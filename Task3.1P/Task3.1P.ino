// Task 3.1P - Create Trigger/Notification based on Sensor Data
// Name: Gaurav
// Roll No: 2510994818

#include <WiFiNINA.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <BH1750.h>

// WiFi credentials
const char* ssid = "iPhone";
const char* password = "nhibtaunga";

// MQTT broker running on PC
const char* mqttServer = "172.20.10.2";
const int mqttPort = 1883;

// MQTT topic used by Node-RED
const char* mqttTopic = "lightmqtt";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

BH1750 lightSensor;

// Light threshold
const float sunlightLimit = 50.0;

// Stores the current sunlight state
bool sunlight = false;

void connectWiFi()
{
  Serial.print("WiFi Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid, password);
    delay(5000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");

  Serial.print("Arduino IP: ");
  Serial.println(WiFi.localIP());
}

void connectMQTT()
{
  while (!mqttClient.connected())
  {
    Serial.println("MQTT Connecting");

    String clientID = "ArduinoTerrarium-" + String(random(1000, 9999));

    if (mqttClient.connect(clientID.c_str()))
    {
      Serial.println("MQTT connected");
    }
    else
    {
      Serial.print("MQTT connection failed, error: ");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  // Start BH1750 sensor
  if (lightSensor.begin())
  {
    Serial.println("BH1750 sensor started");
  }
  else
  {
    Serial.println("BH1750 sensor not found");

    while (true)
    {
      delay(1000);
    }
  }

  // Connect to WiFi
  connectWiFi();

  // Configure MQTT broker
  mqttClient.setServer(mqttServer, mqttPort);

  Serial.println("System ready");
}

void loop()
{
  // Reconnect WiFi if disconnected
  if (WiFi.status() != WL_CONNECTED)
  {
    connectWiFi();
  }

  // Reconnect MQTT if disconnected
  if (!mqttClient.connected())
  {
    connectMQTT();
  }

  mqttClient.loop();

  // Read light level
  float lux = lightSensor.readLightLevel();

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");

  // Sunlight detected
  if (lux >= sunlightLimit)
  {
    if (sunlight == false)
    {
      sunlight = true;

      Serial.println("Sunlight detected");

      mqttClient.publish(mqttTopic, "ON");
    }
  }

  // Sunlight stopped
  else
  {
    if (sunlight == true)
    {
      sunlight = false;

      Serial.println("Sunlight stopped");

      mqttClient.publish(mqttTopic, "OFF");
    }
  }

  delay(5000);
}
