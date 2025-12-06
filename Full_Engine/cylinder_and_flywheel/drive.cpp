#include "global.h"
#include "joystick.h"
#include "engine.h"
#include "drive.h"
#include <arduino.h>

int speedPause = IDLE_PAUSE;
static long unsigned int lastEngineCycle = ZERO;

void wait(int p) {
	while (millis() < now + p) {;}
}

void checkEngineState(void) {
	
	// Idle check
	bool idleX = x >= IDLE_INPUT - hyst && x <= IDLE_INPUT + hyst;
	
	if (idleX) {
		if (now - lastUpdate_X > IDLE_WAIT) {
			
			isIdle = true;
		}
	} else { isIdle = false;}
	
	// ON/OFF toggle
	if (z && now - lastUpdate_Z > WAIT_PAUSE) {
		lastEngineCycle = now;
		engineON 		= !engineON;
	}
	
	// LED + servo control updates
	if (x && now - lastUpdate_X > WAIT_PAUSE) {
		lastUpdate_X = now;
		speed = getSpeed();
		speedPause = getCylinderPause();
	}
}

int getSpeed(void) {
	
	int newSpeed = ZERO;
	
	if (isIdle) 											{ speed = ZERO;}
	
	if (x > IDLE_INPUT + hyst && x < LEVEL_ONE_INPUT - hyst){ speed = SPEED_ONE;}
	
	if (x > LEVEL_ONE_INPUT && x < LEVEL_TWO_INPUT - hyst) 	{ speed = SPEED_TWO;}
	
	if (x > LEVEL_TWO_INPUT && x < LEVEL_THREE_INPUT - hyst){ speed = SPEED_THREE;}
	
	return newSpeed;
}

int getCylinderPause(void) {
	
	int newPause = IDLE_PAUSE;
	
	if (isIdle) 											{ speedPause = IDLE_PAUSE;}
	
	if (x > IDLE_INPUT + hyst && x < LEVEL_ONE_INPUT - hyst){ speedPause = SPEED_ONE_PAUSE;}
	
	if (x > LEVEL_ONE_INPUT && x < LEVEL_TWO_INPUT - hyst) 	{ speedPause = SPEED_TWO_PAUSE;}
	
	if (x > LEVEL_TWO_INPUT && x < LEVEL_THREE_INPUT - hyst){ speedPause = SPEED_THREE_PAUSE;}
	
	return newPause;
}

void driveEngine(int pause) {
	
	runEngine(speedPause);
	
	wait(pause);
}
	
