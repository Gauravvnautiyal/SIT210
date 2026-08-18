// Embedded Systems Development Task 1.1P
// Gaurav Nautiyal
// 2510994807

const int porchLight = 9;
const int hallwayLight = 6;
const int lightSwitch = 2;

// Function to setup the pins
void setup()
{
  pinMode(porchLight, OUTPUT);
  pinMode(hallwayLight, OUTPUT);
  pinMode(lightSwitch, INPUT_PULLUP);

  // At the initial point both lights are off
  digitalWrite(porchLight, LOW);
  digitalWrite(hallwayLight, LOW);
}

void loop()
{
  if (digitalRead(lightSwitch) == LOW)
  {
    turnLightsOn();
    controlLights();
  }
}

// Turns both lights ON
void turnLightsOn()
{
  digitalWrite(porchLight, HIGH);
  digitalWrite(hallwayLight, HIGH);
}

// Controls how long each light stays ON
void controlLights()
{
  // Porch light stays ON for 30 seconds
  delay(30000);

  // Turn OFF porch light
  digitalWrite(porchLight, LOW);

  // Hallway light stays ON for another 30 seconds
  delay(30000);

  // Turn OFF hallway light
  digitalWrite(hallwayLight, LOW);
}
