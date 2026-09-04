#include <Wire.h>
#include <BH1750.h>

// Pins
const int PIR_PIN = 2;
const int BUTTON_PIN = 3;

const int LED1_PIN = 6;
const int LED2_PIN = 7;

// Light thresholds
const float DARK_THRESHOLD = 20.0;
const float BRIGHT_THRESHOLD = 40.0;

// BH1750 light sensor
BH1750 lightMeter;

// Interrupt flags
volatile bool motionDetected = false;
volatile bool buttonPressed = false;

// Light state
bool lightsOn = false;

// Manual control
bool manualOverride = false;

// Check light level every 500 ms
unsigned long lastLightCheck = 0;
const unsigned long LIGHT_CHECK_TIME = 500;


// PIR interrupt
void motionISR() {
  motionDetected = true;
}


// Button interrupt
void buttonISR() {
  buttonPressed = true;
}


// Turn both lights ON or OFF
void setLights(bool state) {

  lightsOn = state;

  if (state) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
  }
  else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }
}


void setup() {

  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  setLights(false);
  // PIR interrupt
  attachInterrupt(
    digitalPinToInterrupt(PIR_PIN),
    motionISR,
    RISING
  );
  // Slider/button interrupt
  attachInterrupt(
    digitalPinToInterrupt(BUTTON_PIN),
    buttonISR,
    FALLING
  );

  Serial.println("System ready.");
}


void loop() {

  // -------------------------
  // BUTTON / SLIDER EVENT
  // -------------------------

  if (buttonPressed) {

    buttonPressed = false;

    if (lightsOn) {

      setLights(false);
      manualOverride = false;

      Serial.println("Button pressed - Lights OFF.");

    }
    else {

      setLights(true);
      manualOverride = true;

      Serial.println("Button pressed - Manual override ON.");
      Serial.println("Lights ON.");
    }
  }
  // PIR MOTION EVENT
  if (motionDetected) {

    motionDetected = false;

    float lux = lightMeter.readLightLevel();

    Serial.print("Motion detected. Light level: ");
    Serial.print(lux);
    Serial.println(" lux.");

    // Only automatic control if manual override is OFF
    if (!manualOverride) {

      if (lux < DARK_THRESHOLD) {

        setLights(true);

        Serial.println("It is dark.");
        Serial.println("Lights turned ON automatically.");

      }
      else {

        Serial.println("It is bright.");
        Serial.println("Lights remain unchanged.");
      }
    }
  }
  // CHECK FOR BRIGHT LIGHT
  if (lightsOn &&
      !manualOverride &&
      millis() - lastLightCheck >= LIGHT_CHECK_TIME) {

    lastLightCheck = millis();

    float lux = lightMeter.readLightLevel();

    if (lux >= BRIGHT_THRESHOLD) {

      setLights(false);

      Serial.print("It is bright: ");
      Serial.print(lux);
      Serial.println(" lux.");

      Serial.println("Lights turned OFF automatically.");
    }
  }


  delay(50);
}
