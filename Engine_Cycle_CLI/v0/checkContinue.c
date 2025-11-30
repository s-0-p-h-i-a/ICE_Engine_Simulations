#include "global.h"
#include "checkContinue.h"
#include <stdio.h>

bool checkContinue() {
	
	int input = 0;
	char inputBuf[4];
		
	printf("\n");
	printf("Start/Continue? 0 = NO, 1 = YES \n");
			
	// Keep reading input until the user enters a valid int
	while (fgets(inputBuf, sizeof(inputBuf), stdin)) {
	// Try to read an integer from the input string
		bool inputValid = sscanf(inputBuf, "%d", &input) && (input == 0 || input == 1);
		if (inputValid) {
		  break;
		} else {
		 printf("Invalid input. Must be 0 or 1. Try again: ");
		}
	}
	
	bool result = input;
	
	return result;
}
