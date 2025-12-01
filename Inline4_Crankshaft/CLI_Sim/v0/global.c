#include "global.h"
#include <stdbool.h>

const int TOTAL_LOBES 	= 4;
const bool TDC = true;
const bool BDC = false;

const bool initMap[TOTAL_LOBES] = { BDC, TDC, TDC, BDC };

bool crankshaft[TOTAL_LOBES];

const int INTERVAL = 8;
