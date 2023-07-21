#include <Arduino.h>
int yellowLEDTest = 6;

void einschaltenYellowLedTest(){
    digitalWrite(yellowLEDTest, HIGH);
}

void aussschaltenYellowLedTest() {
    digitalWrite(yellowLEDTest, LOW);
}

void toggleYellowLedTest() {
    for (int i = 0; i < 10; i++)
    {
       einschaltenYellowLedTest();
       delay(250);
       aussschaltenYellowLedTest();
       delay(250);
    }
    
}

