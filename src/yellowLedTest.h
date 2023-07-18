#include <Arduino.h>
int yellowLEDTest = 6;

void einschaltenYellowLedTest(){
    digitalWrite(yellowLEDTest, HIGH);
}

void aussschaltenYellowLedTest() {
    digitalWrite(yellowLEDTest, LOW);
}

