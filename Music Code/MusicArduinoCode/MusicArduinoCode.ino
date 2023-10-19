const int buttonPin = 2;
byte arbitraryCode = 97;
int buttonState = 0;
#include <Servo.h>
//servo library 

//flex sensor connection
#define fsrpin A0

//first servo for kids
Servo hanselGretel;

//second servo for the cake
Servo cake;

//oven lights
int redPin = 4;

//reset button on breadboard for us
int resetButton = 2;

//start button needed

//servo position
int pos = 0;

//boolean to check whether the oven door has been closed
bool doorClosed = false;

//integer to take in the pressure noted on the sensor
int fsrreading;

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

