
int echoPin = 9;
int triggerPin = 8;
long duration = 0;
long distance = 0;

void ultraschallOne()
{
    // Ultraschall
    digitalWrite(triggerPin, LOW);
    delay(5);
    digitalWrite(triggerPin, HIGH);
    delay(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    distance = (duration / 2) * 0.03432;

    if (distance >= 500 || distance <= 0)
    {
        Serial.println("Kein Messwert");
    }
    else
    {
        Serial.print("Die Entfernung beträgt: ");
        Serial.print(distance);
        Serial.println(" cm");
        //delay(1000);  --kann weg
    }

}


