#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int button = 13;

void message(){
  lcd.setCursor(0, 0);
  String message = "Dear mum,I love u so much<3";
  for (byte i = 0; i < message.length(); i++){
    if (i < 16) {
      lcd.print(message[i]);
      delay(200);
    }
    else {
      int j = i - 16;
      lcd.setCursor(j, 1);
      lcd.print(message[i]);
      delay(200);
    }
  }
  delay(1000);
  lcd.clear();
}

void setup() {
  lcd.begin(16, 2);
  pinMode(button, INPUT);

}

void loop() {
  if (digitalRead(button) == HIGH){
    message();
  }
  else{
    lcd.print("");
  }

}
