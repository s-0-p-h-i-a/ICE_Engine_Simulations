/*
 * COMBUSTION ENGINE CYCLE SIMULATION
 29/11
 
 IDEA:
 - Simulate 4-stroke cycle via a simple Moore state machine using structs/enums/arrays
 
 CYCLE:
 
 INTAKE 	 = Z0
 COMPRESSION = Z1
 COMBUSTION  = Z2
 EXHAUST	 = Z3
 
 enum stroke = {INTAKE = 1,...}
 
 enum piston = {TDC, BDC}
 
 struct cylinder = {piston, bool intake_valve, bool exhaust_valve, bool fuel, bool spark}
 
 INTAKE - Z0
 
 piston = BDC
 intake = true
 exhaust = false
 fuel = true
 spark = false
 
 COMPRESSION - Z1
 
 piston = TDC
 intake = false
 exhaust = false
 fuel = false
 spark = false
 
 COMBUSTION - Z2
 
 piston = BDC
 intake = false
 exhaust = false
 fuel = false
 spark = true
 
 EXHAUST - Z3
 
 piston = TDC
 intake = false
 exhaust = true
 fuel = false
 spark = false
 
 
 IDEA:
 - 5 global const arrays [4] with the states of each element at each stroke
 
 - 4 cylinder structs each cycling through each stroke
 
 */
 
#include "global.h"
#include "checkContinue.h"
#include "output.h"
#include <stdbool.h>

int main() {
	
	struct engine inline_4;
	int timestamp = 0;
	STROKES cylinder1Step = INTAKE;
	STROKES cylinder3Step = EXHAUST;
	STROKES cylinder4Step = COMBUSTION;
	STROKES cylinder2Step = COMPRESSION;
	
	// INIT ENGINE
	inline_4.cylinder1.piston 		= pistonCycle[cylinder1Step];
	inline_4.cylinder1.intakeValve 	= intakeValveCycle[cylinder1Step];
	inline_4.cylinder1.exhaustValve = exhaustValveCycle[cylinder1Step];
	inline_4.cylinder1.injectFuel 	= fuelInjectionCycle[cylinder1Step];
	inline_4.cylinder1.spark 		= sparkPlugCycle[cylinder1Step];
	
	inline_4.cylinder3.piston 		= pistonCycle[cylinder3Step];
	inline_4.cylinder3.intakeValve 	= intakeValveCycle[cylinder3Step];
	inline_4.cylinder3.exhaustValve = exhaustValveCycle[cylinder3Step];
	inline_4.cylinder3.injectFuel 	= fuelInjectionCycle[cylinder3Step];
	inline_4.cylinder3.spark 		= sparkPlugCycle[cylinder3Step];
	
	inline_4.cylinder4.piston 		= pistonCycle[cylinder4Step];
	inline_4.cylinder4.intakeValve 	= intakeValveCycle[cylinder4Step];
	inline_4.cylinder4.exhaustValve = exhaustValveCycle[cylinder4Step];
	inline_4.cylinder4.injectFuel 	= fuelInjectionCycle[cylinder4Step];
	inline_4.cylinder4.spark 		= sparkPlugCycle[cylinder4Step];
	
	inline_4.cylinder2.piston 		= pistonCycle[cylinder2Step];
	inline_4.cylinder2.intakeValve 	= intakeValveCycle[cylinder2Step];
	inline_4.cylinder2.exhaustValve = exhaustValveCycle[cylinder2Step];
	inline_4.cylinder2.injectFuel 	= fuelInjectionCycle[cylinder2Step];
	inline_4.cylinder2.spark 		= sparkPlugCycle[cylinder2Step];
	
	++timestamp;
	
	bool continueCycle = checkContinue();
	
	while (continueCycle) {
		
		// EDGE CASE CHECK
		if 		(cylinder1Step == EXHAUST) {
			cylinder1Step = INTAKE;
			++cylinder3Step;
			++cylinder4Step;
			++cylinder2Step;
		}
		else if (cylinder3Step == EXHAUST) {
			cylinder3Step = INTAKE;
			++cylinder4Step;
			++cylinder2Step;
			++cylinder1Step;
		}
		else if (cylinder4Step == EXHAUST) {
			cylinder4Step = INTAKE;
			++cylinder2Step;
			++cylinder1Step;
			++cylinder3Step;
		}
		else if (cylinder2Step == EXHAUST) {
			cylinder2Step = INTAKE;
			++cylinder1Step;
			++cylinder3Step;
			++cylinder4Step;
		}
		
		// RUN ENGINE
		inline_4.cylinder1.piston 		= pistonCycle[cylinder1Step];
		inline_4.cylinder1.intakeValve 	= intakeValveCycle[cylinder1Step];
		inline_4.cylinder1.exhaustValve = exhaustValveCycle[cylinder1Step];
		inline_4.cylinder1.injectFuel 	= fuelInjectionCycle[cylinder1Step];
		inline_4.cylinder1.spark 		= sparkPlugCycle[cylinder1Step];
		
		inline_4.cylinder3.piston 		= pistonCycle[cylinder3Step];
		inline_4.cylinder3.intakeValve 	= intakeValveCycle[cylinder3Step];
		inline_4.cylinder3.exhaustValve = exhaustValveCycle[cylinder3Step];
		inline_4.cylinder3.injectFuel 	= fuelInjectionCycle[cylinder3Step];
		inline_4.cylinder3.spark 		= sparkPlugCycle[cylinder3Step];
		
		inline_4.cylinder4.piston 		= pistonCycle[cylinder4Step];
		inline_4.cylinder4.intakeValve 	= intakeValveCycle[cylinder4Step];
		inline_4.cylinder4.exhaustValve = exhaustValveCycle[cylinder4Step];
		inline_4.cylinder4.injectFuel 	= fuelInjectionCycle[cylinder4Step];
		inline_4.cylinder4.spark 		= sparkPlugCycle[cylinder4Step];
		
		inline_4.cylinder2.piston 		= pistonCycle[cylinder2Step];
		inline_4.cylinder2.intakeValve 	= intakeValveCycle[cylinder2Step];
		inline_4.cylinder2.exhaustValve = exhaustValveCycle[cylinder2Step];
		inline_4.cylinder2.injectFuel 	= fuelInjectionCycle[cylinder2Step];
		inline_4.cylinder2.spark 		= sparkPlugCycle[cylinder2Step];
		
		// PRINT VALUES
		output(inline_4.cylinder1, 1);
		output(inline_4.cylinder2, 2);
		output(inline_4.cylinder3, 3);
		output(inline_4.cylinder4, 4);
		
		// CHECK WHETHER TO CONTINUE EVERY 10 CYCLES
		if (timestamp % INTERVAL == 0) {
			continueCycle = checkContinue();
			}
			
		++timestamp;	
	}
	
	return 0;
}
 
