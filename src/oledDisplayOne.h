#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oledOne; // Displayname oledOne

void oledTestDurchlauf()
{
    // Anzeige OLED
    oledOne.clear();
    Serial.println("LCD"); // Teat
    // oledOne.println(" Nick K.");
    oledOne.println(" Testboard Uno 1");
    oledOne.println(" Version 1.0");
    oledOne.println(" Stand 07/2023");
    delay(4000);
}

void oledDisplayText(String text)
{
    oledOne.println(text);
}

void oledDisplayInt(int value)
{
    oledOne.println(value);
}

void oledDisplayFloat(float valueFloat)
{
    oledOne.println(valueFloat);
}

void oledDisplayDouble(double valueDouble){
    oledOne.println(valueDouble);
}