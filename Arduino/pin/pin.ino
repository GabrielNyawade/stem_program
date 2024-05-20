#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buzzer = 10;

// LiquidCrystal(uint8_t rs, uint8_t enable,
//		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 3;
byte rowPins[KEYPAD_ROWS] = {8, 7, 6, 9};
byte colPins[KEYPAD_COLS] = {A0, A1, A2};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

void showStartupMessage() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  delay(1000);

  lcd.setCursor(0, 2);
  String message = "Input PIN";
  for (byte i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(100);
  }
  delay(500);
}

String inputSecretCode() {
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("[____]");
  lcd.setCursor(6, 1);
  String result = "";
  while (result.length() < 4) {
    char key = keypad.getKey();
    if (key >= '0' && key <= '9') {
      tone(buzzer, 440, 30);
      lcd.print('*');
      result += key;
    }
  }
  return result;
}

void showUnlockMessage() {
  lcd.clear();
  lcd.setCursor(4, 0);
  delay(500);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(30);
  lcd.print("Unlocked!");
  delay(1000);
}
void showLockMessage() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Locked!");

  //buzz continously
  tone(buzzer, 880);
}


void setup() {
  lcd.begin(16, 2);
  showStartupMessage();
  pinMode(buzzer, OUTPUT);
}

void loop() {
 if(inputSecretCode()=="1234")
 {
  showUnlockMessage(); 
 }
 else
 {
   showLockMessage();
 }
}