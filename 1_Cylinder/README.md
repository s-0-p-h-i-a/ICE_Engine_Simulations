# Arduino Single-Cylinder Engine Simulation (WIP / PoC)

## Overview

This project is a learning-focused prototype simulating a **single cylinder moving through a 4-stroke engine cycle** using LEDs on an Arduino. It practices:

- Embedded C programming and multi-file organization

- State-machine logic for engine cycles

- Mapping logical cylinder state to hardware outputs (LEDs)

- Conceptual visualization of piston and valve behavior

> **Note:** This project is a proof-of-concept and is not intended as a real-time or production engine simulation.

---
## Hardware Setup

- **Total LEDs:** 8 (arranged in 4 conceptual rows)

**Top row:**

- Blue LED → intake valve
- Green LED → exhaust valve

**Second row:**

- Yellow LED → fuel injection
- Red LED → spark plug

**Third row:**

- 2 White LEDs → TDC (top dead center)

**Fourth row (with gap below third row):**

- 2 White LEDs → BDC (bottom dead center)

This arrangement visually represents the cylinder’s four-stroke cycle on a breadboard.

---
## Code Structure

### Cylinder struct

```
struct cylinder {
    bool intakeValve;
    bool exhaustValve;
    bool fuelInjection;
    bool sparkPlug;
    enum piston pistonPosition;
};

```

### Piston enum

```
enum piston {
    TDC = TDC_PINS,
    BDC = BDC_PINS
};

```

### Cycle maps

```
extern const bool intakeValveCycle[4];
extern const bool exhaustValveCycle[4];
extern const bool fuelInjectionCycle[4];
extern const bool sparkPlugCycle[4];
extern const position pistonCycle[4];

```

These maps define **which elements are active at each stroke**, and are used in the main Arduino loop to control the LEDs.

Other elements, as well as functions, to be added.

---
## Behaviour

The Arduino loop will:

1. Read the cylinder’s current stroke from the cycle maps.

2. Update the LEDs corresponding to valves, fuel, spark, and piston position.

3. Advance to the next stroke in the sequence.

This creates a **visual, continuous simulation of a single cylinder’s 4-stroke cycle**.

---
## Learning Goals / Roadmap

- Build a strong conceptual understanding of **engine cycles** and **state-machine modeling**.

- Practice **mapping logical state to hardware outputs**.

- Extend the project over time:

    - Implement **timing delays for realistic stroke visualization**

    - Expand to **multiple cylinders using a LED matrix**

    - Integrate more realistic fuel, spark, and valve overlap logic

---
## Notes

- This is a **proof-of-concept / WIP**, intentionally structured for learning rather than production.

- Part of the larger `engine-simulations` repository, showing progression from CLI-based engines to visual hardware prototypes.