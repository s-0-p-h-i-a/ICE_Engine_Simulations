#include <stdbool.h>

#ifndef GLOBAL_H
#define GLOBAL_H

enum cycle {
	INTAKE = 0,
	COMPRESSION = 1,
	COMBUSTION = 2,
	EXHAUST = 3
};

enum lobes {
	lobe1 = 0,
	lobe2 = 1,
	lobe3 = 2,
	lobe4 = 3
};
	
enum rows {
	top = 0,
	bottom = 1
};

typedef int lobeMap[4];

// PIN nr list so they can easily be changed	
extern const int lobe1TDC;
extern const int lobe1BDC;
extern const int lobe2TDC;
extern const int lobe2BDC;
extern const int lobe3TDC;
extern const int lobe3BDC;
extern const int lobe4TDC;
extern const int lobe4BDC;

// Consts for the arrays
extern const int TOTAL_LOBES;
extern const int TOTAL_ROWS;
extern const int TOP_PIN;
extern const int BOTTOM_PIN;

// For LED control
extern const bool TDC;
extern const bool BDC;

// Arrays
extern const int lobe1Pins[2];
extern const int lobe2Pins[2];
extern const int lobe3Pins[2];
extern const int lobe4Pins[2];
extern const int lobePins[2][4];

// Crankshaft: needs to be trackable across loops and available to functions
extern bool crankshaft[4];

// Initialisation map for crank lobe positions
extern const bool initMap[4];

#endif
