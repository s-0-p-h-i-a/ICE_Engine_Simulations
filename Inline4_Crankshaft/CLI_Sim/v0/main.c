/*# Inline-4 Crankshaft CLI Simulation 01/12

Simulate a 4 lobe crankshaft moving through the combustion cycle via CLI ASCII visuals.
1-3-4-2 firing order.

## SETUP:

Four rows of terminal output:

Setting 1:

|--------|        |        |--------|
|        |        |        |        |
|        |        |        |        |
|        |--------|--------|        |

Setting 2:

|        |--------|--------|        |
|        |        |        |        |
|        |        |        |        |
|--------|        |        |--------|

## STRUCTURE:
- Separate crank object state machine (cranklib.h) and visual interface (graphics.h)

## PROCESS:
- Take arduino crank source code as base, to be separated into main and cranklib
- Start implementing new program in main
- Build cranklib and graphics lib progressively

## LIBRARIES:

### GRAPHICSLIB:
- main spinCrankVisual function with helpers printSpacers, printTDC and printBDC
- clearTerminal to reset Terminal

### CRANKLIB:
- Same initCrank as in the arduino version: this function is to initialise the main crankshaft state machine/object
- spinCrank "spins" the crankshaft by toggling the lobe's state

## NOTES:
- First time making and using custom libraries, progression felt like a logical next step after multi-file structure, folders separation feels easier to work on and maintain
- Use of cranklib and graphicslib accompanied/supported the choice to make a clearer distinction between internal "crankshaft" state machine and supporting graphics/output logic

Link:

gcc main.o cranklib/initCrank.o cranklib/spinCrank.o graphics/printers.o graphics/spinCrankVisual.o checkContinue.o global.o -o cli_crank

Build:

gcc -c main.c
gcc -c global.c
gcc -c checkContinue.c
gcc -c cranklib/initCrank.c
gcc -c cranklib/spinCrank.c
gcc -c graphics/printers.c
gcc -c graphics/spinCrankVisual.c
gcc main.o cranklib/initCrank.o cranklib/spinCrank.o graphics/printers.o graphics/spinCrankVisual.o checkContinue.o global.o -o cli_crank



*/

#include "./cranklib/cranklib.h"
#include "./graphics/graphicslib.h"
#include "global.h"
#include "checkContinue.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	
	// Start engine
	for (lobes i = lobe1; i <= lobe4; ++i) {
		crankshaft[i] = initCrank(i);
	}
	
	// Run the engine
	bool continueRunning = checkContinue();
	
	// To pause every INTERVAL = 8 loops and extra infinite loop prevention
	int track = 0;
	
	// Main loop
	while (continueRunning && track <= INTERVAL) {
		
		clearTerminal();
		
		spinCrankVisual();
		
		++track;
		
		// Continue check
		if (track == INTERVAL) {
			continueRunning = checkContinue();
			track = 0;
		}
		
		// Update crankshaft state(=lobe positions) for next loop
		for (lobes lobe = lobe1; lobe <= lobe4; ++lobe) {	
			crankshaft[lobe] = spinCrank(lobe);
		}
		
		usleep(500000); // 200ms pause
	}
	
	return 0;
}
