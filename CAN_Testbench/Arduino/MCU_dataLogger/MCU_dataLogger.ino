  
/*
  Read/write to SD card
  Transmit/receive CANbus
  Output to LCD/UART

*/


//CAN Read Demo libraries
#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>



// lcd display variable (RS, EN, data pins 4,5,6,7)
//LiquidCrystal lcd(LCD_RS, LCD_EN, 3, 4, 5, 6);

void setup() {
  Serial.begin(9600);
  //initialize lcd and specify dimensions
  //lcd.begin(16, 2);
  //initialize CAN controller MCP2515 and specify bit rate
  int CAN_BRP = CANSPEED_500;
  CAN_BRP = 199;
  if (Canbus.init(CAN_BRP))
    Serial.println("CAN initialized");
  else
    Serial.println("ERROR: Can't initialize CAN controller");
}

bool bufferWasEmpty = 0;

void readCAN() {
  tCAN message;
  //Check if new messages are waiting
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

    }
    else {
      //bufferWasEmpty = 1;
      Serial.println("Get Message Failed");
    }
  }
  else if (bufferWasEmpty == 0) {
    Serial.println("Check Message Failed");
    //bufferWasEmpty = 1;
  }
}

void sendMessageCAN() {
  tCAN message;

  //message.id = 0x631; //formatted in HEX
  message.id = 0x123;
  message.header.rtr = 0;
  message.header.length = 8; //formatted in DEC
  message.data[0] = 0x40;
  message.data[1] = 0x05;
  message.data[2] = 0x30;
  message.data[3] = 0xFF; //formatted in HEX
  message.data[4] = 0x00;
  message.data[5] = 0x40;
  message.data[6] = 0x00;
  message.data[7] = 0x00;

  
  //mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
  int retval = mcp2515_send_message(&message);

  Serial.print("Check free buffer: ");
  Serial.println(mcp2515_check_free_buffer());
  Serial.print("Print ret: ");
  Serial.println(retval);
}


void loop() {
  readCAN();
  sendMessageCAN();

  delay(1000);
}
