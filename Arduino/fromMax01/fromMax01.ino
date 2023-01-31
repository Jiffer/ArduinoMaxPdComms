/*
Receieves numbers over serial port 
used to determine what pin to enable and PWM value

use with maxToArduino, fromPd

*/

int output1 = 11;       // the pin number


void setup() {
  // set the digital pins as output:

  pinMode(output1, OUTPUT);
  analogWrite(output1, 10);

  // initialize serial port
  Serial.begin(115200);
  Serial.flush();
}

void loop() {
  // check for serial data:
  if (Serial.available()) {
    int val = Serial.read();

    analogWrite(output1, val);
  }
}
