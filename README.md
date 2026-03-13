# BLE Fleet Management System

Embedded system for driver identification and vehicle tracking using Bluetooth Low Energy (BLE).

This project was developed as part of an engineering final-year project at **Be Wireless Solutions (BWS)**.  
The objective is to replace the traditional **physical driver identification system (iButton)** with a **secure wireless BLE-based solution** integrated into an existing fleet management device.

The system enables driver authentication via smartphone and allows real-time GPS position retrieval from the vehicle tracker.

---

# Project Overview

Fleet management systems traditionally rely on **physical identification keys** such as iButton devices.  
Although widely used, these systems present several limitations:

- mechanical wear of readers and keys
- risk of loss or duplication of physical identifiers
- manual interaction required for identification
- limited automation capabilities

To address these issues, this project proposes a **wireless driver identification system using Bluetooth Low Energy (BLE)**.

A dedicated BLE microcontroller communicates with the existing vehicle tracker and allows driver authentication through a mobile device.

---

# System Architecture

The system is composed of three main elements:

1. Mobile application (BLE client)
2. BLE communication module (STM32WB55)
3. Vehicle tracker (BWS-GR1) with integrated GPS module

---

# Hardware Components

The prototype system is based on the following hardware components:

• **STM32WB55 microcontroller** – BLE communication module  
• **BWS-GR1 tracker** – embedded fleet management device  
• **SIM868 module** – GPS positioning module  
• **Smartphone** – BLE client used for driver identification  

The STM32WB55 provides native Bluetooth Low Energy connectivity and ensures secure communication with the mobile device.

---

# Software Architecture

The embedded firmware was developed using:

- STM32CubeIDE
- STM32 HAL drivers
- STM32WPAN middleware (Bluetooth stack)

The software architecture includes the following main modules:

- BLE GATT service
- UART communication interface
- GPS data processing module
- command parsing module
- system event management

The system is designed to remain **modular and portable for future embedded applications**.

---

# BLE Communication

A custom **BLE GATT service** was implemented to manage communication between the mobile device and the embedded system.

The service contains two main characteristics:

### Write Characteristic
Used by the mobile application to send commands such as:

- driver identification request
- position request

### Notification Characteristic
Used by the embedded system to send responses to the mobile application, including:

- identification status
- GPS position

---

# UART Communication

The STM32WB55 communicates with the BWS-GR1 tracker using a **UART interface**.

This communication link is responsible for:

- forwarding identification commands to the tracker
- receiving GPS information from the SIM868 module
- sending responses back to the BLE module

The UART interface ensures reliable data exchange between both embedded devices.

---

# GPS Data Processing

Vehicle position data is obtained from the **SIM868 GPS module** integrated in the tracker.

GPS data is transmitted in **NMEA format**, which includes frames such as:
$GPGGA
$GPRMC

The firmware parses these frames to extract key parameters:

- latitude
- longitude
- speed
- timestamp

The extracted information is then sent to the mobile application via BLE notifications.

---

# Security Features

Security mechanisms were integrated into the BLE communication layer to ensure safe access to the system.

Implemented features include:

- BLE pairing and bonding
- encrypted communication
- passkey authentication
- access control for GATT characteristics

These mechanisms protect the system against unauthorized connections and data interception.

---

# Development Tools

The project was developed using the following tools:

- **STM32CubeIDE** – embedded development environment
- **STM32WPAN** – Bluetooth middleware
- **ST BLE Toolbox** – BLE testing application
- **MIT App Inventor** – prototype mobile application

---

# Testing and Validation

Several validation tests were performed during development:

• BLE communication tests  
• UART communication validation  
• GPS data acquisition tests  
• secure authentication tests  
• end-to-end system validation

These tests confirmed the feasibility of a **BLE-based driver identification system integrated with the existing fleet management infrastructure**.

---

---

# Future Improvements

Potential future enhancements include:

- integration of BLE directly inside the tracker hardware
- development of a production-ready mobile application
- cloud connectivity for remote fleet monitoring
- advanced security mechanisms

---

# Author

Olfa Ameur  
Embedded Systems Engineering

