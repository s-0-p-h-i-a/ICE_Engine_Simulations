#include "global.h"
#include "setPins.h"
#include <stdbool.h>

int setPins(enum lobes j) {
	
	bool lobeUP = crankshaft[j] == TDC;
	int value = (lobeUP) ? lobePins[TOP_PIN][j] : lobePins[BOTTOM_PIN][j];
	return value;
}
