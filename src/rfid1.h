#include <MFRC522.h>

// RFID RC522
#define SS_PIN 10 // SDA
#define RST_PIN 9 // RST

MFRC522 mfrc522(SS_PIN, RST_PIN);