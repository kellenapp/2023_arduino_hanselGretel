const int buttonPin = 2;
byte arbitraryCode = 97;
int buttonState = 0;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}
 
void loop() {
   buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.write(arbitraryCode);
  } 
}

