# SIT210 Task 2.1P - Sending Temperature and Light Data to the Web

## Overview

This project is part of SIT210 Embedded Systems Development. The aim of this task is to collect temperature and light data using an Arduino Nano 33 IoT and send the readings to the web using ThingSpeak.

The system is designed for Linda's assisted living scenario, where environmental conditions such as room temperature and light levels need to be monitored.

## Hardware Used

* Arduino Nano 33 IoT
* DHT22 Temperature and Humidity Sensor
* BH1750 Light Sensor
* Breadboard
* Jumper wires

## Software and Libraries

* Arduino IDE
* WiFiNINA library
* ThingSpeak library
* DHT library
* BH1750 library
* Wire library

## Sensors

The DHT22 sensor is used to measure the room temperature.

The BH1750 sensor is used to measure the light intensity in the room in lux.

## ThingSpeak

The sensor readings are sent to a ThingSpeak channel using Wi-Fi.

* Field 1: Temperature
* Field 2: Light Intensity

The Arduino sends updated sensor readings to ThingSpeak every 30 seconds.

## Webhook Understanding

Webhooks allow one system to automatically send information to another system when an event occurs. In this project, the Arduino collects new sensor readings and sends the temperature and light data to ThingSpeak over Wi-Fi.

The ThingSpeak functions in the Arduino code are responsible for sending the sensor data to the web. The `ThingSpeak.setField()` functions assign the sensor readings to the ThingSpeak fields, while `ThingSpeak.writeFields()` sends the data to the ThingSpeak channel.

## Project Images

### Circuit

![Circuit](Circuit.jpeg)

### Circuit Diagram

![Circuit Diagram](Wikwo_circuit.png)

### Light Intensity

![Light Intensity](Light_intensity.png)

### Temperature and Humidity

![Temperature and Humidity](Temprature_and_humidity.png)

## Main Code

The main Arduino program is:

`TASK2.1P_Webhooks.ino`

The program connects the Arduino to Wi-Fi, reads the temperature and light sensor values, and sends the readings to ThingSpeak every 30 seconds.
