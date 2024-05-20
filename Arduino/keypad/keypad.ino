#include <Keypad.h>
const byte ROWS = 4; // Define the number of rows on the keypad
const byte COLS = 3; // Define the number of columns on the keypad
char keys[ROWS][COLS] = { // Matrix defining character to return for each key
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pins (R0-R3) of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pins (C0-C2) of the keypad
//initialize an instance of class
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int buzzer = 0;
void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  char key = keypad.getKey();
  
  if (key){     // If key is pressed, send it to the Serial Monitor Window
    Serial.println(key);
  }
} 

  
 

 