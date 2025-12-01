# **Dev Log – Inline-4 Crankshaft CLI Simulation**

**Date:** 01/12/2025  
**Version:** 0.1 (First functional iteration)

---
## **Project Goal**

Create a terminal-based simulation of a 4-lobe inline-4 crankshaft moving through a 4-stroke engine cycle.  
Focus on **learning goals** rather than mechanical precision:

- Multi-file C project structure

- Custom library creation (`cranklib` & `graphicslib`)

- Clear separation between engine logic (state machine) and output/interface code

- Practice ASCII terminal visualization and simple user interaction

This serves as a lightweight, hardware-free precursor to the Arduino LED version and a hands-on exercise in ECU-style software architecture.

---
## **Implementation Notes**

### **Engine Logic (`cranklib`)**

- `initCrank()` initializes each lobe’s starting position.

- `spinCrank()` toggles the lobe state to simulate rotation.

- Encapsulated as a mini library to practice modular design and function exposure through headers.

### **Graphics (`graphicslib`)**

- `spinCrankVisual()` renders current crankshaft state to the terminal.

- Helper functions `printLobesTDC()`, `printLobesBDC()`, and `printSpacers()` generate ASCII frames.

- `clearTerminal()` refreshes the display to simulate motion.

- Visual layer completely separated from engine state logic — mirrors ECU actuator abstraction.

### **Main Loop**

- Initializes crankshaft state using `initCrank()`.

- Cycles through crankshaft updates with `spinCrank()`.

- Every 8 cycles, asks user whether to continue (`checkContinue()`).

- Updates ASCII output each cycle, then pauses (`usleep(500000)` = 0.5s) for readability.

---
### **Learning Highlights**

- First use of multiple folders for multi-file C structures .

- First attempt at personal “library” creation and API exposure through headers.

- Explicit separation between **state machine (engine)** and **interface/graphics (actuation)** — parallels real ECU architecture.

- Practiced ANSI escape codes for terminal redraws and clean ASCII visuals.

- Gained understanding of how the **compiler and linker handle multiple `.c` and `.h` files**.