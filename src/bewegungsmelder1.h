#include <Arduino.h>

int bewegung = 5;
int bewegungsstatus = 0;

int bewegungsMessung () {
    bewegungsstatus = digitalRead(bewegung);
    if (bewegungsstatus == HIGH) {
        return 1;
    } else {
        return 0;
    }
}
