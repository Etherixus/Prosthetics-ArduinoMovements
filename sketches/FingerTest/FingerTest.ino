#include <Servo.h>
Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(160);
  delay(2500);
  servo.write(30);
  delay(2500);
}
