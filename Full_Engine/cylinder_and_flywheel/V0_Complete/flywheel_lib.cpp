#include "flywheel_lib.h"
#include "servolib.h"
#include <stdint.h>

#define ZERO 0

enum {
	ANGLE_ZERO = 0,
	ANGLE_180 = 180
};

static uint8_t sweepBack = 0;

int flywheelAngle = ZERO;
int flywheelSpeed = ZERO;

void handleEdgeValues(void) {
	
	// prevent angle from going beyond 0-180
	if (flywheelAngle < ANGLE_ZERO) { 
		flywheelAngle = ANGLE_ZERO;
		sweepBack = 1; }
			
	if (flywheelAngle > ANGLE_180) {
		flywheelAngle = ANGLE_180;
		sweepBack = 1; }	
}

uint8_t checkDirectionToggle(void) {
	
	uint8_t toggleSpeedZero = (flywheelAngle == ANGLE_ZERO) && (flywheelSpeed < ZERO);
	uint8_t toggleSpeed180  = (flywheelAngle == ANGLE_180)  && (flywheelSpeed > ZERO);
			
	uint8_t toggleNow = toggleSpeedZero || toggleSpeed180;
	sweepBack = toggleNow;
	
	return toggleNow;
}

void spinFlywheel(int speed) {
	
	handleEdgeValues();
	
	checkDirectionToggle();
	
	if (sweepBack) { flywheelSpeed = -flywheelSpeed; }
	
	flywheelSpeed = (flywheelSpeed >= ZERO) ? speed : -speed;
	
	flywheelAngle += flywheelSpeed;
	
	moveServo(flywheelAngle);
}


/**void initFlywheel(void) {
	
	flywheelAngle = ANGLE_ZERO;
}

void handleEdgeValues(void) {
	
	// prevent angle from going beyond 0-180
	if (flywheelAngle < ANGLE_ZERO) { 
		flywheelAngle = ANGLE_ZERO; }
			
	if (flywheelAngle > ANGLE_180) {
		flywheelAngle = ANGLE_180; }	
}

void checkSpeedToggle(void) {
			
	uint8_t toggleSpeed = (flywheelAngle == ANGLE_ZERO) && (flywheelSpeed < 0)
						|| (flywheelAngle == ANGLE_180) && (flywheelSpeed > 0);
		
	// sweep back		
	if (toggleSpeed) {
		flywheelSpeed = -flywheelSpeed;	
	}
}

void spinFlywheel(void) {
	
	handleEdgeValues();
	checkSpeedToggle();
	flywheelAngle += flywheelSpeed;
}**/
