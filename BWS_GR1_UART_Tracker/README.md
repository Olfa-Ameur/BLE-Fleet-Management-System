# BLE Driver Identification System for Fleet Management

This project presents an embedded system designed to replace the traditional physical iButton driver identification mechanism used in fleet management systems with a wireless Bluetooth Low Energy (BLE) based authentication solution.

The system enables secure driver identification using a smartphone application and a BLE communication architecture between two microcontrollers integrated in a vehicle tracking device.

This work was developed as part of an engineering final year project.

---

# Project Overview

Fleet management systems traditionally use physical authentication devices such as iButton keys to identify drivers before allowing the vehicle to operate.

However, this approach presents several limitations:

- Physical wear of the iButton keys
- Risk of loss or duplication
- Lack of flexibility
- Maintenance constraints

To address these limitations, this project proposes a wireless driver authentication system using Bluetooth Low Energy.

The driver is authenticated using a mobile application that communicates with the embedded BLE module integrated in the vehicle system.

---

# System Architecture

The proposed system consists of three main components:

• STM32WB55 BLE module  
• BWS-GR1 fleet management device  
• Mobile application for driver identification  

The communication architecture is illustrated below:

Smartphone Application  
        │  
        │ BLE Communication  
        ▼  
STM32WB55 BLE Node  
        │  
        │ UART Communication  
        ▼  
BWS-GR1 Fleet Tracker  
        │  
        ▼  
GPS Module (SIM868)  
        │  
        ▼  
Fleet Management Platform  

The BLE module receives identification requests from the mobile application and transfers the authentication information to the BWS-GR1 tracker via UART communication.

---

# Key Features

- Wireless driver identification using BLE
- Replacement of physical iButton authentication
- Communication between two embedded systems
- UART data exchange between microcontrollers
- GPS notification and fleet monitoring
- Mobile application interaction

---

# Hardware Components

The system is implemented using the following hardware components:

STM32WB55 microcontroller  
BLE communication module  
BWS-GR1 fleet tracking device  
SIM868 GPS communication module  
Smartphone mobile application  

---

# Firmware Architecture

The project firmware is divided into two main embedded applications.

## 1. STM32WB55 BLE Node

Responsible for:

- BLE communication with the mobile application
- Receiving identification requests
- Transmitting authentication data to the tracker
- Managing BLE services and notifications

Key files include:

- `app_ble.c`
- `custom_stm.c`
- `command_parser.c`

---

## 2. BWS-GR1 Tracker Firmware

Responsible for:

- Receiving identification data via UART
- Managing GPS communication
- Sending driver identification notifications
- Interacting with the fleet management system

Key modules include:

- `gps_functions.c`
- `command_parse.c`
- `uart.c`

---

# Software Tools

The development environment includes:

- STM32CubeIDE
- Embedded C
- STM32 HAL libraries
- Bluetooth Low Energy stack
- UART communication drivers

---

# Skills Demonstrated

This project demonstrates several embedded systems engineering skills:

- Embedded firmware development
- Bluetooth Low Energy communication
- Multi-microcontroller architecture
- UART communication protocols
- IoT system integration
- Real-time embedded software design

---

# Author

Olfa Ameur  

Embedded Systems Engineer  

Fields of interest:

Embedded Systems  
Internet of Things  
Bluetooth Low Energy  
Smart Vehicle Systems  

---
