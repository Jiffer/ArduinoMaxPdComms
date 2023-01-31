/* 
  Send a random number between 0 : 127 every time button on pin 2 is pressed (active low)
*/

int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  // start the serial port communications
  Serial.begin(115200);

}

void loop() {
  

  buttonState = digitalRead(buttonPin);
  // check if the button state has changed from the last time through the loop
  if(buttonState != lastButtonState){
    if(buttonState == LOW){
      // generate a random number
      int randValue = random(128);
      Serial.println(randValue);
    }
    else{
      // don't do anything on button release
    }
    delay(20);
  }

  lastButtonState = buttonState;

}
