# Interrupt Driven Sensor Monitoring System

## Overview

This project demonstrates an interrupt-driven embedded system using an Arduino.

A hardware timer generates periodic interrupts every 200 ms to trigger sensor sampling.
An external button interrupt switches between manual LED blinking mode and automatic sensor-controlled mode.

## Features

* Timer interrupt based sampling
* External interrupt for mode switching
* ADC sensor reading
* Direct register-level programming
* LED control based on sensor thresholds

## Concepts Demonstrated

* Hardware timers
* Interrupt service routines
* Analog to Digital Conversion (ADC)
* Bit manipulation using AVR registers
* Embedded system state control
