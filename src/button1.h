#include <Bounce2.h>
#include "ultraschall1.h"

int button1 = 7;       // Pin 7 - Board 1
Bounce button1Bounce = Bounce(button1, 50);
int buttonStatus = 0;  // Button 1 - HIGH oder LOW
int yellowLEDTest = 6;

int counter = 0;

void buttonOneBounce()
{
    button1Bounce.update();

    if (button1Bounce.fell())
    {
        buttonStatus = buttonStatus + 1;
        digitalWrite(yellowLEDTest, HIGH);
        Serial.println("Taster EIN");
        ultraschallOne();
        counter = counter +1;
        Serial.println(counter);
       
    }
    else
    {
        digitalWrite(yellowLEDTest, LOW);
    }
}


