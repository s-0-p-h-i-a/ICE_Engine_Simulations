# **Inline-4 Crankshaft Simulation: Arduino & CLI Versions**

**Updated:** 01/12/2025  
**Status:** Work in progress, conceptual prototypes

This folder contains two complementary versions of an inline-4 engine crankshaft simulator: one targeting **Arduino hardware with LEDs** and one **CLI-based**, terminal visualization version. Both are learning-focused prototypes intended to explore **embedded C, state representation, multi-file project structure, and modular software design**.

---
## **Overview**

The project simulates the rotation of an inline-4 engine crankshaft through the 4-stroke cycle. Each version demonstrates **state-machine logic**, **visualization of crank positions**, and **separation of engine logic from output control**, but the implementations differ according to their output method:

- **Arduino Version:** Maps crankshaft state to a **2-dimensional array of LED pins** (2 rows × 4 lobes), directly interfacing with hardware.

- **CLI Version:** Uses simple **boolean TDC/BDC logic** to control ASCII output, rendering each lobe as a series of hyphens or spaces in the terminal.

Both approaches reinforce the same underlying concepts, while giving different levels of abstraction and feedback for testing.

---
## **Hardware / Visualization Concepts**

### **Arduino**

- 8 LEDs (2 rows) represent TDC/BDC positions for each lobe
- Crankshaft state determines which LEDs are on/off each loop
- Firing order: 1-3-4-2
- Uses arrays and enums for readable indexing of pins and lobes

### **CLI**

- Terminal output visualizes TDC/BDC positions per lobe with ASCII characters (`--------` for active TDC/BDC, spaces otherwise)
- State machine logic mirrors Arduino version but without physical outputs
- Provides a hardware-free way to test and debug engine sequencing and rotation logic

---
## **Code Structure**

Both versions share the same **conceptual separation of concerns**:

- **Engine logic** is separated from **output control**, mirroring the abstraction layers in real automotive ECUs.
- Both versions use enums and arrays for readable indexing and maintainable state tracking.
- CLI version adds `checkContinue` for user-interactive pausing every few cycles.

---
## **Learning Goals**

This project was designed as a hands-on exercise to:

- Explore **multi-file C project structures** and folder separation
- Understand **how the compiler and linker manage multiple `.c` and `.h` files**
- Create **custom libraries** for engine state machine and output control
- Practice **separating internal logic (engine state machine) from actuator/interface logic**
- Visualize engine sequencing using **LEDs or terminal ASCII output**
- Gain early exposure to **embedded software patterns** used in automotive ECUs

> The CLI version reinforces modular design and logic testing without hardware, while the Arduino version provides real-world interfacing experience.

---
## **Next Steps / Future Work**

- Extend the CLI and Arduino versions to include **full cycle phases** (Intake, Compression, Combustion, Exhaust)
- Implement **timed rotation loops** for more realistic engine speed simulation
- Refactor engine logic into a reusable **C/C++ library** usable for both versions
- Introduce **multi-cylinder synchronization and expanded visualization**