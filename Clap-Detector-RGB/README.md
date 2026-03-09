# Clap Controlled RGB LED

## Overview

This project uses a microphone sensor to detect claps or sudden sound spikes and change the color of an RGB LED.

Each clap cycles through different colors such as red, green, blue, yellow, cyan, magenta, white, and off.

## Components

* Arduino Uno
* Sound sensor / microphone module
* RGB LED
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

| Component      | Arduino Pin |
| -------------- | ----------- |
| Microphone OUT | A0          |
| RGB Red        | D10         |
| RGB Green      | D11         |
| RGB Blue       | D9          |

## Working Principle

The microphone signal is continuously sampled using `analogRead()`.

When a sudden increase in sound amplitude (spike) is detected, the system interprets it as a clap.

A lock mechanism prevents multiple detections from the same sound burst.

Each detected clap cycles the RGB LED through predefined colors.

## Concepts Demonstrated

* Analog signal sampling
* Sound spike detection
* RGB LED control using PWM
* Basic event detection in embedded systems
