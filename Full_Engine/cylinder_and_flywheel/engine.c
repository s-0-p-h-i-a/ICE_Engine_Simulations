#include "global.h"
#include "engine.h"
#include <stdbool.h>

static const int strokes[TOTAL_CYCLE] 				= { INTAKE, COMPRESSION, COMBUSTION, EXHAUST};
static const bool intakeValveCycle[TOTAL_CYCLE] 	= { true, false, false, false };
static const bool exhaustValveCycle[TOTAL_CYCLE]	= { false, false, false, true };
static const bool fuelInjectionCycle[TOTAL_CYCLE]	= { true, false, false, false };
static const bool sparkPlugCycle[TOTAL_CYCLE]		= { false, false, true, false };
static const bool pistonCycle[TOTAL_CYCLE]			= { BDC, TDC, BDC, TDC };

bool cylinder[CYLINDER_ELEMENTS];

int currentStroke = INTAKE;

bool isIdle = true;
bool engineON = false;
extern int speed = ZERO;

void updateStroke(void) {
	
	if (currentStroke == EXHAUST) { currentStroke = INTAKE;}
	
	for (int i = INTAKE; i < EXHAUST; ++i) {
		
		if (i == currentStroke) {
			currentStroke = strokes[i+1];
		}
	}
}
	
	/*if (currentStroke == INTAKE) { currentStroke = COMPRESSION;}
	else if (currentStroke == COMPRESSION) { currentStroke = COMBUSTION;}
	else if (currentStroke == COMBUSTION) { currentStroke = EXHAUST;}
	else if (currentStroke == EXHAUST) { currentStroke = INTAKE;}*/
	
bool initCylinder(int c) {
	switch (c) {
		case INTAKE_VALVE: 	return intakeValveCycle[INTAKE];
			break;
		case EXHAUST_VALVE: return exhaustValveCycle[INTAKE];
			break;
		case FUEL_INJECTOR: return fuelInjectionCycle[INTAKE];
			break;
		case SPARK_PLUG: 	return sparkPlugCycle[INTAKE];
			break;
		case PISTON: 		return pistonCycle[INTAKE];
			break;
		
		// just to prevent program from breaking?
		default:			return 0;
			break;
	}
}

void startEngine(void) {
	
	for (int i = ZERO; i < CYLINDER_ELEMENTS; ++i) {
		
		cylinder[i] = initCylinder(i);
	}
}

void runEngine(int pause) {
	
	for (int i = ZERO; i < CYLINDER_ELEMENTS; ++i) {
		
		switch(i) {
				case INTAKE_VALVE: 	{
					cylinder[i] = intakeValveCycle[currentStroke];
				}
					break;
				case EXHAUST_VALVE: 	{
					cylinder[i] = exhaustValveCycle[currentStroke];
				}
					break;
				case FUEL_INJECTOR: 	{
					cylinder[i] = fuelInjectionCycle[currentStroke];
				}
					break;
				case SPARK_PLUG: 	{
					cylinder[i] = sparkPlugCycle[currentStroke];
				}
					break;
				case PISTON: 		{
					cylinder[i] = pistonCycle[currentStroke];
				}
					break;
				
				// just to prevent program from breaking?
				default: ;
					break;
		}
	}
}
