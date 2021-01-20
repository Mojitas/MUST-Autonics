
/*
  Read/write to SD card
  Transmit/receive CANbus
  Output to LCD/UART

*/

//LCD library
#include <LiquidCrystal.h>

//CAN Read Demo libraries
#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

//Define pins
#define LCD_RS 12
#define LCD_EN 11

// lcd display variable (RS, EN, data pins 4,5,6,7)
//LiquidCrystal lcd(LCD_RS, LCD_EN, 3, 4, 5, 6);

void setup() {
  Serial.begin(9600);
  //initialize lcd and specify dimensions
  //lcd.begin(16, 2);
  //initialize CAN controller MCP2515 and specify bit rate
  if (Canbus.init(CANSPEED_500))
    Serial.println("CAN initialized");
  else
    Serial.println("ERROR: Can't initialize CAN controller");
}

/*
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
*/
bool bufferWasEmpty = 0;

void readCAN() {
  tCAN message;
  if (mcp2515_check_message())
  {
    if (mcp2515_get_message(&message))
    {
      //if(message.id == 0x620 and message.data[2] == 0xFF)  //uncomment when you want to filter
      //{

        bufferWasEmpty = 0;

        Serial.print("ID: ");
        Serial.print(message.id, HEX);
        Serial.print(", ");
        Serial.print("Data: ");
        Serial.print(message.header.length, DEC);
        for (int i = 0; i < message.header.length; i++)
        {
          Serial.print(message.data[i], HEX);
          Serial.print(" ");
        }
        Serial.println("");
  
//        lcd.print(message.header.length, DEC);
//        lcd.print(" ");
//        lcd.print(message.id, HEX);
//        lcd.setCursor(1,0);
//        for (int i = 0; i < min(message.header.length, 16); i++){
//          lcd.print(message.data[i], HEX);  
//        }

      
      //}
    }
//    else{
//      bufferWasEmpty = 1;
//      Serial.println("Could not get message");
//    }
  }
//  else if(bufferWasEmpty == 0){
//    Serial.println("No message available");
//    bufferWasEmpty = 1;
//  }
}

void loop() {
  
//  lcd.clear();
//  lcd.print("Len, Id");
//  lcd.setCursor(0,1);
//  lcd.print("Message");

//  delay(1500);

//  lcd.clear();
  
  readCAN();
  delay(1000);
}
