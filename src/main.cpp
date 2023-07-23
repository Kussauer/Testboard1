#include <Arduino.h>
#include "button1.h"
#include "oledDisplayOne.h"
#include "bewegungsmelder1.h"
#include "rfid1.h"
//#include "dfPlayer.h"

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <Wire.h>
#include <SPI.h>

// DFPlayer
/*SoftwareSerial mySoftwareSerial(2,3);
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
*/

int ultraschall = 0;  // test

long rfid_code = 0; // test

/*=====================================================*/

void setup()
{
  Serial.begin(115200);           // auch Konfig platformio.ini !!
  pinMode(yellowLEDTest, OUTPUT); // testled
  pinMode(button1, INPUT);        // button1

  // Ultraschall HC-SR04
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Wire.begin();
  Wire.setClock(400000L);

  // OLED Display
  oledOne.begin(&Adafruit128x64, I2C_ADDRESS); // OLED 0,96
  oledOne.setFont(Arial_bold_14);
  oledOne.displayRemap(true);              // Drehung 180 Grad
  oledOne.setScrollMode(SCROLL_MODE_AUTO); // AutoScroll
  oledOne.setLetterSpacing(2);
  oledOne.println("Start");

  // oledTestDurchlauf(); 
  // Testdurchlauf im Setup

  // Bewegungsmelder1
  pinMode(bewegung, INPUT);

  // RFID RC522
  SPI.begin();
  mfrc522.PCD_Init();

  // DFPlayer
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  mySoftwareSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  //myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30);
  myDFPlayer.play(2);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

}

/* =============================================*/

void loop()
{

  unsigned long currentMillis = millis(); // für später

  
  rfid_code = 0;
  rfid_code = check_rfid_users_id();
  action_rfid_users_id_correct(rfid_code);

  //DFPlayer
  static unsigned long timer = millis();
  
  if (millis() - timer > 10000) {
    timer = millis();
   //myDFPlayer.play(3);
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

}
