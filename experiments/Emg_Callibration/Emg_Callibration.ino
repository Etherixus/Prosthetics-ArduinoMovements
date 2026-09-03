int handOpen;
int handClosed;
bool hOpen;
bool hClosed;

int thumbOpen;
int thumbClosed;
bool tOpen;
bool tClosed;

int indexOpen;
int indexClosed;
bool iOpen;
bool iClosed;

const int handSensor = A0;
const int indexSensor = A2;
const int thumbSensor = A4;


Servo servo;
void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorValue = analog.Read(sensorPin);
  int indexSensor = analog.Read()
  calibrateHand();
  calibrateThumb();
  calubrateIndex();
  servo.write(map());

}

void calibrateHand(){
   if(hClosed == false){
    Serial.println("Make a fist with your hand for 5 seconds");
    delay(500);
    handClosed = sensorValue;
    hClosed = true;
  }
  if(hOpen == false){
    Serial.println("Open your hand wide for 5 seconds");
    delay(500);
    handOpen = sensorValue;
    hOpen = true;
  }
}

void calibrateThumb(){
   if(tClosed == false){
    Serial.println("Make a fist with your hand for 5 seconds");
    delay(500);
    thumbClosed = sensorValue;
    tClosed = true;
  }
  if(tOpen == false){
    Serial.println("Open your hand wide for 5 seconds");
    delay(500);
    thumbOpen = sensorValue;
    tOpen = true;
  }
}

void calibrateIndex(){
   if(iClosed == false){
    Serial.println("Make a fist with your hand for 5 seconds");
    delay(500);
    indecClosed = sensorValue;
    iClosed = true;
  }
  if(open == false){
    Serial.println("Open your hand wide for 5 seconds");
    delay(500);
    indexOpen = sensorValue;
    iOpen = true;
  }
}



