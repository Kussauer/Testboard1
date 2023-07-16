int yellowLEDTest = 6; // Pin 6 - Board 1
int button1 = 7;       // Pin 7 - Board 1
int buttonStatus = 0;  // Button 1 - HIGH oder LOW

int counter = 0;

void buttonOne()
{
    buttonStatus = digitalRead(button1);

    if (buttonStatus == HIGH)
    {
        digitalWrite(yellowLEDTest, HIGH);
        Serial.println("Taster EIN");
        counter = counter +1;
        Serial.println(counter);
        // delay(1000);
    }
    else
    {
        digitalWrite(yellowLEDTest, LOW);
    }
}