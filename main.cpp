#include <Arduino.h>
#define GIRO 12
#define MOTORPIN 25
#define MOTORPIN2 26
#define UP 2
#define DOWN 4
int motordir = 1;

void updatemotordir(){
    if (motordir == 1){
        digitalWrite(MOTORPIN, HIGH);
        digitalWrite(MOTORPIN2, LOW);
    } else {
        digitalWrite(MOTORPIN, LOW);
        digitalWrite(MOTORPIN2, HIGH);
    }

}

void setup(){
    pinMode(MOTORPIN, OUTPUT);
    pinMode(MOTORPIN2, OUTPUT);
    pinMode(GIRO, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);

    digitalWrite(MOTORPIN, LOW);
    digitalWrite(MOTORPIN2, LOW);
}

void loop(){
    if (digitalRead(GIRO) == LOW){
        delay(50);
        digitalWrite(MOTORPIN, HIGH);
        digitalWrite(MOTORPIN2, LOW);
        updatemotordir();
        while (digitalRead(GIRO) == HIGH){
            delay(50);
            digitalWrite(MOTORPIN, LOW);
            digitalWrite(MOTORPIN2, HIGH);
        }
    }
}