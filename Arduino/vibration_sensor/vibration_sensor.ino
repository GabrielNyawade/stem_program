#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS 9
#define TFT_RST 7
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const uint16_t Display_Color_Black = 0x0000;
const uint16_t Display_Color_Blue = 0x001F;
const uint16_t Display_Color_Red = 0xF800;
const uint16_t Display_Color_Green = 0x07E0;
const uint16_t Display_Color_Cyan = 0x07FF;
const uint16_t Display_Color_Magenta = 0xF81F;
const uint16_t Display_Color_Yellow = 0xFFE0;
const uint16_t Display_Color_White = 0xFFFF;

uint16_t Display_Text_Color = Display_Color_Black;
uint16_t Display_Backround_Color = Display_Color_White;

bool isDisplayVisible = false;
const size_t data_size = 16;
char data[data_size] = { 0 };

int analogpin = 0; // define analog OUT signal pin
int analog; // define variable to store value read from pin
int digitalpin = 2; // define digital OUT signal pin
int digital; // define variable to store value read from pin
  

void display_data(char* data) {
  tft.setCursor(0, 0);
  tft.setTextColor(Display_Backround_Color);
  tft.print("Hello");
}

void setup() {
  pinMode(analogpin, INPUT); // set the OUT signal pin as an input
  pinMode(digitalpin, INPUT); // set the OUT signal pin as

  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  tft.setRotation(1);


  // initialise the display
  tft.setFont();
  tft.fillScreen(Display_Backround_Color);
  tft.setTextColor(Display_Text_Color);
  tft.setTextSize(2);
  isDisplayVisible = true;

}

void loop() {
  delay(100);
  analog = analogRead(analogpin);  // read the voltage level on the A0
  digital = digitalRead(digitalpin);  // 

tft.fillScreen(Display_Backround_Color);
tft.setCursor(0, 0);
tft.print("Analog :");
tft.print(analog);
tft.print("\n");
tft.print("Digital:");
tft.print(digital);
}
  