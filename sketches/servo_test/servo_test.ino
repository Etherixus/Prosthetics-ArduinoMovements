#include <Servo.h>

Servo servoMotor;
int servoPin = 7;

int stopValue = 90;   // You will tune this!

void setup() {
  Serial.begin(9600);
  servoMotor.attach(servoPin);

  Serial.println("=== Continuous Servo Experiment ===");
  Serial.println("Commands:");
  Serial.println("s = stop");
  Serial.println("f = slow forward");
  Serial.println("F = fast forward");
  Serial.println("r = slow reverse");
  Serial.println("R = fast reverse");
  Serial.println("+ = increase stop value");
  Serial.println("- = decrease stop value");
  Serial.println("");
  
  servoMotor.write(stopValue);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 's') {
      servoMotor.write(stopValue);
      Serial.println("STOP");
    }

    if (cmd == 'f') {
      servoMotor.write(stopValue + 10);
      Serial.println("Slow Forward");
    }

    if (cmd == 'F') {
      servoMotor.write(stopValue + 30);
      Serial.println("Fast Forward");
    }

    if (cmd == 'r') {
      servoMotor.write(stopValue - 10);
      Serial.println("Slow Reverse");
    }

    if (cmd == 'R') {
      servoMotor.write(stopValue - 50);
      Serial.println("Fast Reverse");
    }

    // Calibration controls
    if (cmd == '+') {
      stopValue++;
      servoMotor.write(stopValue);
      Serial.print("Stop value now: ");
      Serial.println(stopValue);
    }

    if (cmd == '-') {
      stopValue--;
      servoMotor.write(stopValue);
      Serial.print("Stop value now: ");
      Serial.println(stopValue);
    }
  }
}