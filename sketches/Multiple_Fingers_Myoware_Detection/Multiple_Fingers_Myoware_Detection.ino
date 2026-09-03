int inputPin;
int baseMax;
int baseMin;
int fistMax;
int fistMin;
int indeMax;
int indexMin;
void setup() {
  inputPin = 2;
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(inputPin));

  delay(100);
}