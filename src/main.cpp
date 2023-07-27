#include <Arduino.h>
#include "button1.h"
#include "oledDisplayOne.h"
#include "bewegungsmelder1.h"
#include "rfid1.h"

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <Wire.h>
#include <SPI.h>

int ultraschall = 0; // test

long rfid_code = 0; // test

unsigned long previousButton1Millis = 0; // Button1
const long button1Intervall = 50;        // Button1
const long buttonAbfragepause = 1000;
unsigned long timerButton = 0;
int statusButton1 = 0; // Button1

/*=====================================================*/

void setup()
{
  Serial.begin(115200);           // auch Konfig platformio.ini !!
  pinMode(yellowLEDTest, OUTPUT); // testled
  pinMode(button1, INPUT_PULLUP); // button1

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

  // Bewegungsmelder1
  pinMode(bewegung, INPUT);

  // RFID RC522
  SPI.begin();
  mfrc522.PCD_Init();

  // DFPlayer
  pinMode(dfPlayer_rx, INPUT);
  pinMode(dfPlayer_tx, OUTPUT);
  mySoftwareSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true)
    {
      delay(0);
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  // myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30);
  // myDFPlayer.play(2);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
}

/* ================== LOOP ===========================*/

void loop()
{

  unsigned long currentMillis = millis(); // für später

  rfid_code = 0;
  rfid_code = check_rfid_users_id();
  action_rfid_users_id_correct(rfid_code);

  // Button
  if (currentMillis - previousButton1Millis >= button1Intervall)
  {  // wird noch nach button1.h verschoben
    statusButton1 = statusButtonWiderstand();
    Serial.print("StatusButton 1 = ");
    Serial.println(statusButton1);
    if (statusButton1 == 1 && (currentMillis - timerButton > buttonAbfragepause)) // nächster Tastendruck frühestens nach timerAbfragepause
    {
      timerButton = currentMillis;
      oledOne.println("Button1 gedrückt");
      einschaltenYellowLedTest();
    }
    else
    {
      aussschaltenYellowLedTest();
    }
    previousButton1Millis = currentMillis;
  }
  /*
    // DFPlayer
    static unsigned long timer = millis();

    if (millis() - timer > 10000)
    {
      timer = millis();
      // myDFPlayer.play(3);
    }

    if (myDFPlayer.available())
    {
      printDetail(myDFPlayer.readType(), myDFPlayer.read()); // Print the detail message from DFPlayer to handle different errors and states.
    }
  */
}
