# Task 4.1P – Handling Interrupts

## Overview

This task demonstrates the use of hardware interrupts with an Arduino Nano 33 IoT. The system uses a PIR motion sensor, BH1750 light sensor, slider switch and two LEDs.

The main purpose is to automatically turn the lights on when motion is detected and the environment is dark. The slider switch is also provided as a manual backup to control the lights.

## Hardware Used

* Arduino Nano 33 IoT
* PIR motion sensor
* BH1750 light sensor
* Slider switch
* 2 LEDs
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

| Component     | Arduino Pin |
| ------------- | ----------- |
| PIR Sensor    | D2          |
| Slider Switch | D3          |
| LED 1         | D4          |
| LED 2         | D5          |
| BH1750 SDA    | SDA         |
| BH1750 SCL    | SCL         |

## How It Works

When the PIR sensor detects motion, it generates an interrupt. The program then checks the light level using the BH1750 sensor.

If the light level is below the dark threshold, both LEDs are switched on automatically.

The slider switch provides a manual backup. When the switch is pressed, an interrupt is generated and the LEDs can be controlled manually.

The program also checks the light level periodically. If the lights were turned on automatically and the environment becomes bright enough, the LEDs are switched off.

## Interrupts

Two hardware interrupts are used in this task:

* The PIR sensor uses an interrupt to detect motion.
* The slider switch uses an interrupt to detect a button press.

The interrupt functions only set flags. The main `loop()` checks these flags and performs the required actions.

## Light Sensor

The BH1750 measures the amount of light in the environment in lux.

The program uses two thresholds:

* Dark threshold: 20 lux
* Bright threshold: 40 lux

The dark threshold is used when motion is detected, while the bright threshold is used to automatically switch the lights off when automatic mode is active.

## Testing

The system was tested by:

1. Triggering the PIR sensor while the environment was dark.
2. Checking that both LEDs turned on.
3. Pressing the slider switch to manually control the LEDs.
4. Checking the messages displayed in the Serial Monitor.
5. Changing the light level and checking the automatic light response.

## Circuit Diagram

The circuit diagram for the task is included below.

![Circuit Diagram](images/circuit.jpg)

## Serial Monitor

The Serial Monitor output showing the interrupt events and light control is included below.

![Serial Monitor](images/serial-monitor.jpg)

## Source Code

The Arduino source code for Task 4.1P is available in:

`Task4.1Interrupts.ino`

