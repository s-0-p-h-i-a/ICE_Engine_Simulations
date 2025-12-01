# Arduino Inline-4 Crankshaft Simulation (WIP / PoC)

30/11

**Work in progress — conceptual prototype, not functional yet.**  
This project simulates an inline-4 engine crankshaft with LEDs on an Arduino. It is intended as a **learning exercise in embedded C**, exploring state representation, multi-file structure, enum-based indexing, and hardware abstraction. The code demonstrates early-stage conceptual thinking about engine sequencing and state-machine logic; it is not production-ready and serves as a hands-on PoC for debugging and iterative learning.

---
## Overview

This project is a **first-layer prototype** to simulate an inline-4 engine crankshaft using LEDs on a breadboard. It is intended as a **learning exercise in embedded C**, exploring:

- State representation of engine lobes

- Basic multi-file C organization (`.h` / `.c`)

- Enum-based indexing and arrays

- Mapping logical state to hardware outputs (LEDs)

- Simple conceptual state-machine behavior

> **Note:** This project is not yet functional. The code is structured for conceptual understanding and debugging practice rather than real-world operation.

---
## Hardware Concept

- 8 LEDs arranged in 2 rows, representing **TDC / BDC positions** for each cylinder lobe

- 4 lobes, representing the cylinders of an inline-4 engine

- LEDs light up according to the **crankshaft state array**, toggling TDC ↔ BDC each loop

- Firing order: 1-3-4-2

**Simplified visualization (conceptual):**

|     | LOBE 1  | LOBE 2  | LOBE 3  | LOBE 4  |
| --- | ------- | ------- | ------- | ------- |
| TDC |         | ------- | ------- |         |
| BDC | ------- |         |         | ------- |

---
## Code Structure

- `global.h/.c`: Definitions, pin mappings, constants, and global state

- `setPins.h/.c`: Logic to determine which LED pin to light based on lobe state

- `spinCrank.h/.c`: Writes output to LEDs

- `crank_run.h/.c`: Updates crankshaft state per loop; conceptual state-machine logic

- `initCrank.h/.c`: Initializes the crankshaft state

- `main.c`: "Runs" the "engine"

The code uses **booleans and arrays** to track lobe positions and **enums** for readable indexing.

---
## Purpose / Learning Goals

This project is primarily a **hands-on practice tool** to:

- Understand mapping between logical state and physical outputs

- Explore multi-dimensional arrays for hardware abstraction

- Practice iterative, modular C programming for embedded systems

- Visualize engine cycle sequencing with LEDs

It is intentionally a **proof-of-concept**, meant to be debugged, extended, and refined as a learning exercise.

---
## Next Steps

- Implement full **loop logic** to simulate continuous crankshaft rotation

- Expand state machine to include **cycle phases (Intake, Compression, Combustion, Exhaust)**

- Optional: add timing control for realistic crankshaft speed visualization

---
## Notes

- This project is part of a **series of engine simulation experiments** in the `ICE_Engine_Simulations` repository

- All code is in early-stage PoC form; it is not production-ready

- Designed for **learning and demonstration** of embedded C and engine sequencing concepts