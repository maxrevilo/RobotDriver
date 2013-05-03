#ifndef POWER_H
#define POWER_H

#include <Arduino.h>

int on, pushed;
const int btnPin = 24;  

void power_init() {
    pinMode(btnPin, INPUT); 
    on = 0;
    pushed = 0;
}

void check_push() {
    if(!digitalRead(btnPin)) {
        if(!pushed) {
            pushed = 1;
            on = 1-on;
        }
    } else {
        pushed = 0;
    }
}

int isOn() {
    return on;
}

#endif