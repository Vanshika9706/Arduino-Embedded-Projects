# Temperature and Humidity Display using Arduino

## Overview

This project measures environmental temperature and humidity using a digital sensor and displays the values through serial communication. It demonstrates basic sensor interfacing and environmental monitoring using Arduino.

## Components Used

* Arduino Uno
* DHT11 / DHT22 Temperature & Humidity Sensor
* Breadboard
* Jumper wires

## Pin Connections

| Component       | Arduino Pin |
| --------------- | ----------- |
| DHT Sensor Data | D2          |
| VCC             | 5V          |
| GND             | GND         |

*(Pin numbers may vary depending on your implementation.)*

## Working Principle

The DHT sensor measures temperature and humidity and sends digital data to the Arduino.
The Arduino reads this data using the DHT library and prints the measured values to the Serial Monitor.

The system continuously monitors environmental conditions and updates the readings periodically.

## Example Output

Temperature: 28°C
Humidity: 65%

## Concepts Demonstrated

* Digital sensor interfacing
* Environmental monitoring
* Serial communication
* Embedded system data acquisition
