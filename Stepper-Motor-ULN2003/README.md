# Stepper Motor Control using ULN2003 and Arduino

## Overview

This project controls a 28BYJ-48 stepper motor using a ULN2003 driver module.
The motor rotates 90° forward and then reverses, repeating continuously.
A relay module is also activated to demonstrate control of external loads.

## Components Used

* Arduino Uno
* 28BYJ-48 Stepper Motor
* ULN2003 Driver Board
* Relay Module
* Jumper wires
* External power supply (optional)

## Pin Connections

### Stepper Motor Driver (ULN2003)

| ULN2003 Pin | Arduino Pin |
| ----------- | ----------- |
| IN1         | D8          |
| IN2         | D10         |
| IN3         | D9          |
| IN4         | D11         |

### Relay Module

| Relay | Arduino |
| ----- | ------- |
| IN    | D7      |
| VCC   | 5V      |
| GND   | GND     |

## Working Principle

The Arduino uses the Stepper library to control the 28BYJ-48 motor through the ULN2003 driver.
The motor moves 512 steps (~90° rotation) forward and then 512 steps backward.

A relay output is enabled during operation to demonstrate switching capability for external loads such as lamps or motors.

## Key Parameters

* Steps per revolution: 2048
* Rotation per cycle: 512 steps (~90°)
* Speed: 10 RPM

## Example Behavior

1. Relay turns ON
2. Stepper rotates forward
3. Waits 2 seconds
4. Stepper reverses direction
5. Cycle repeats

## Learning Outcomes

* Interfacing stepper motors
* Using the Arduino Stepper library
* Controlling relays
* Understanding motor step control
