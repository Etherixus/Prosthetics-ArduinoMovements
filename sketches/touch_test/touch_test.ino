const int SENSOR_PIN = 2; // Fabric connected here
int lastState = HIGH;     // Start HIGH because of INPUT_PULLUP

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);  // Internal pull-up resistor
  pinMode(LED_BUILTIN, OUTPUT);       // Built-in LED for feedback
  Serial.begin(115200);
  Serial.println("Touch test ready: Touch fabric to GND to trigger");
}

void loop() {
  double currentState = analogRead(SENSOR_PIN);
  if (currentState>229 && currentState < 255){ 
    Serial.print("Touch");
  }
  Serial.println(currentState);
  delay(1000);
  }
