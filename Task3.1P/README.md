# Task 3.1P - Create Trigger/Notification based on Sensor Data

## Description

This task uses a BH1750 light sensor connected to an Arduino Nano 33 IoT.
The Arduino reads the light level and sends an MQTT message when the
sunlight condition changes.

## Components

- Arduino Nano 33 IoT
- BH1750 light sensor
- Wi-Fi
- MQTT
- Node-RED

## MQTT Configuration

- MQTT Broker: 172.20.10.2
- Port: 1883
- Topic: lightmqtt

## Trigger

When the light level is 50 lux or above, the Arduino sends:

ON

When the light level falls below 50 lux, the Arduino sends:

OFF

Node-RED receives these messages and sends an email notification.

## Result

The BH1750 successfully detects changes in light intensity.
The Arduino publishes ON and OFF messages through MQTT, and Node-RED
uses these messages to trigger email notifications.
