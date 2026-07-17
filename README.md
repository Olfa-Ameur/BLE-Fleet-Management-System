Fleet Driver Identification over BLE
Overview

Designed and developed an embedded Bluetooth Low Energy gateway enabling secure wireless driver identification for an existing fleet management device.

The solution replaces the traditional physical iButton authentication by integrating a STM32WB55-based BLE module communicating with the company's BWS-GR1 controller over UART.

Engineering Challenge

The existing fleet device relied on physical electronic keys for driver authentication.

The objective was to investigate a secure wireless alternative while preserving compatibility with the existing embedded platform.

My Contributions
Designed the embedded firmware for STM32WB55
Configured STM32WPAN BLE middleware
Developed custom BLE GATT services
Implemented UART communication between two MCUs
Processed GPS NMEA frames received from the BWS-GR1
Implemented secure BLE pairing using Passkey Entry
Validated BLE, UART and GPS communication through functional testing
Technologies

STM32WB55

Embedded C

STM32CubeIDE

STM32WPAN

BLE

UART

HAL

DMA

GPS

SIM868

GATT

GAP

Passkey Entry

Git

Key Features

✔ Wireless driver authentication

✔ BLE notifications

✔ GPS position transmission

✔ Secure BLE pairing

✔ UART communication

✔ Real-time embedded communication

Results
Successfully replaced contact-based authentication with a BLE prototype.
Demonstrated reliable communication between the BLE gateway and the existing fleet management device.
Validated secure authentication and real-time GPS data exchange.
