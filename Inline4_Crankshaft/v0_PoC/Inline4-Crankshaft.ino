#include "global.h"
#include "initCrank.h"
#include "setPins.h"
#include "spinCrank.h"
#include "main.c"
#include <stdbool.h>

void setup () {
	
	crank_init();
}

void loop() {
	crank_run();
}
