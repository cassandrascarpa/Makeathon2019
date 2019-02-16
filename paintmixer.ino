#include <Servo.h>

float cmy[3];
int index;
String inString = "";

boolean gotInput;

int cupRotationAngle;
int scale = 10;

Servo cyanCup;
Servo magentaCup;
Servo yellowCup;
Servo mixMotor;

void setup() {
  reset();
  Serial.begin(9600);
  cyanCup.attach(5);
  magentaCup.attach(6);
  yellowCup.attach(7);
  mixMotor.attach(8);
}

void reset() {
  index = 0;
  String inString = "";
  gotInput = false;
}

void mixPaints() {
  cyanCup.write(cupRotationAngle);
  delay(cmy[0]*scale);
  cyanCup.write(0);
  
  magentaCup.write(cupRotationAngle);
  delay(cmy[1]*scale);
  magentaCup.write(0);
  
  yellowCup.write(cupRotationAngle);
  delay(cmy[2]*scale);
  yellowCup.write(0);
}

void loop() {
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

  if(gotInput) {
    mixPaints();
    reset();
  }
}
