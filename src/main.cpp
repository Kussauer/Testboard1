#include <Arduino.h>

int yellowLEDTest = 6;
int button1 = 7;
int buttonStatus = 0;

int testRun = 1;

void setup()
{
  Serial.begin(115200);
  pinMode(yellowLEDTest, OUTPUT);
  pinMode(button1, INPUT);
}

void loop()
{

  buttonStatus = digitalRead(button1);

  if (buttonStatus == HIGH)
  {
    digitalWrite(yellowLEDTest, HIGH);
    Serial.println("Taster EIN");
    delay(1000);
  }
  else
  {
    digitalWrite(yellowLEDTest, LOW);
    Serial.println("Taster AUS");
  }
  
}
