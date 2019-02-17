#include <Servo.h>

float cmy[3];
int index;
String inString = "";

boolean gotInput;
boolean canReadSerial;

int cupRotationAngle = 180;
int scale = 1000;

int motor = 4;

Servo cyanCup;
Servo magentaCup;
//Servo yellowCup;
//Servo mixMotor;

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  reset();
  cyanCup.attach(5);
  magentaCup.attach(7);
  //yellowCup.attach(7);
 // mixMotor.attach(8);
}

void reset() {
  index = 0;
  String inString = "";
  gotInput = false;
  canReadSerial = true;
}

void dispensePaints() {
  
  cyanCup.write(cupRotationAngle);
  delay(cmy[0]*scale);
  cyanCup.write(90);
  
  delay(1000);
  
  magentaCup.write(cupRotationAngle);
  delay(cmy[1]*scale);
  magentaCup.write(90);
  /*
  yellowCup.write(cupRotationAngle);
  delay(cmy[2]*scale);
  yellowCup.write(0);*/

  delay(1000);
}

void mix() {
  digitalWrite(motor, HIGH);
  delay(5000);
  digitalWrite(motor, LOW);
}

void loop() {
  if (canReadSerial) {
  while (Serial.available() > 0) {
    int inChar = Serial.read();

    if (inChar != ',') {
      inString += (char) inChar;
    }
    else {
      cmy[index] = inString.toFloat();
      inString = "";
      index += 1;
    }
    gotInput = true;
  }
  }

  if(gotInput) {
    canReadSerial = false;
    dispensePaints();
    mix();
    reset();
  }
}
