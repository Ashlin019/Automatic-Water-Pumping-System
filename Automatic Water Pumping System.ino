#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


long duration, inches;
int set_val, percentage;
bool state, pump;


void setup() {


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("WATER LEVEL SYSTEM");
  display.display();
  delay(1200);


  pinMode(2, OUTPUT);       // Trigger
  pinMode(3, INPUT);        // Echo
  pinMode(10, INPUT_PULLUP); // Button
  pinMode(11, INPUT_PULLUP); // Mode switch
  pinMode(13, OUTPUT);       // Pump relay


  set_val = EEPROM.read(0);
  if (set_val > 20) set_val = 20;
}


void loop() {


  // 1️⃣ ULTRASONIC READ
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);


  duration = pulseIn(3, HIGH);
  inches = microsecondsToInches(duration);


  // 2️⃣ WATER PERCENT FORMULA
  percentage = (set_val - inches) * 110 / set_val;
  if (percentage < 0) percentage = 0;
  if (percentage > 100) percentage = 100;


  // 3️⃣ AUTO MODE PUMP CONTROL
  if (digitalRead(11)) {
    if (percentage < 30) pump = 1;
    if (percentage > 85) pump = 0;
  }
  digitalWrite(13, !pump);


  // 4️⃣ BUTTON BEHAVIOR (EEPROM + MANUAL TOGGLE)
  if (!digitalRead(10) && !state) {
    state = true;


    if (digitalRead(11)) {
      set_val = inches;
      EEPROM.write(0, set_val);
    } else {
      pump = !pump;
    }
  }
  if (digitalRead(10)) state = false;


  // 5️⃣ OLED DISPLAY
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("LEVEL: ");
  display.print(percentage);
  display.println("%");


  display.print("PUMP : ");
  if (pump) display.println("ON");
  else display.println("OFF");


  display.print("MODE : ");
  if (digitalRead(11))
    display.println("AUTO");
  else
    display.println("MANUAL");


  display.setCursor(0, 40);
  display.print("SET VAL: ");
  display.print(set_val);
  display.print(" in");


  display.display();


  delay(500);
}


long microsecondsToInches(long microseconds) {
  return microseconds / 29 / 2;
}
