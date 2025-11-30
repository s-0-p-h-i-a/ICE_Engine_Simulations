#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

typedef enum {
	INTAKE 		= 0,
	COMPRESSION = 1,
	COMBUSTION 	= 2,
	EXHAUST 	= 3,
} STROKES;

typedef enum {
	TDC = 1,
	BDC = 2
} POSITION;

struct cylinder {
	 POSITION piston;
	 bool intakeValve;
	 bool exhaustValve;
	 bool injectFuel;
	 bool spark;};
	 
struct engine {
	struct cylinder cylinder1;
	struct cylinder cylinder2;
	struct cylinder cylinder3;
	struct cylinder cylinder4;	
};

extern const int TOTAL_CYCLE;
extern const int INTERVAL;

extern const POSITION pistonCycle[4];
extern const bool intakeValveCycle[4];
extern const bool exhaustValveCycle[4];
extern const bool fuelInjectionCycle[4];
extern const bool sparkPlugCycle[4];

#endif
