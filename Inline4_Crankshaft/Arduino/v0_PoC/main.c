/*# Inline-4 Crankshaft Simulation 30/11

Simulate a 4 lobe crankshaft moving through the combustion cycle using LEDs on a breadboard.

## Setup:

8 LEDs arranged in two rows.
Diagram for 1342 firing order:

| ------ |        |        | ------- |
|        |        |        |         |
|        | ------ | ------ |         |

NOTES:
- Again encountering limitations due to avoiding using pointers for more complex projects for now, specifically for initCrank,setPins, and was not able to implement an update function to set values for next loop

- Leaving this logic as is for now, for loops with lobe enum are 'readable' enough
*/

#include "global.h"
#include "initCrank.h"
#include "setPins.h"
#include "spinCrank.h"
#include <stdbool.h>

void crank_init (void) {
	
	for (enum lobes i = lobe1; i <= lobe4; ++i) {
		crankshaft[i] = initCrank(i);
	}
}

void crank_run (void) {
	
	// Choose LED pins for display: create this loop's pin map
	int pinMap[TOTAL_LOBES];
	
	for (enum lobes i = lobe1; i <= lobe4; ++i) {
		
			pinMap[i] = setPins(i);
	}
	
	// Light up chosen LEDs
	spinCrank(pinMap);
	
	// Update lobe position for next loop
	for (enum lobes i = lobe1; i <= lobe4; ++i) {	
		crankshaft[i] = !crankshaft[i];
	}
}
	
	
