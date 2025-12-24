/*
 
 arduino-cli compile --fqbn arduino:avr:uno Rebuild.ino
 
 arduino-cli upload -p /dev/cu.usbmodem141011 --fqbn arduino:avr:uno .


08/12 FIRST DRAFT REWORK

MAIN CHANGES

- Converting enums to static const int to keep them contained and avoid enum confusion

- Increasing overall "containment" of variables, functions, function calls

- Swapping some variables for getVariable function calls where appropriate (= values needed as intermediary or to be checked punctually, they do not need to exist between loops)

- Using local intermediary variables

- Clearer conceptual separation: cylinder and flywheel are now separate parts of a composite engine multi state machine

- Component states are now static local variables: the state of the cylinder (which stroke it is on) depends on the state of the engine, but the engine does not need to know the state of the cylinder to assess its own state (defined only by latched button input)

- Cylinder display now uses millis() call instead of global int now to control on/off timing: the blinking timing is its own independent state separate from the rest of the system

- Joystick debounce now also uses a millis() variable for its debounce tracking

- Now only cylinder display, joystick and drive modules need the current time. They now all use their town millis() calls for independent time tracking

- Most global enums changed for local static const int or #defines

20/12

Cylinder state and LED display not working

State check + fix:
- Adding stroke cycle display to serial plotter to diagnose cylinder LED display and cycling issues
- Found issue with state change: cylinder state alternates oscillating between all states and moving to next stroke
- Cylinder stroke logic seems tied to when/where/how updateCylinderState is called
- Found issue: switchNow got stuck on true and would periodically cause the cylinder state to jump back and forth when the if branch was entered

LED display check:
- Previous cylinder states matrix was storing junk int values instead of 0 or 1 due to array-pointer situation in C
- Now using uint and #defines for the element states arrays that make up the cylinder states matrix
- Previous issue with exhaust valve led display happening at the wrong time fixed via tighter cylinder update function calls + syncing stroke change with display on/off
- Previous issue with led display messing up at the higher speed setting now gone, probably due to better state change management and timing

STROKE PROGRESSION + CYLINDER DISPLAY MODULE + JOYSTICK ON/IDLE/OFF AND SPEED REGULATION NOW FULLY VALIDATED

Next steps: integrate servo, then rpm calculation

Flywheel + servo integration:

- The exhaust pin is now floating: servo was attached to its pin by mistake
- Servo reacts to on/off command, but for some reason just wiggles around the same angle: angle control issue, search inside flywheel lib
- Was actually in servo lib, moveservo function calling spinflywheel twice
- Moved edge angle handling to inside spinflywheel function instead of moveservo: the angle is a state characteristic of the flywheel which is the actuator of the servo. The servo just responds to flywheel movement, it should not be changing its state
- Servo now moves to approx 90° then gets stuck and jitters when engine on/off is toggled
- Unlikely to be in servo lib as it does not change angle or direction -> look inside flywheel lib, or maybe it's in drive?
- Idea: moving state update inside cylinder visuals display helped, try the same for servo movement
- Found redundant lastAngle = flywheelAngle in spinflywheel, handleedgeangles already takes care of that
- Found an issue: speed was declared as unsigned
- Tightened speed + - toggle logic: explicitly takes into account trajectory now (speed < or > 0 condition)
- Split angle/speed management concerns into 2 functions: handleedgecases and checkspeedtoggle, now both called in spinflywheel
- Done for today, current servo behaviour: it goes to 180 but does not sweep back

22/12
FLYWHEEL LOGIC REWORK:
GOAL:
- Isolate flywheel movement logic and print current angle on terminal to test it independently from servo movement
- First in fixed speed/rpm loop, then with user input for idle rpm or speed 1 or 2
- Next step: integrate it back into arduino sketch and connect it to joystick module for on/off and speed control

SIDE QUEST:
- Refactor present code for 'drive' logic to control the flywheel object via spinflywheel, and the servo will be controlled by spinflywheel
- Change dependencies: currently servolib includes flywheellib, this needs to be reversed
- Reformulated idleCheck logic:
Now:		 	isIdle = engineON && (x < IDLE_INPUT + hyst) && (x > IDLE_INPUT - hyst);
Previously: 	isIdle = engineON && (x < IDLE_INPUT + hyst || x > IDLE_INPUT - hyst);
- Removed isIdle check inside getSpeed function in drive: drive() already runs it
- getSpeedInput previously called in getServoSpeed (now getFlywheelSpeed), now moved to drive() as it is relevant for both the flywheel and the cylinder
- Changed logic inside spinFlywheel:
Now:

	flywheelSpeed = speed;
	flywheelAngle += flywheelSpeed;
	handleEdgeValues();
	checkDirectionToggle();
	moveServo(flywheelAngle);
	
Previously:

	no flywheelSpeed assignment
	flywheelAngle += flywheelSpeed; at the end
- Full engine state check in checkEngineState: engineOn, isIdle and getSpeedInput inside it. Called inside drive()
- Cylinder and flywheel control now directly via spinFlywheel(getFlywheelSpeed()); displayCylinder(getCylinderPause());

- Found issue: flywheelAngle gets stuck at 180, speed toggles but angle isn't decremented
- Terminal output matches servo behaviour, won't sweep back
- Terminal output:

		  Current angle: 178 
		 Current speed: 2 
		  Current angle: 180 
		 Current speed: -2 
		  Current angle: 180 
		 Current speed: -2 
- Likely cause: order of the instructions inside spinFlywheel
- Currently:

		flywheelSpeed = speed;
		flywheelAngle += flywheelSpeed;
	
		handleEdgeValues();
		checkDirectionToggle();
		
- This code:

		flywheelSpeed = flywheelSpeed ? speed : -speed;
		-> ISSUE HERE: flywheelSpeed true for any non zero value?
	
		handleEdgeValues();
		checkDirectionToggle();
		flywheelAngle += flywheelSpeed;
		
- Prints: 
		 Current angle: 178 
		 Current speed: 2 
		  Current angle: 180 
		 Current speed: 2 
		  Current angle: 178 
		 Current speed: -2 
		  Current angle: 180 
		 Current speed: 2 
		  Current angle: 178 
		 Current speed: -2 

- Difficulty: finding a logic that works both on the very first run and across loops
- Sticking point: initial (first loop) assignment of flywheelSpeed
	-> initialised speed at 0 causes issues with control branches
- Sweep back logic fixed for when angle hits 180, now gets stuck at -2 and -2 after sweeping back
- Added sweepBack check in check...Toggle so it gets updated there too
- Issue solved! flywheelSpeed assignment in main spinflywheel, after sweepback check, separated from sweep back concern
- The issue with this module was in flywheellib, specifically the sweep back logic which spilled over into the incrementation/decrementation. Angle being previously unsigned caused issues when/if it went below 0.
- Main problem was basically wonky/uncoordinated angle+speed updating with unclear separation of concerns and unclear state management, all causing the logic to break down when hitting the edge angles.
- Considered trying more verbose solutions as intermediary, but preferred to look for concise solution
	-> this forced me to redefine logic in a more centralised/synchronised way
	- reduced 'function multitasking':
		eg checkDirectionToggle previously also handled the speed toggling
		-now it is part of the decision process to trigger toggling or not)
	- cleaner separation of concerns/dependency structure
	- more holistic definition of states, where states live, how they are influenced

NOTES:
RE: FLYWHEEL AND SERVO REINTEGRATION

- The servo module just checks if the servo response delta (using 15ms here) has elapsed and does servo.write (or not) with the angle the flywheel lib fed it
- That delta check is just in the servo module, the angle incrementation evolves separately inside the flywheel module
- Servo step timing and flywheel angle incrementation are two separate things with their own timelines, the goal is that they sync up everytime spinflywheel calls moveservo and the servo response delta has elapsed
- In theory if i were to move the joystick back and forth before the servo delta, that variation would go nowhere
- But the joystick reading function has a debounce anyway so in practice:
	-> speed level is only updated once in every debounce period (100ms)
	- there is no continuous value reading and actuating, only a speed status update every 100ms that will be picked up after the current servo delta is elapsed
- The flywheel speed input and servo actuation are both discreetly periodic
- Their relation gets reset/rechecked every time the servo is in 'can respond to input' (= delta has elapsed) mode
- Speed input reading between joystick debounce periods simply goes nowhere as from a human user/observer perspective the 100ms debounce time is negligible proportionally to the system and its purpose as a basic simulation
- Mental model:
	-> two parallel lines with different step lengths
	- the flywheel line with the speed input is sort of continuously (with changes possibly happening every 100ms) talking to the servo timeline, which in turn only 'listens' every 15ms.

23/12
- Changed separate if branches to if-else for the speed and pause assignment in drive


 */

#include "joystick.h"
#include "drive.h"
#include "cylinderVisuals.h"
#include "servolib.h"
#include "rpmlib.h"
#include "plotter.h"

void setup() {

	Serial.begin(9600);
	
	pinMode(JOYSTICK_Z,INPUT);
	
	serv0.attach(SERVO_PIN);
	
	startEngineVisuals();
}

void loop() {
	
	driveEngine();
	plotterDisplay();
	getRPM();
}
