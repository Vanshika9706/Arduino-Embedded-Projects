# Knight Rider LED Pattern using 74HC595

## Overview

This project generates a "Knight Rider" scanning LED pattern using a 74HC595 shift register and an Arduino.
The LEDs turn on sequentially from left to right and then reverse direction, creating a sweeping light effect.

## Components

* Arduino Uno
* 74HC595 Shift Register
* 8 LEDs
* 220Ω resistors
* Breadboard
* Jumper wires

## Working Principle

The Arduino sends LED patterns to the 74HC595 using the `shiftOut()` function.
Each pattern corresponds to a single LED being active.

The LED position moves across the register outputs and then reverses direction, creating a back-and-forth scanning effect.

## Concepts Demonstrated

* Serial-to-parallel conversion using 74HC595
* LED sequencing
* Timing control using delays
* Bit manipulation for LED patterns
