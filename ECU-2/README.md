# ECU-2 : RPM and Indicator Transmission Unit

## Overview

ECU-2 is responsible for monitoring engine RPM and vehicle indicator status and transmitting the information to the dashboard ECU.

## Functions

* Reads engine RPM value.
* Reads left/right indicator status.
* Packages RPM and indicator information.
* Transmits data through UART communication.

## Transmitted Parameters

| Parameter | Description                      |
| --------- | -------------------------------- |
| RPM       | Engine speed                     |
| Indicator | Left/Right turn indicator status |

## Peripherals Used

* UART
* GPIO

## Files

* ecu2_main.c
* uart.c
* uart.h

## Output

The ECU continuously transmits RPM and indicator status information to the receiving ECU.

## Controller

PIC18F4580

## Language

Embedded C

