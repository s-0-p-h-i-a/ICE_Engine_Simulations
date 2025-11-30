# Inline-4 Engine Cycle Simulation v0 PoC (No Pointers)

This repository contains a simple **C-based command-line simulation of a 4-stroke inline-4 engine**. It’s a proof-of-concept project designed to **practice C programming, finite state machines, and struct/enum usage**.

Implements independent cylinder states, firing order logic, and a Moore-style finite state machine to track piston position, valves (intake and exhaust), fuel injection, and spark timing.

---
## Features

- Models **four cylinders** with independent stroke states.

- Uses **Moore-style state logic** to represent:

    - Intake
    - Compression
    - Combustion
    - Exhaust

- Tracks **piston position**, **valve states**, **fuel injection**, and **spark** for each cylinder.

- Allows the user to **advance the simulation step-by-step**, checking or continuing the engine cycles interactively.

- Implements a **basic firing order (1-3-4-2)**.

---
## Structure

- `global.h/c` – defines enums, structs, and arrays representing cylinder and stroke states.
- `output.h/.c` – prints the current state of each cylinder.
- `checkContinue.h/c` – simple CLI input to control simulation progression.
- `main.c` – orchestrates the engine cycle simulation.

---
## Learning Goals / Roadmap

- Serve as a **learning platform for practicing C**: structs, enums, arrays, loops, and modular design.

- Refine simulation over time:

    - Introduce **pointers** for cylinder arrays.
    - Expand **realistic timing** and engine dynamics.
    - Explore **Mealy-style event responses** (e.g., misfires or backfires).

---
## Notes

- This is intentionally **verbose and pointer-free** to focus on understanding engine logic and finite state machines.
- Conceptually models an **abstract engine FSM**, not a real-time engine controller.