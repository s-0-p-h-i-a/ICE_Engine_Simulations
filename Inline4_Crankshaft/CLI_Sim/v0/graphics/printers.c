#include "../global.h"
#include "graphicslib.h"
#include <stdbool.h>
#include <stdio.h>

void printSpacers(void) {
	
	printf("|        |        |        |        |\n");
	printf("|        |        |        |        |\n");
}

void printLobesTDC(bool pos) {
	
	if (pos) {
		printf("--------");
	} else {
		printf("        ");
	}
	
	printf("|");
}

void printLobesBDC(bool pos) {
	
	if (pos) {
		printf("        ");
	} else {
		printf("--------");
	}
	
	printf("|");
}

void clearTerminal(void) {
	printf("\033[2J\033[H");
}
