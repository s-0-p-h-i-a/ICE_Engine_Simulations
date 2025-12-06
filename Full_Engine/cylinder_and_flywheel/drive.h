#ifndef DRIVE_H
#define DRIVE_H

enum {
	
	hyst		= 30,
	IDLE_INPUT	= 500,
	LEVEL_ONE_INPUT 	= 670,
	LEVEL_TWO_INPUT 	= 840,
	LEVEL_THREE_INPUT	= 1000
};

enum {

	SPEED_THREE_PAUSE = 250,	// 60RPM x 100	
	SPEED_TWO_PAUSE = 500,	// 30RPM x 100
	SPEED_ONE_PAUSE = 1500, // 1RPM x 100
	IDLE_PAUSE 	= 2000,
};

enum {
	SPEED_ONE 	= 4,
	SPEED_TWO	= 8,
	SPEED_THREE = 12
};

enum { 
	WAIT_PAUSE = 1000,
	IDLE_WAIT  = 3000
	};

extern int speedPause;

void wait(int p);

void checkEngineState(void);
int getSpeed(void);
int getCylinderPause(void);

#endif
