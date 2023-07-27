#include <Bounce2.h>
#include "ultraschall1.h"
#include "yellowLedTest.h"

int button1 = 7;      // Pin 7 - Board 1
int buttonStatus = 0; // Button 1 - HIGH oder LOW

int statusButtonWiderstand()
{
    buttonStatus = digitalRead(button1);
    return buttonStatus;
}