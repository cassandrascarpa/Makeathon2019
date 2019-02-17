#include <Servo.h>

float cmy[3];
int index;
String inString = "";

boolean gotInput;
boolean canReadSerial;

int scale = 1000;

int pos;

Servo cyanCup;
Servo magentaCup;
Servo yellowCup;
Servo mixMotor;

void setup() {
  Serial.begin(9600);
  reset();
  cyanCup.attach(5);
  cyanCup.write(90);
  delay(100);
  cyanCup.detach();
  magentaCup.attach(6);
   magentaCup.write(180);
   delay(100);
   magentaCup.detach();
  yellowCup.attach(7);
  yellowCup.write(90);
  delay(100);
  yellowCup.detach();
  mixMotor.attach(4);
   mixMotor.write(90);
   delay(100);
   mixMotor.detach();
}

void reset() {
  mix();
  index = 0;
  String inString = "";
  gotInput = false;
  canReadSerial = true;
}

void dispensePaints() {

  cyanCup.attach(5);
  cyanCup.write(0);
  delay(cmy[0]*scale);
  cyanCup.write(90);
  delay(100);
  cyanCup.detach();
  
  delay(1000);

  magentaCup.attach(6);
  magentaCup.write(90);
  delay(cmy[1]*scale);
  magentaCup.write(180);
  delay(100);
  magentaCup.detach();

  delay(1000);

  yellowCup.attach(7);
  yellowCup.write(0);
  delay(cmy[2]*scale);
  yellowCup.write(90);
  delay(100);
  yellowCup.detach();

  delay(1000);
}

void mix() {
  mixMotor.attach(4);
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    mixMotor.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    mixMotor.write(pos);              
    delay(15);                       
  }
  mixMotor.detach();
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
    delay(2000);
    /*mix();*/
    reset();
  }
}
