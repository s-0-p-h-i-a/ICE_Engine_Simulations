#include "../global.h"
#include <stdbool.h>
#include <stdio.h>

#ifndef GRAPHICSLIB_H
#define GRAPHICSLIB_H

// Main visual crank spinner
void spinCrankVisual(void);

// Helper funcs
void printSpacers(void);
void printLobesTDC(bool pos);
void printLobesBDC(bool pos);

// Clear terminal to print new crank, defined in printers.c
void clearTerminal(void);

#endif
