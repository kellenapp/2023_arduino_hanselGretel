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
//int resetButton = 2;

//start button on breadboard
int startButton = 3;

//servo position
int pos = 0;

//boolean to check whether the oven door has been closed
bool doorClosed = false;

//integer to take in the pressure noted on the sensor
int fsrreading;

void setup() {
  pinMode(redPin, OUTPUT);
  //pinMode(resetButton, INPUT_PULLUP);
  pinMode(startButton , INPUT_PULLUP);
  hanselGretel.attach(9);
  hanselGretel.write(0);
  cake.write(0);
  cake.attach(11);  // attaches the servo on pin 11 to the servo object
}

void loop() {

  doorClosed = false;
  fsrreading = analogRead(fsrpin);
  //byte buttonState = digitalRead(resetButton);
  //reset button moves everything back to original place

  byte startState = digitalRead(startButton);

  //if the button has been pressed
  if(startState == HIGH){
    //start the program


      fsrreading = analogRead(fsrpin); 
      //hansel and gretel begin to move towards the oven
      for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees

      
        fsrreading = analogRead(fsrpin);
        //check if oven door is closed
        if(fsrreading > 40){
          digitalWrite(redPin, HIGH);
          doorClosed = true;
          break;
        }

        // in steps of 1 degree
        // cake.write(pos);
        // delay(10);
        hanselGretel.write(pos); 
        delay(50);               

        
                
      }

      //if door WAS closed
      if(doorClosed){

        digitalWrite(redPin, LOW);
          //if loop has been broken, bring hansel and Gretel back to their original position
          for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
            //cake.write(pos);
            hanselGretel.write(pos);              // tell servo to go to position in variable 'pos'
            delay(20);                       // waits 30ms for the servo to reach the position
          }
      }
      //door did not close...
      else{
        digitalWrite(redPin, HIGH);
        //move cake out from the oven
        for (pos = 0; pos <= 90; pos += 1) {
          cake.write(pos);
          delay(30); //the speed of the movement
        }

      }
    
  }
  else{
    //do nothing if button hasn't been pressed yet
    loop();
    
  }

  
  //reset bool
  

  //pressure sensor reading
  

 // if(buttonState == LOW){
    //button is pressed and the servo motor begins to run

    //for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    //cake.write(pos);
    //hanselGretel.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(30);                       // waits 30ms for the servo to reach the position
  //}
  
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