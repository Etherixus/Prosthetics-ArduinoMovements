#include <Servo.h>
// Servos
Servo thumb;
Servo index;
Servo bird;
Servo ring;
Servo pinky;

// PINS FOR SERVOS
#define THUMB_PIN 1
#define INDEX_PIN 2
#define BIRD_PIN 3
#define RING_PIN 4
#define PINKY_PIN 5
#define SWITCH_PIN 12

// MAX VALUES FOR SERVOS
#define SERVO_MAX 180
#define THUMB_MAX 170
#define INDEX_MAX 170
#define BIRD_MAX 170
#define RING_MAX 110
#define PINKY_MAX 175

// MIN VALUES FOR SERVOS
#define SERVO_MIN 0
#define THUMB_MIN 45
#define INDEX_MIN 40
#define BIRD_MIN 40
#define RING_MIN 10
#define PINKY_MIN 25

// OTHER VALUES
#define OFFSET 30
#define DIFF_PORTION .2

// DELAYS
#define SAMPLE_NUM 1000
#define SAMPLE_DELAY 2
#define MOVE_DELAY 20

/*
 * Set up the environment
 */
void setup(){
  //Sets up the Servo Pins
  pinMode(SWITCH_PIN, INPUT);
  pinMode(THUMB_PIN, OUTPUT);
  pinMode(INDEX_PIN, OUTPUT);
  pinMode(BIRD_PIN, OUTPUT);
  pinMode(RING_PIN, OUTPUT);
  pinMode(PINKY_PIN, OUTPUT);
  //Assigns each servo to a pin
  thumb.attach(THUMB_PIN);
  index.attach(INDEX_PIN);
  bird.attach(BIRD_PIN);
  ring.attach(RING_PIN);
  pinky.attach(PINKY_PIN);
  thumb.write(THUMB_MIN);
  //Moving each servo to their default positions
  thumb.write(THUMB_MIN);
  index.write(INDEX_MIN);
  bird.write(BIRD_MIN);
  ring.write(RING_MIN);
  pinky.write(PINKY_MIN);
  //Pauses movement for .5 seconds
  delay(500);
}

/**
 * Opens the hand at a moderate pace
 */
void openHand(){
   for(int i = SERVO_MIN; i <= SERVO_MAX; ++i){
    if (i <= SERVO_MAX - OFFSET)    // moves the thumb for the first 150 cycles
      thumb.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX - OFFSET, THUMB_MIN, THUMB_MAX));
    if (i >= SERVO_MIN + OFFSET) {    // moves the other fingers for the last 150 cycles
      index.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, INDEX_MIN, INDEX_MAX));
      bird.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, BIRD_MIN, BIRD_MAX));
      ring.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, RING_MIN, RING_MAX));
      pinky.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, PINKY_MIN, PINKY_MAX));
    }
    delay(MOVE_DELAY); // in milliseconds
  }
}

/**
 * Closes the hand at a moderate pace.
 */
void closeHand() {
  for(int i = SERVO_MAX; i >= SERVO_MIN; --i){
    if (i <= SERVO_MAX - OFFSET)    // moves the thumb for the last 150 cycles
      thumb.write(map(i, SERVO_MIN, SERVO_MAX - OFFSET, THUMB_MIN, THUMB_MAX));
    if (i >= SERVO_MIN + OFFSET) {    // moves the other fingers for the first 150 cycles
      index.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, INDEX_MIN, INDEX_MAX));
      bird.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, BIRD_MIN, BIRD_MAX));
      ring.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, RING_MIN, RING_MAX));
      pinky.write(map(i, SERVO_MIN + OFFSET, SERVO_MAX, PINKY_MIN, PINKY_MAX));
    }
    delay(MOVE_DELAY); // in milliseconds
  }
}

/*
 * Loops through the hand functions 
 */
void loop() {
   while (digitalRead(SWITCH_PIN) == HIGH) {
    openHand();
    delay(2500);
    closeHand();
    delay(2500);
  }
}
