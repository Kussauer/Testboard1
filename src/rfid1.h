#include <MFRC522.h>
#include "rfidUsersList.h"
#include "dfPlayer.h"

#define SS_PIN 10 // SDA
#define RST_PIN 9 // RST

MFRC522 mfrc522(SS_PIN, RST_PIN);

long code = 0;
long checked_code = 0;

long check_rfid_users_id()
{
    code = 0; // 0-setzen des Wertes !!!
    Serial.println("Testline1");
    Serial.println(code);
    delay(1000);

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        Serial.println("Testline4");
        Serial.println(code);
        delay(1000);
        return code;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        Serial.println("Testline3");
        Serial.println(code);
        delay(1000);
        return code;

    }

    Serial.print("TAG-ID: ");
    long code = 0;

    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        code = ((code + mfrc522.uid.uidByte[i]) * 10);
    }

    Serial.println(code);
    Serial.println("Testline2");
    Serial.println(code);
    delay(1000);

    return code;
}


long action_rfid_users_id_correct(long checked_code)
{
    code = checked_code;
    
    switch (code)
    {
    case 2016530:
        einschaltenYellowLedTest();
        oledOne.println("Hallo Jenny");
        myDFPlayer.play(7);
        delay(2500);
        aussschaltenYellowLedTest();
        break;

    case 609130:
        einschaltenYellowLedTest();
        oledOne.println("Hallo Nick");
        myDFPlayer.play(7);
        delay(2500);
        aussschaltenYellowLedTest();
        break;

    case 0:
        break;

    default:
        myDFPlayer.play(5);
        toggleYellowLedTest();

    }

}

