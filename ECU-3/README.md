# ECU-3 : Automotive Dashboard Receiver Unit

## Overview

ECU-3 acts as the central dashboard unit. It receives data from ECU-1 and ECU-2 and displays the vehicle information.

## Functions

* Receives speed and gear data from ECU-1.
* Receives RPM and indicator data from ECU-2.
* Processes received information.
* Displays dashboard parameters.

## Received Parameters

| Source | Parameters            |
| ------ | --------------------- |
| ECU-1  | Speed, Gear           |
| ECU-2  | RPM, Indicator Status |

## Communication

* UART Reception
* Multi-ECU Data Monitoring

## Dashboard Information

* Vehicle Speed
* Gear Position
* Engine RPM
* Indicator Status

## Peripherals Used

* UART
* CLCD Display
* GPIO

## Files

* ecu3_main.c
* uart.c
* uart.h
* clcd.c
* clcd.h

## Controller

PIC18F4580

## Language

Embedded C

