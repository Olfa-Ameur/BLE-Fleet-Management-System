# STM32WB55-Based BLE Gateway for Fleet Management System Modernization

## 📌 Project Overview

This project presents the design and implementation of a **BLE gateway prototype** aimed at modernizing an existing fleet management system.

The objective is to introduce **smartphone-based driver identification and wireless location monitoring** while maintaining compatibility with the existing embedded fleet management product.

The solution is based on an **STM32WB55 microcontroller**, acting as a communication bridge between a mobile application and the existing system through:

* **Bluetooth Low Energy (BLE)** communication with the smartphone
* **UART communication** with the fleet management device

The prototype enables secure driver authentication, GPS data exchange, and bidirectional communication between the mobile interface and the embedded system.

---

# 🎯 Project Objectives

* Modernize an existing fleet management solution using BLE connectivity
* Replace traditional physical identification methods with smartphone-based authentication
* Develop a BLE gateway using STM32WB55
* Design custom BLE GATT services for application-specific communication
* Establish communication between BLE and UART interfaces
* Integrate BLE security mechanisms for protected communication

---

# 🏗 System Architecture

```
                 Smartphone Application
                         |
                         |
                    BLE Communication
                         |
                         |
                  STM32WB55 Gateway
                         |
              -------------------------
              |                       |
             UART              BLE Security Layer
              |
              |
       Existing Fleet Management
              Device
```

The STM32WB55 operates as a gateway between the mobile application and the existing fleet management product, enabling communication translation between BLE and UART protocols.

---

# 🔄 Communication Workflow

## Driver Authentication Flow

```
Smartphone
    |
    | Driver Identifier (BLE Write)
    ↓
STM32WB55 Gateway
    |
    | UART Command
    ↓
Fleet Management Device
    |
    | Authentication Response
    ↓
STM32WB55 Gateway
    |
    | BLE Notification
    ↓
Smartphone
```

The driver enters identification information through the mobile application.
The STM32WB55 receives the data through BLE, forwards it to the existing fleet management device through UART, and returns the authentication result to the smartphone.

---

## GPS Location Monitoring Flow

```
Fleet Management Device
          |
          | GPS Data (UART)
          ↓
      STM32WB55 Gateway
          |
          | BLE Notification
          ↓
   Smartphone Application
```

The location information provided by the fleet management system is transmitted through UART to the STM32WB55 and then notified to the smartphone using BLE communication.

---

# 🔵 BLE Application Design

A custom BLE GATT profile was developed to support fleet management functionalities.

## Driver Authentication Service

### Driver Identifier Characteristic

**Properties:**

* Write

**Purpose:**

Receives the driver's identification information transmitted from the smartphone application.

---

### Authentication Status Characteristic

**Properties:**

* Notify

**Purpose:**

Sends the authentication result from the fleet management system back to the smartphone.

---

## GPS Location Service

### Location Data Characteristic

**Properties:**

* Notify

**Purpose:**

Transfers GPS location information received from the fleet management device to the smartphone application.

---

# 🔐 BLE Security Implementation

To improve communication security, BLE security mechanisms were configured using the STM32WB BLE stack.

Implemented features:

* BLE Pairing process
* Passkey Entry authentication method
* Security Manager (SM) layer configuration
* Secure connection establishment between devices

These mechanisms help protect wireless communication against unauthorized access.

---

# 💻 Embedded Firmware Development

The embedded firmware was developed for the STM32WB55 platform.

## Main functionalities

✔ BLE stack initialization
✔ Custom GATT services implementation
✔ BLE connection management
✔ Data exchange between BLE and UART interfaces
✔ Authentication request processing
✔ GPS data forwarding
✔ Notification handling

---

# 🛠 Hardware & Software Environment

## Hardware

| Component               | Description                                   |
| ----------------------- | --------------------------------------------- |
| STM32WB55               | BLE-enabled microcontroller acting as gateway |
| Smartphone              | BLE central device for user interaction       |
| Fleet Management Device | Existing embedded product                     |
| GPS Module              | Location data source                          |

---

## Software Tools

* STM32CubeMX
* STM32CubeIDE
* STM32 HAL Drivers
* STM32WB BLE Middleware
* Embedded C

---

# 📡 Communication Protocols

| Protocol                   | Usage                                    |
| -------------------------- | ---------------------------------------- |
| Bluetooth Low Energy (BLE) | Smartphone communication                 |
| GATT                       | Custom application data exchange         |
| UART                       | Communication with existing fleet system |

---

# 📷 Project Demonstration

Recommended project documentation:

* System architecture diagram
* STM32WB55 hardware setup
* BLE GATT service configuration
* BLE pairing/security configuration
* UART communication logs
* Smartphone communication screenshots

---

# 🚀 Skills Demonstrated

* Embedded firmware development
* STM32WB55 programming
* BLE application development
* Custom GATT profile design
* Embedded gateway architecture
* Hardware/software integration
* UART communication
* BLE security configuration
* Legacy system modernization approach

---

## 👩‍💻 Author

**Olfa Ameur**
Electronics & Embedded Systems Engineering
