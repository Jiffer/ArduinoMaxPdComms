// reads and sends value for one analog input and one
// digital (button/switch) input to the serial port
// Uses an internal pullup on pin 2


// button variables
int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

// analog input variables
int analogPin = A0;
int analogValue;

// for updateInterval timer:
unsigned long updateInterval = 10; // how often to read pins and send over serial (in ms)
unsigned long lastUpdate = 0;
int now; 


void setup() {
  // configure pins as inputs / outputs as needed
  pinMode(buttonPin, INPUT_PULLUP);

  // start the serial port communications
  Serial.begin(115200);
}

void loop() {

  now = millis();
  // update if updateInterval has been exceeded
  if (now > lastUpdate + updateInterval) {
    lastUpdate = now;

    // read pins
    buttonState = digitalRead(buttonPin);
    analogValue = analogRead(analogPin);

    // send values over serial connection
    // print button value
    Serial.print(buttonState);
    // sepereate values with a space
    Serial.print(" ");
    // print analog value
    Serial.print(analogValue);

    // send a new line at the end of the list
    Serial.println();
  }
}
