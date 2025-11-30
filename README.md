# ICE Engine Simulations (WIP / PoC)

A collection of **learning-focused engine simulation projects** in C and Arduino. These early-stage experiments explore **state-machine logic, modular C design, and hardware abstraction** through CLI and LED-based prototypes. Projects are conceptual and work-in-progress, demonstrating understanding of engine sequencing and embedded systems thinking. They will be iteratively refined and expanded over time.

---
## Overview

Current projects include:

1. **Inline-4 Engine CLI Simulation (v0 PoC)**
    
    - A command-line C application simulating a 4-stroke inline-4 engine.

    - Tracks independent cylinder states, piston positions, valves, fuel injection, and spark timing.

    - Implements a Moore-style finite state machine and a basic firing order (1-3-4-2).

    - Focused on learning structs, enums, arrays, loops, and modular design, intentionally pointer-free.

    - Allows step-by-step progression via CLI input.

2. **Arduino Inline-4 Crankshaft Simulation (WIP / PoC)**
    
    - Prototype to simulate crankshaft rotation using LEDs.

    - Represents each cylinder lobe as a boolean state (TDC/BDC) and maps them to LED outputs.

    - Demonstrates state-machine thinking, enum-based indexing, and multi-file C organization.

    - Conceptual and not yet functional, intended as a visual, hardware-based learning exercise.

---
## Structure

Each project is contained in its own folder (`v0/PoC`) to clearly separate work-in-progress experiments.

Each project uses **modular C structure**, separating state representation, output handling, and core logic to mimic embedded systems best practices.

---
## Planned Projects:

- Single cylinder simulation using LEDs: now in design plan phase.
- 4 cylinder inline-4 simulation using LED matrix.

---
## Learning Goals / Roadmap

- Practice **C programming**: structs, enums, arrays, loops, and modular design.

- Explore **state-machine logic** (Moore and composite multi-lobe concepts).

- Build **hardware abstraction awareness** via Arduino simulations.

- Iteratively refine projects over time:

    - Enhance timing and cycle accuracy

    - Introduce pointers and dynamic state management

    - Expand LED-based visualizations to multiple cylinders

    - Simulate more realistic engine events (misfires, spark/fuel timing, valve overlap)

---
## Notes

- Projects may be intentionally verbose and are structured for **learning and experimentation**, not production or real-time control.

- Conceptually models engine behavior and embedded logic, but does **not** simulate real engine dynamics or timing.

- The repository serves as a **portfolio of embedded and simulation concepts**, showing progression and understanding of engine control fundamentals.