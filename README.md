# CAN-Based Automotive Dashboard using PIC18F4580

## Overview

This project implements a CAN-Based Automotive Dashboard using PIC18F4580 microcontrollers. The system consists of three Electronic Control Units (ECUs) that communicate automotive parameters such as vehicle speed, gear position, RPM, and indicator status.

The project demonstrates CAN communication concepts using Embedded C and MPLAB X IDE.

## System Architecture

### ECU-1 (Vehicle Speed & Gear Transmitter)

Functions:

* Reads vehicle speed data.
* Reads gear position information.
* Transmits Speed and Gear data.

Transmitted Parameters:

* Vehicle Speed
* Current Gear

### ECU-2 (RPM & Indicator Transmitter)

Functions:

* Reads engine RPM.
* Reads indicator status.
* Transmits RPM and Indicator information.

Transmitted Parameters:

* Engine RPM
* Left/Right Indicator Status

### ECU-3 (Dashboard Receiver)

Functions:

* Receives messages from ECU-1 and ECU-2.
* Displays received vehicle information.
* Acts as the central dashboard unit.

Received Parameters:

* Vehicle Speed
* Gear Position
* Engine RPM
* Indicator Status

## Communication Details

* Communication Method: UART-based Loopback Simulation
* Protocol Concept: CAN-Based Automotive Communication
* Controller: PIC18F4580
* Language: Embedded C

## Features

* Multi-ECU Architecture
* Speed Monitoring
* Gear Position Monitoring
* RPM Monitoring
* Indicator Status Monitoring
* UART Communication
* Modular Embedded Software Design

## Tools Used

* MPLAB X IDE
* XC8 Compiler
* PIC18F4580 Microcontroller
* Embedded C

## Project Structure

CAN-Based-Automotive-Dashboard/

├── ECU-1/

├── ECU-2/

├── ECU-3/

└── README.md

## Learning Outcomes

* UART Communication
* Automotive ECU Architecture
* Data Transmission and Reception
* Embedded C Modular Programming
* PIC18F4580 Peripheral Configuration
* Automotive Dashboard Design Concepts

## Author

MD Abdul Azeez

Embedded Systems Developer

