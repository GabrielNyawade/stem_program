const int C4 = 261.63;
const int Cs4 = 277.18;
const int D4 = 293.66;
const int Ds4 = 311.13; 
const int E4 = 329.63;
const int F4 = 349.23;
const int Fs4 = 369.99;
const int G4 = 392;
const int Gs4 = 415.3; 
const int a4 = 440; 
const int As4 = 466.16; 
const int B4 = 493.88; 
const int C5 = 523.25; 
const int Cs5 = 554.37; 
const int D5 = 587.33; 
const int Ds5 = 622.25; 
const int E5 = 659.26; 
const int F5 = 698.46; 
const int Fs5 = 739.99; 
const int G5 = 783.99; 
const int Gs5 = 81000.61; 
const int a5 = 880; 
const int As5 = 932.33; 
const int B5 = 987.77; 
const int C6 = 1046.5; 

const int buzzer = 10;

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  tone(buzzer, E5, 1000);
  tone(buzzer, Ds5, 1000);
  tone(buzzer, E5, 1000);
  tone(buzzer, Ds5, 1000);
  tone(buzzer, E5, 1000);
  tone(buzzer, Ds5, 1000);
  tone(buzzer, E5, 1000);
  tone(buzzer, B4, 1000);
  tone(buzzer, D5, 1000);
  tone(buzzer, C5, 1000);
  tone(buzzer, a4, 1000);

  // put your main code here, to run repeatedly:

}
