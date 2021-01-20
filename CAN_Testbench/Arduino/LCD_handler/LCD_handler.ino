#include <LiquidCrystal.h>

#define LCD_RS 12
#define LCD_EN 11

// lcd display variable (RS, EN, data pins 4,5,6,7)
LiquidCrystal lcd(LCD_RS, LCD_EN, 3, 4, 5, 6);

void setup() {
  //initialize lcd and specify dimensions
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop() {
  lcd.print("ya");
  lcd.setCursor(1, 5);
  lcd.print("yeet");
  Serial.println("ya");
  Serial.println("yeet");
  delay(3000);
  lcd.home();
  delay(3000);
  lcd.clear();
  delay(500);
}
