const byte PIN = 2;

void setup() {
  pinMode(PIN, INPUT_PULLUP);      // default HIGH via internal pull-up
  pinMode(LED_BUILTIN, OUTPUT);    // onboard LED
  Serial.begin(115200);
  Serial.println("Ready: touch D2 to GND to trigger LOW");
}

void loop() {
  int v = digitalRead(PIN);        // HIGH when floating, LOW when grounded
  digitalWrite(LED_BUILTIN, v ? LOW : HIGH);  // LED on when pin is LOW
  static int last = -1;
  if (v != last) {
    Serial.println(v ? "PIN=HIGH (released)" : "PIN=LOW (GND)");
    last = v;
  }
  delay(10);
}
