# Binary Counter with 7-Segment Display using 74HC595

## Overview

This project demonstrates driving a multiplexed 4-digit 7-segment display using an Arduino and a 74HC595 shift register.

The counter value is split into individual digits and displayed sequentially using multiplexing.

## Components

* Arduino Uno
* 74HC595 Shift Register
* 4-Digit 7-Segment Display
* LEDs (for binary output)
* Resistors
* Breadboard

## Working Principle

The Arduino sends segment data to the 74HC595 using the `shiftOut()` function.

Each digit is enabled one at a time while the corresponding segment pattern is shifted into the register.
Rapid switching creates the illusion that all digits are lit simultaneously.

## Features

* Binary LED output of the counter
* 4-digit multiplexed 7-segment display
* Serial-to-parallel conversion using shift register

## Concepts Demonstrated

* Shift register interfacing
* Multiplexing
* 7-segment encoding
* Embedded timing control
