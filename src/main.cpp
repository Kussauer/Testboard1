#include <Arduino.h>
#include "button1.h"
#include "oledDisplayOne.h"

#include <Wire.h>

// unsigned long previousMillisSonic = 0;
// unsigned long previousMillisButton = 0;

int zaehler = 0; // TestHilfe
int valuetest = 1; // TestHilfe
float valueTestFloat = 1.2345;  // testHilfe
double valueTestDouble = 1.2345;   // TestHilfe

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
  oledOne.displayRemap(true);  //Drehung 180 Grad
  oledOne.setScrollMode(SCROLL_MODE_AUTO); // AutoScroll
  oledOne.setLetterSpacing(2);

  oledTestDurchlauf(); // Testdurchlauf im Setup
}

void loop()
{

  unsigned long currentMillis = millis(); // für später

  

  
}
