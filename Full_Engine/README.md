# Flywheel & LED Cylinder Mini Embedded System

## Overview

This project simulates an engine + flywheel system controlled via a joystick, with LED cylinder visualization and Hall sensor RPM feedback. It is structured as a modular “mini embedded system” with separate hardware interface modules and logic modules.

This project is the first step towards building a more complete Arduino-based inline-4 engine simulation, integrating a crankshaft and DOHC camshafts.

---
## Modules

- **Drive, Engine, EngineVisuals** – handles engine logic and LED display

- **Flywheellib** – flywheel simulation and dynamics

- **Halllib** – Hall sensor input interface

- **Joystick** – joystick input abstraction

- **Servolib** – servo control

- **Rpmlib** – RPM calculation

- **Plotter** – serial output for visualization/debugging

- **Global** – shared timing variables (`now`, `timewindow`)

---
### Design Notes

- Logic and dynamics (`.c` modules) are hardware-agnostic and can be tested independently of Arduino.

- Hardware interface modules (`.cpp`) handle Arduino-specific functionality like LEDs, servos, and serial I/O.

- Clear separation of concerns allows safe refactoring and modular testing.

---
## Status

- **Builds successfully on Arduino CLI.**
- Hardware integration and live testing have not been performed yet.