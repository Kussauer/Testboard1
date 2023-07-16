#include <Arduino.h>
#include "button1.h"
// #include "ultraschall1.h" -- über button1.h

unsigned long previousMillisSonic = 0;
unsigned long previousMillisButton = 0;

void setup()
{
  Serial.begin(115200);           // auch Konfig platformio.ini !!
  pinMode(yellowLEDTest, OUTPUT); // testled
  pinMode(button1, INPUT);        // button1

  // Ultraschall HC-SR04
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{

  unsigned long currentMillis = millis(); // für später

  /*
  if (currentMillis - previousMillisSonic >= 5000)
  {
    previousMillisSonic = currentMillis;
    ultraschallOne();
  }


  if (currentMillis - previousMillisButton >= 100)
  {
    previousMillisButton = currentMillis;
    buttonOneBounce();
  }
  */

  buttonOneBounce();
}
