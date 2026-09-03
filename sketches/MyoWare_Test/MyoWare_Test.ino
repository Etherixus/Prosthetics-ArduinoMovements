int sensorValue;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // Read MyoWare signal
  sensorValue = analogRead(A4);

  // Print value to Serial Monitor
  Serial.println(sensorValue);

  delay(10);  // small delay for stability (~500 Hz)
}
