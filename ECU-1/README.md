# ECU-1 : Speed and Gear Transmission Unit

## Overview

ECU-1 is responsible for acquiring vehicle speed and gear position information and transmitting the data to the dashboard ECU.

## Functions

* Reads vehicle speed value.
* Reads current gear position.
* Packages speed and gear information.
* Transmits data through UART communication.

## Transmitted Parameters

| Parameter | Description           |
| --------- | --------------------- |
| Speed     | Vehicle speed         |
| Gear      | Current gear position |

## Peripherals Used

* UART
* GPIO

## Files

* ecu1_main.c
* uart.c
* uart.h

## Output

The ECU continuously transmits speed and gear information to the receiving ECU.

## Controller

PIC18F4580

## Language

Embedded C

