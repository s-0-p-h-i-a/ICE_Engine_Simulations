#include "../global.h"
#include "graphicslib.h"
#include <stdbool.h>
#include <stdio.h>

void spinCrankVisual(void) {
	
	printf("\n");
	printf("|");
	for (lobes lobeTDC = lobe1; lobeTDC <= lobe4; ++lobeTDC) {			
				printLobesTDC(crankshaft[lobeTDC]);
				if (lobeTDC == lobe4) {
					printf("\n");
				}
		}
	printSpacers();
	
	printf("|");
	for (lobes lobeBDC = lobe1; lobeBDC <= lobe4; ++lobeBDC) {			
				printLobesBDC(crankshaft[lobeBDC]);
				if (lobeBDC == lobe4) {
					printf("\n");
				}
		}
	printf("\n");
}
