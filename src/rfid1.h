#include <MFRC522.h>
#include "rfidUsersList.h"

#define SS_PIN 10 // SDA
#define RST_PIN 9 // RST

MFRC522 mfrc522(SS_PIN, RST_PIN);

long code = 0;
long checked_code = 0;

long check_rfid_users_id()
{
    code = 0; // 0-setzen des Wertes !!!

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return code;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return code;
    }

    Serial.print("TAG-ID: ");
    // long code = 0;

    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        code = ((code + mfrc522.uid.uidByte[i]) * 10);
    }

    Serial.println(code);
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
        delay(2500);
        aussschaltenYellowLedTest();
        break;

    case 609130:
        einschaltenYellowLedTest();
        oledOne.println("Hallo Nick");
        delay(2500);
        aussschaltenYellowLedTest();
        break;

    case 0:
        break;

    default:
        toggleYellowLedTest();
    }

}

