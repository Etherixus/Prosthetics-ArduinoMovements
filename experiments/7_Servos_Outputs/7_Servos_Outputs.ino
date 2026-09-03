//Program intended to test power supply to be able to power 7 servos at once
#include <Servo.h>
// Defining servo pins
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7
//Initializing servo variables
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Setting servo pin numbers to output
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin7, OUTPUT);
  //Assigning each servo to a pin number
  s1.attach(Pin1);
  s2.attach(Pin2);
  s3.attach(Pin3);
  s4.attach(Pin4);
  s5.attach(Pin5);
  s6.attach(Pin6);
  s7.attach(Pin7);
  //Setting each servo to 0 degrees
  s1.write(0);
  s2.write(0);
  s3.write(0);
  s4.write(0);
  s5.write(0);
  s6.write(0);
  s7.write(0);
}

void loop() {
 s7.write();

}
