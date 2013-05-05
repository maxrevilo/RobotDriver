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

/*
#ifndef POWER_H
#define POWER_H

#include <Arduino.h>
#include <avr/sleep.h>


int wakePin = 2;                 // pin used for waking up
int sleepStatus = 0;             // variable to store a request for sleep
int count = 0;                   // counter
int on, pushed;

void pushInterrupt()
{
    if(!digitalRead(btnPin)) {
        if(!pushed) {
            pushed = 1;
            on = 1-on;
        }
    } else {
        pushed = 0;
    }
}

void power_init() {
    pinMode(wakePin, INPUT); 
    on = 0;
    pushed = 0;

    attachInterrupt(0, pushInterrupt, LOW);
}

int isOn() {
    return on;
}

void sleepNow()
{
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    attachInterrupt(0, pushInterrupt, LOW);
    sleep_mode();
    sleep_disable();
    detachInterrupt(0);
}

#endif
*/