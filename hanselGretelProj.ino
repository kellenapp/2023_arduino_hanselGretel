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
  pinMode(redPin, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP);
  hanselGretel.attach(9);
  cake.attach(11);  // attaches the servo on pin 11 to the servo object
}

void loop() {
 
  fsrreading = analogRead(fsrpin);
  byte buttonState = digitalRead(resetButton);
  //reset button moves everything back to original place

  if(fsrreading > 0){
    digitalWrite(redPin, HIGH); // turn the red light on
    delay(3000); // wait 3 sec
    digitalWrite(redPin, LOW);
  }

 // if(buttonState == LOW){
    //button is pressed and the servo motor begins to run

    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    cake.write(pos);
    hanselGretel.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
  
 // }
  
  
  //Now pressure sensor to check if there is obstruction
    //if yes, hanselGretel move back, cake doesn't move, and lights off
    //else, cake begans to move and hanselGretel stays hidden, and lights in oven turn on 
  //delay(5000);
 // for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
   // cake.write(pos);
    //hanselGretel.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(30);                       // waits 30ms for the servo to reach the position
  //}
  //delay(5000);

}