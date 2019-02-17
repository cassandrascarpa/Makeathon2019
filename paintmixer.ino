#include <Servo.h>

float cmy[3];
int index = 0;
String inString = "";

boolean gotInput = false;
boolean canReadSerial = true;

int scale = 1000;

int pos;

Servo cyanCup;
Servo magentaCup;
Servo yellowCup;
Servo mixMotor;

int cyanStart = 90;
int magentaStart = 180;
int yellowStart = 90;

void setup() {
  Serial.begin(9600);
  
  cyanCup.attach(5);
  cyanCup.write(cyanStart);
  delay(100);
  cyanCup.detach();
  
  magentaCup.attach(6);
  magentaCup.write(magentaStart);
  delay(100);
  magentaCup.detach();
  
  yellowCup.attach(7);
  yellowCup.write(yellowStart);
  delay(100);
  yellowCup.detach();
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
  cyanCup.write(cyanStart);
  delay(100);
  cyanCup.detach();
  
  delay(1000);

  magentaCup.attach(6);
  magentaCup.write(90);
  delay(cmy[1]*scale);
  magentaCup.write(magentaStart);
  delay(100);
  magentaCup.detach();

  delay(1000);

  yellowCup.attach(7);
  yellowCup.write(0);
  delay(cmy[2]*scale);
  yellowCup.write(yellowStart);
  delay(100);
  yellowCup.detach();

  delay(1000);
}

void mix() {
  mixMotor.attach(4);
  for (pos = 0; pos <= 180; pos += 1) { 
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
    reset();
  }
}
