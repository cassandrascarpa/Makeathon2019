float cmy[3];
int index;
String inString = "";

void setup() {
  Serial.begin(9600);
  index = 0;
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
  }

}
