#include "global.h"
#include <stdbool.h>

// Pin numbers for each LED, random numbers for now just for compile checks
const int lobe1TDC = 1;
const int lobe1BDC = 2;
const int lobe2TDC = 3;
const int lobe2BDC = 4;
const int lobe3TDC = 5;
const int lobe3BDC = 6;
const int lobe4TDC = 7;
const int lobe4BDC = 8;
	
const int TOTAL_LOBES 	= 4;
const int TOTAL_ROWS 	= 2;
const int TOP_PIN 		= 0;
const int BOTTOM_PIN 	= 1;
const bool TDC = true;
const bool BDC = false;

const int lobePins[TOTAL_ROWS][TOTAL_LOBES] = { { lobe1TDC, lobe2TDC, lobe3TDC, lobe4TDC}, { lobe1BDC, lobe2BDC, lobe3BDC, lobe4BDC} };

bool crankshaft[TOTAL_LOBES];

const bool initMap[TOTAL_LOBES] = { BDC, TDC, TDC, BDC };

