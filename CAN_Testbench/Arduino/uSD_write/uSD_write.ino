/*
   SPI: ( https://www.circuitbasics.com/basics-of-the-spi-communication-protocol/ )
   MOSI - pin
   MISO - pin
   SCLK - pin

   SS/CS (Slave Select/Chip Select); HIGH - idle, LOW - active
   CS uSD - pin 9
   MCP2515 - pin
*/

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

//#include <LiquidCrystal.h>

#include <SPI.h>

#include <SD.h>


const int CS_uSD = 9;

void setup() {
  Serial.begin(9600);

  pinMode(CS_uSD, OUTPUT);
  if (!SD.begin(CS_uSD)) {
    Serial.println("Card failed or not present");
    return;
  }
  Serial.println("Card ready");
}

void loop() {
  String dataString = "";
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    //write to uSD card
    int timeStamp = millis();
    dataFile.print(timeStamp);
    dataFile.print(" ms");
    dataFile.print(", ");
    //write to Serial monitor
    Serial.print(timeStamp);
    Serial.print(", ");

    timeStamp = millis();
    dataFile.print(timeStamp);
    dataFile.print(" ms");
    dataFile.print(", ");
    
    Serial.print(timeStamp);
    Serial.print(", ");

    timeStamp = millis();
    dataFile.print(timeStamp);
    dataFile.print(" ms");
    dataFile.print(", ");

    Serial.print(timeStamp);
    Serial.print(", ");

    
    dataFile.print(", yayeet!");
    
    Serial.print(", yayeet!");
    /*
    for (int analogPin = 0; analogPin < 3; analogPin++) {
      //write to uSD card
      int sensorVal = analogRead(analogPin);
      dataFile.print(" Analog Pin A")
      dataFile.print(analogPin);
      dataFile.print(" = ");
      dataFile.print(sensorVal);
      //write to Serial monitor
      Serial.print(" A");
      Serial.print(analogPin);
      Serial.print(" = ");
      Serial.print(sensorVal);
      if (analogPin < 3) {
        dataString += ",";
      }
    }
    */
    
    dataFile.println();
    dataFile.close();
    Serial.println();
  }
  else {
    Serial.println("Could not open datalog.txt");
  }
  //Stop program
  while(1){}
}
