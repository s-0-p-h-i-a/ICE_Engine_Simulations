# Arduino Single-Cylinder Engine Simulation (WIP / PoC)

30/11/25
## Overview

This project is a learning-focused prototype simulating a single cylinder moving through a 4-stroke engine cycle using LEDs on a breadboard. It practices:

- Embedded C programming and multi-file organization

- State-machine logic for engine cycles

- Mapping logical cylinder state to hardware outputs (LEDs)

- Conceptual visualization of piston, valve, fuel injector and spark plug behavior

**Note:** This project is a proof-of-concept and is not intended as a real-time or production engine simulation.

The code now implements a **pointer-free, cycle-driven boolean array model** for the cylinder elements, allowing the engine to “run” continuously in the Arduino loop without passing values between functions.

---
## Hardware Setup

Total LEDs: 8 (arranged in 4 conceptual rows)

- **Top row:**
    - Blue LED → intake valve
    - Green LED → exhaust valve

- **Second row:**
    - Yellow LED → fuel injection
    - Red LED → spark plug

- **Third row:**
    - 2 White LEDs → TDC (top dead center)

- **Fourth row (with gap below third row):**
    - 2 White LEDs → BDC (bottom dead center)

This arrangement visually represents the cylinder’s four-stroke cycle on a breadboard.

---
## Code Structure

- **Cylinder representation:**  
    Instead of a struct, a **boolean array representing the cylinder** is currently used to track intake valve, exhaust valve, fuel injector, spark plug, and piston position. This allows looping through cylinder elements easily without pointers, while maintaining clear state representation.
    
- **Cycle maps:**
```
extern const bool intakeValveCycle[4];
extern const bool exhaustValveCycle[4];
extern const bool fuelInjectionCycle[4];
extern const bool sparkPlugCycle[4];
extern const bool pistonCycle[4];
```

These maps define which elements are active at each stroke.

- **Functions:**

    - `initCylinder(cylinderElements c)` → initializes element states at the start of the cycle

    - `runEngine(strokes now)` → updates all LEDs according to the current stroke

    - `pistonWrite(bool pistonUP)` → handles TDC/BDC LED outputs

The **Arduino loop** now cycles through strokes continuously, updating LED outputs automatically:

```
void loop () {
	runEngine(currentStroke);
	++currentStroke;
	}
```
---
## Behaviour

Each iteration of the loop:

1. Reads the cylinder elements’ current state from the cycle maps

2. Updates the LEDs for valves, fuel injection, spark, and piston position

3. Advances to the next stroke

This produces a simple, continuous visualization of a single cylinder’s 4-stroke cycle.

---
## Learning Goals / Roadmap

- **Current focus:**

    - Develop a functional, pointer-free, loop-driven cycle model

    - Map logical state to hardware outputs clearly

    - Understand the relationship between FSMs, cylinder state, and outputs

- **Future plans:**
    
    - Implement realistic timing delays for visualization

    - Expand to multiple cylinders using an LED matrix

    - Explore valve overlap, fuel injection, and spark logic

    - Transition to more structured data representations (e.g., structs) as complexity grows

---
## Notes

- This project remains a **work-in-progress / proof-of-concept**, structured for learning rather than production.

- It is part of the **larger engine-simulations repository**, showing progression from CLI-based simulations to visual hardware prototypes.