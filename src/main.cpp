#include <Arduino.h>
#include "button1.h"
#include "oledDisplayOne.h"
#include "bewegungsmelder1.h"

#include <Wire.h>
#include <SPI.h>

// RFID RC522
#include <MFRC522.h>
#define SS_PIN 10 // SDA
#define RST_PIN 9 // RST

MFRC522 mfrc522(SS_PIN, RST_PIN);

// unsigned long previousMillisSonic = 0;
// unsigned long previousMillisButton = 0;

int zaehler = 0;                 // TestHilfe
int valuetest = 1;               // TestHilfe
float valueTestFloat = 1.2345;   // testHilfe
double valueTestDouble = 1.2345; // TestHilfe

int ultraschall = 0;

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

  // oledTestDurchlauf(); // Testdurchlauf im Setup

  // Bewegungsmelder1
  pinMode(bewegung, INPUT);

  // RFID RC522
  SPI.begin();
  mfrc522.PCD_Init();
}

/* ------Loop------------*/

void loop()
{

  unsigned long currentMillis = millis(); // für später

  // Testlauf
  /*
  Serial.print("Test ");
  zaehler = zaehler + 1;

  Serial.println(zaehler);
  oledDisplayInt(zaehler);
  delay(2000);

  // Bewegungssensor
  int moveReg = bewegungsMessung();
  if (moveReg == 1){
    Serial.println("Bewegung registriert");
    oledDisplayText("Bewegung");

  } else {
    Serial.println("Keine Bewegung registriert");
  }

*/

  // RFID

  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print("TAG-ID: ");
  long code = 0;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    code = ((code + mfrc522.uid.uidByte[i]) * 10);
  }

  Serial.println(code);
  // toggleYellowLedTest();

  if (code == 2016530)
  {
    einschaltenYellowLedTest();
    oledOne.println("Hallo Jenny");
    delay(2500);
    aussschaltenYellowLedTest();
  }
  else if (code == 609130)
  {
    oledOne.println("Hallo Nick");
    delay(2500);
    aussschaltenYellowLedTest();
  }
  else
  {
    toggleYellowLedTest();
  }
}
