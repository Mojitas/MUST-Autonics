/*
  SolarTeam
  Datalogging - uSD card handler

  Specs:
    From limitations in the FAT16 file system:
  Filenames must follow the 8.3 convention; a name of no more than 8 characters, followed by a dot and the 3 character extension.
  A log must not exceed 4(?) GiB memory
  
    From requirements:
  Each day must have its own directory. The directory should be named after the date.
  Each log from a given day must be located in its corresponding directory.
  A log must be closed and a new one created and opened before the log hits the maximum file size. This must be done without losing CAN messages.


  
    
  Functionality required:
    Handle directory creation
    Handle file naming and creation
      Navigating up and down through directories
      Listing contents in a directory, specifically names of files
      Searching for a (sub)string in another string
      Iterating numbers in a string
  
  Input:  
    Date
    Time
    Data to store
    
  
*/


/*

  SD library:
    SD library notes: (https://www.arduino.cc/en/Reference/SDCardNotes)
    File naming conventions must use the 8.3 format (https://en.wikipedia.org/wiki/8.3_filename).
    file.write() doesn't write to the card until flush() or close() is called.
    It is possible to have multiple files open, as of version 1.0.
    
  
  SPI: ( https://www.circuitbasics.com/basics-of-the-spi-communication-protocol/ )
  MOSI - pin
  MISO - pin
  SCLK - pin

  SS/CS (Slave Select/Chip Select); HIGH - idle, LOW - active
  CS uSD - pin 9
  MCP2515 - pin
*/


/*
SD Library:
  SD class:
    begin()
    exists()
    mkdir()
    open()
    remove()
    rmdir()
  File class:
    available()
    close()
    flush()
    peek()
    position()
    print()
    println()
    seek()
    size()
    read()
    write()
    isDirectory()
    openNextFile()
    rewindDirectory()
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

String getDate(){
  return "210112" //yymmdd
}

int startfolder(){
  //get current date
  //if folder with given name doesn't exist:
  //  create new folder
  String date = "210112";
  String dirName = "/TEST" + date;
  return 0;
}

//given fileName: name with extension
File createFile(String fileName){
  //Assert
  //filename <= 8 chars
  //filename purely alphabetical
  //extension <= 3 chars
  //extension purely alphabetical

  //if file with given name and extension already exists: 
    //return err?
    //try iterating?
  //else create file
}

int createLog(String filename){
  //if filename <=8 chars
  //  append extension (.LOG or .TXT) to filename
  //  if another file with the same name exists
  //    return 0;
  //  else create file
}


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
  while (1) {}
}
