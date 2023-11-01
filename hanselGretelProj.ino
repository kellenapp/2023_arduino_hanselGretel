#include <Servo.h>
//servo library 

//hall sensor connection
#define hallSensorPin A0

//first servo for kids
Servo hanselGretel;

//second servo for the cake
Servo cake;

//hall sensor reading
int hallReading;

//oven lights
int redPin = 4;

//start button on breadboard
int startButton = 3;

//servo position
int pos = 0;

//hansel/gretel pos
int hgPos = 0;

//cake position
int cakePos = 0;

//boolean to check whether the oven door has been closed
bool doorClosed = false;

//integer to take in the pressure noted on the sensor
int fsrreading;

void setup() {
  pinMode(redPin, OUTPUT);
  //pinMode(resetButton, INPUT_PULLUP);
  pinMode(startButton , INPUT_PULLUP);
  pinMode(hallSensorPin, INPUT);
  hanselGretel.attach(9);
  hanselGretel.write(0);
  cake.write(0);
  cake.attach(11);  // attaches the servo on pin 11 to the servo object
  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();

  doorClosed = false;
  //fsrreading = analogRead(fsrpin);
  //Serial.println("pressure at: " + fsrreading);
  

  hallReading = digitalRead(hallSensorPin);
  Serial.println(hallReading);
  
  
  
  //byte buttonState = digitalRead(resetButton);
  //reset button moves everything back to original place

  byte startState = digitalRead(startButton);
  //Serial.println(startState);
  

  //if the button has been pressed
  if(startState == HIGH){
    //start the program
    //Serial.print(pos);

       
      //hansel and gretel begin to move towards the oven
      //Serial.println("pressure at: " + fsrreading);
      for (hgPos = 0; hgPos <= 50; hgPos += 1) { // goes from 0 degrees to 90 degrees
      
        hallReading = digitalRead(hallSensorPin);
        Serial.println(hallReading);
        //check if oven door is closed
        if(hallReading == 0){
          //Serial.println("pressure at: " + fsrreading);
          Serial.println("stop hansel and gretel" + pos);
          digitalWrite(redPin, LOW);
          doorClosed = true;
          break;
        }
        
        //Serial.println("hansel/gretel pos: " + pos);
        hanselGretel.write(hgPos); 
        delay(50);  
        

        // in steps of 1 degree
        // cake.write(pos);
        // delay(10);
            
        //millis(50);                 
      }

      //if door WAS closed
      if(doorClosed == true){

        digitalWrite(redPin, LOW);
          //if loop has been broken, bring hansel and Gretel back to their original position
          for (pos = hgPos; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
            //cake.write(pos);
            hanselGretel.write(pos);              // tell servo to go to position in variable 'pos'
            //millis(20);                         //better option than a delay
            delay(50);                       // waits 30ms for the servo to reach the position

          }
      }
      //door did not close...
      if(doorClosed == false){
        
        digitalWrite(redPin, HIGH);
        delay(4000);
        digitalWrite(redPin, LOW);
        //move cake out from the oven
        for (cakePos = 0; cakePos <= 50; cakePos += 1) {
          cake.write(cakePos);
          //millis(30);
          delay(50); //the speed of the movement
        }

      }
      //resetting the servos back to start
      for (pos = hgPos; pos >= 0; pos -= 1) {
            
            hanselGretel.write(pos);
            cake.write(pos);              
            delay(50);                       
      }
  }
  else{
    //do nothing if button hasn't been pressed yet
    
    
  }

  
}