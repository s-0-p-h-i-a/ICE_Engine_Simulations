#include "global.h"
#include "spinCrank.h"
#include <stdbool.h>

void spinCrank(int valuesMap[TOTAL_LOBES]) {
	
	for (enum lobes k = lobe1; k <= lobe4; ++k) {
		digitalWrite(valuesMap[k], HIGH);
	}	
}
