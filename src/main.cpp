#include <Arduino.h>
#include "button1.h"

unsigned long previousMillis = 0;

void setup()
{
  Serial.begin(115200); // auch Konfig platformio.ini !!
  pinMode(yellowLEDTest, OUTPUT);
  pinMode(button1, INPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 150)
  {
    previousMillis = currentMillis;

    buttonOne();
  }
}
