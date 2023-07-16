#include <Arduino.h>

int yellowLEDTest = 6; // Pin 6 - Board 1
int button1 = 7;       // Pin 7 - Board 1
int buttonStatus = 0; // Button 1 - HIGH oder LOW

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

  if (currentMillis - previousMillis >= 200)
  {

    buttonStatus = digitalRead(button1);

    if (buttonStatus == HIGH)
    {
      digitalWrite(yellowLEDTest, HIGH);
      Serial.println("Taster EIN");
      //delay(1000);
    }
    else
    {
      digitalWrite(yellowLEDTest, LOW);
    }
  }
}
