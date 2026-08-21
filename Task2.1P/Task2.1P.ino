 // Task 2.1P - Sending Temperature and Light Data to the Web
// gaurav nautiyal
//2510994807
#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <BH1750.h>
#include <Wire.h>

// Wi-Fi credentials
const char* WIFI_NAME = "iPhone";
const char* WIFI_PASSWORD = "nhibtaunga";

// ThingSpeak details
unsigned long CHANNEL_ID = 3464875;
const char* API_KEY = "NVIWYHIWXKST7F0J";

#define DHT_PIN 8
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);
BH1750 lightSensor;
WiFiClient client;

void setup() {
    Serial.begin(115200);

    dht.begin();
    Wire.begin();
    lightSensor.begin();

    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("WiFi module not found");
        while (true);
    }

    // Connect to WiFi
    Serial.print("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
        delay(3000);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");

    ThingSpeak.begin(client);
}

void loop() {

    // Read sensor values
    float temperature = dht.readTemperature();
   
    float light = lightSensor.readLightLevel();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    

    Serial.print("Light: ");
    Serial.print(light);
    Serial.println(" lux");

    // Check sensor readings
    if (isnan(temperature) ||  isnan(light)) {
        Serial.println("Sensor error");
    }
    else {
        // Send data to ThingSpeak
        ThingSpeak.setField(1, temperature);
      
        ThingSpeak.setField(2, light);

        int result = ThingSpeak.writeFields(CHANNEL_ID, API_KEY);

        if (result == 200) {
            Serial.println("Data sent successfully!");
        }
        else {
            Serial.println("Failed to send data");
        }
    }

    delay(30000);
}
