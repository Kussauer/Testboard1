#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServos = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
#define USMIN 600
#define USMAX 2400
#define SERVO_FREQ 50

uint8_t servonum = 0;
uint8_t numberOfServos = 2;

void servo1Offen () {
    myServos.setPWM(1, 0, 100);
}

void servo1Geschlossen (){
    myServos.setPWM(1, 0, 500);
}
