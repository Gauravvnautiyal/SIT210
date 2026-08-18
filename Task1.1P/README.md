# Task 1.1P - Switching ON Lights

This project uses an Arduino Nano 33 IoT, two LEDs, resistors and a push button to control the porch and hallway lights.

When the button is pressed, both lights turn ON. The porch light stays ON for 30 seconds, while the hallway light stays ON for 60 seconds.

## Modular Programming

I used separate functions for different parts of the lighting system.

`setup()` sets up the input and output pins and keeps both lights OFF when the program starts.

`turnLightsOn()` turns ON both the porch and hallway lights when the button is pressed.

`controlLights()` controls the timing of the lights. It turns the porch light OFF after 30 seconds and then turns the hallway light OFF after another 30 seconds.

Using separate functions makes the program easier to understand because each function has a specific job. It also makes it easier to change a particular part of the program without changing the whole program.

## Circuit

D2 → Push Button
D9 → Porch LED through resistor
D6 → Hallway LED through resistor
GND → Common ground

## Result

The system turns ON both lights when the button is pressed. The porch light switches OFF after 30 seconds, while the hallway light remains ON for 60 seconds before switching OFF.
