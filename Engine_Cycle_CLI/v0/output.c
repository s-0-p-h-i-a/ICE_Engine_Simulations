#include "global.h"
#include "output.h"
#include <stdbool.h>
#include <stdio.h>

void output(struct cylinder currentCylinder, int i) {
	
	printf("\n");
	printf("Current state of cylinder %d: \n", i);
	
	printf("Piston:\n");
	
	if (currentCylinder.piston == TDC) {	
		printf("TDC\n");
	} else {
		printf("BDC\n");
	}
	
	printf("Intake valve:\n");
	
	if (currentCylinder.intakeValve) {	
		printf("OPEN\n");
	} else {
		printf("CLOSED\n");
	}
	
	printf("Exhaust valve:\n");
	
	if (currentCylinder.exhaustValve) {	
		printf("OPEN\n");
	} else {
		printf("CLOSED\n");
	}
	
	printf("Fuel injection:\n");
	
	if (currentCylinder.injectFuel) {	
		printf("ON\n");
	} else {
		printf("OFF\n");
	}
	
	printf("Spark plugs:\n");
	
	if (currentCylinder.spark) {	
		printf("ON\n");
	} else {
		printf("OFF\n");
	}
		
}
