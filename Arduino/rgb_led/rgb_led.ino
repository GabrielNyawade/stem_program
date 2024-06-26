/*
    ARDUINO RGB LED TUTORIAL: RAINBOW COLOR
    By: TheGeekPub.com
    More Arduino Tutorials: https://www.thegeekpub.com/arduino-tutorials/
*/
 
const int PIN_RED   = 5; 
const int PIN_GREEN = 6; 
const int PIN_BLUE  = 7; 

const int buzzer = 2;
 
//variables to hold our color intensities and direction
//and define some initial "random" values to seed it
/* This function "Set Color" will set the color of the LED
   rather than doing it over and over in the loop above. */
void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}
 
void setup() {
  //set all three pins to output mode
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  pinMode(buzzer, OUTPUT);
}

int time = 500;
int sec = 0;
void loop() {
  sec = sec + 1;
  if (time > 2) {
    setColor(255, 0, 0);
    digitalWrite(buzzer, HIGH);
    delay(time/sec);
    setColor(0, 0, 0);
    digitalWrite(buzzer, LOW);
    delay(time/sec);
  }
  else {
    setColor(0, 0, 0);
  }

}