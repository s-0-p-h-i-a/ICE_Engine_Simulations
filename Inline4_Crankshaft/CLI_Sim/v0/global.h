#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

typedef enum {
	lobe1 = 0,
	lobe2 = 1,
	lobe3 = 2,
	lobe4 = 3
} lobes;

// Consts for the arrays
extern const int TOTAL_LOBES;
extern const bool TDC;
extern const bool BDC;

// Time interval for while loop
extern const int INTERVAL;

// Initialisation map for crank lobe positions
extern const bool initMap[4];

// Crankshaft: needs to be trackable across loops and available to functions
extern bool crankshaft[4];

#endif
