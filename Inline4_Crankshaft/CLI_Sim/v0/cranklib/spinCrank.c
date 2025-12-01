#include "../global.h"
#include "cranklib.h"
#include <stdbool.h>

bool spinCrank(lobes i) {
	
	bool lobeStatus = !crankshaft[i];
	
	return lobeStatus;
		
}
