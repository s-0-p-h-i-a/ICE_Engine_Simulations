#include "global.h"
#include <stdbool.h>

const int TOTAL_CYCLE = 4;
const int INTERVAL = 10;

const POSITION pistonCycle[TOTAL_CYCLE] 	= { BDC, TDC, BDC, TDC};
const bool intakeValveCycle[TOTAL_CYCLE] 	= { true, false, false, false};
const bool exhaustValveCycle[TOTAL_CYCLE] 	= { false, false, false, true};
const bool fuelInjectionCycle[TOTAL_CYCLE] 	= { true, false, false, false};
const bool sparkPlugCycle[TOTAL_CYCLE] 		= { false, false, true, false};
