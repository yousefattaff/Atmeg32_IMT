# ATmega32 Drivers & Applications

## Overview

**Atmeg32_IMT** is an embedded systems project that focuses on developing reusable drivers and small test applications for the **ATmega32 microcontroller**.
The goal of this repository is to practice and implement **layered embedded software architecture**, separating hardware abstraction from application logic while keeping the drivers modular and reusable.

The project follows a structure similar to what is commonly used in professional embedded systems development, dividing the system into:

* **MCAL (Microcontroller Abstraction Layer)** – Low-level drivers that interact directly with the microcontroller registers.
* **HAL (Hardware Abstraction Layer)** – Higher level drivers for external hardware components.
* **APP (Applications)** – Example programs used to test and demonstrate the drivers.

The repository is still under active development, and more drivers, improvements, and architectural refinements are planned.

---

# Architecture

The project is organized using a **layered architecture**, which helps isolate hardware dependencies and improve code maintainability.

```
Application Layer (APP)
        ↓
Hardware Abstraction Layer (HAL)
        ↓
Microcontroller Abstraction Layer (MCAL)
        ↓
ATmega32 Hardware
```

### 1. MCAL (Microcontroller Abstraction Layer)

This layer interacts **directly with ATmega32 registers** and provides basic microcontroller functionality.

Current MCAL drivers include:

* **DIO (Digital Input/Output)**

  * Pin configuration
  * Pin read/write
  * Port manipulation

These drivers are responsible for controlling the actual hardware registers of the microcontroller.

---

### 2. HAL (Hardware Abstraction Layer)

The HAL layer builds on top of MCAL and provides **drivers for external hardware components** connected to the microcontroller.

Implemented drivers include:

* **LCD Driver**
* **LED Driver**
* **Keypad Driver**
* **Seven Segment Display**
* **Stepper Motor**
* **DC Motor**
* **Switches**
* **Ultrasonic Sensor**

These drivers internally use the **MCAL layer** to access pins and ports.

For example:

* The **LCD driver** uses DIO to control data and control pins.
* The **Keypad driver** scans rows and columns using digital I/O.
* The **Stepper Motor driver** controls phase sequences through GPIO pins.

---

### 3. Application Layer (APP)

This layer contains **example applications used to test the drivers** and demonstrate their functionality.

Examples included in the repository:

* **LED Blink**
* **Keypad Test**
* **LCD Display Applications**
* **Stepper Motor Test**
* **Traffic Light Simulation**
* **Motor Control Assignment**
* **Battery Loading Animation**
* **LCD Sinusoidal Name Animation**

Each application is designed to verify that a specific driver behaves correctly.

---

# Repository Structure

```
Atmeg32_IMT
│
├── APP
│   ├── LED_BLINK.c
│   ├── KBDTEST.c
│   ├── STEPPER_TEST.c
│   ├── TrafficLightAssignment.c
│   ├── LCD_Assignment 1.c
│   ├── LCD_ENTIRE_NAME_SINUSOIDAL.c
│   └── ...
│
├── HAL
│   ├── LCD
│   ├── LED
│   ├── KeyPad
│   ├── Seven_Segment
│   ├── StepperMotor
│   ├── DcMotor
│   ├── Switches
│   └── ultrasonic
│
├── MCAL
│   └── DIO
│
└── README.md
```

---

# Design Goals

This repository was created with several goals in mind:

### 1. Modular Driver Design

Drivers are written to be reusable and independent whenever possible.

### 2. Layered Embedded Architecture

Separating MCAL, HAL, and APP layers helps simulate real embedded software stacks used in industry.

### 3. Hardware Abstraction

Applications should not directly manipulate registers but instead rely on drivers.

### 4. Practical Testing

Every driver should have **small testing applications** to confirm correct behavior.

---

# Planned Improvements

The project is still evolving and several improvements are planned:

* Refactor drivers to support **Post-Build / Linker-Time configuration**
* Improve **driver configurability**
* Add more **MCAL drivers** such as:

  * Timers
  * UART
  * SPI
  * I2C
  * ADC
* Improve **documentation and examples**
* Add **interrupt-based drivers**
* Introduce **better hardware abstraction**

---

# Technologies Used

* **Language:** C
* **Microcontroller:** ATmega32
* **Embedded Architecture:** Layered Drivers (MCAL / HAL / APP)

---

# Purpose of the Project

This repository is mainly intended for:

* Practicing **embedded driver development**
* Understanding **hardware abstraction layers**
* Building reusable **embedded libraries**
* Strengthening knowledge of **ATmega32 architecture**




