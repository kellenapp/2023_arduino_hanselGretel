import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;
Minim minim;
AudioPlayer player;
byte arbitraryCode = 97;
byte saved = 68;
 
void setup()
{
  // In the next line, you'll need to change this based on your USB port name
  myPort = new Serial(this, "COM4", 9600);
  minim = new Minim(this);
  // Put in the name of your sound file below, and make sure it is in the same directory
  player = minim.loadFile("Intro.wav");
}
 
void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == arbitraryCode) {
      player.rewind();
      player.play();
    }
}
}
