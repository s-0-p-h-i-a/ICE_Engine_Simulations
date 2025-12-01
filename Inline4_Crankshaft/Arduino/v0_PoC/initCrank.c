#include "global.h"
#include "initCrank.h"
#include <stdbool.h>

bool initCrank(enum lobes k) {
	bool lobeUP = initMap[k];
	return lobeUP;
}
