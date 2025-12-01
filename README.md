# ICE Engine Simulations (WIP / PoC)

A collection of **learning-focused engine simulation projects** in C and Arduino. These early-stage experiments explore **state-machine logic, modular C design, and hardware abstraction** through CLI and LED-based prototypes. Projects are conceptual and work-in-progress, demonstrating understanding of engine sequencing and embedded systems thinking. They will be iteratively refined and expanded over time.

**Fully functional:** CLI crankshaft simulation.

**Current WIPs:** cylinder and crankshaft simulations.

**Long-term goal:** add DOHC camshafts, fuel injection and spark plug projects, merge into simple Moore machine-like simulation of inline-4 engine control.

---
## Overview

Current projects include:

1. **Inline-4 Crankshaft Simulations, CLI (functional v0) Arduino (WIP / PoC)**

	- Functional CLI "sandbox" version for practice, using ASCII visuals to represent side view of the crankshaft.
    
    - Prototype to simulate crankshaft rotation using LEDs.

    - Represents each cylinder lobe as a boolean state (TDC/BDC) and maps them to LED outputs.

    - Demonstrates state-machine thinking, enum-based indexing, and multi-file C organization.

    - Conceptual and not yet functional, intended as a visual, hardware-based learning exercise.

2. **Inline-4 Engine CLI Simulation (v0 WIP / PoC)**
    
    - A command-line C application simulating a 4-stroke inline-4 engine.

    - Tracks independent cylinder states, piston positions, valves, fuel injection, and spark timing.

    - Implements a Moore-style finite state machine and a basic firing order (1-3-4-2).

    - Focused on learning structs, enums, arrays, loops, and modular design, intentionally pointer-free.

    - Allows step-by-step progression via CLI input.
    
3. **Arduino 1-Cylinder Simulation (WIP / PoC)**
    
    - Design plan to simulate one cylinder moving through combustion cycle using LEDs and a breadboard.

4. **Arduino 4-Cylinder Simulation (Planned)**
    
    - Expansion on the 1-cylinder project, simulating an inline-4 engine using an LED matrix.

5. **Camshafts Simulation (Planned)**
    
    - Simulate valve distribution control in an inline-4 DOHC engine.

6. **Fuel & Spark Simulation (Planned)**
    
    - Simulate fuel injector and spark plug control.

7. **Simple Inline-4 Engine Simulation (Planned)**
    
    - Progressively combine previously developed cylinder, crank, cam, injection and ignition logic into modular, simplified Moore machine-like inline-4 engine control simulation.

---
## Structure

Each project is contained in its own folder (`v0/PoC`) to clearly separate work-in-progress experiments.

Each project uses **modular C structure**, separating state representation, output handling, and core logic to mimic embedded systems best practices.

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
