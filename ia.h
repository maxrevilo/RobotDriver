#ifndef IA_H
#define IA_H

#include <Arduino.h>

#include "movement.h"
#include "sensors.h"

int led = 2;


void ia_init() {
    pinMode(led, OUTPUT);
}

/*void ia_update() {

    int dist = right_distance();
    if(dist > 20 || dist < 0) {
        analogWrite(led, 0);
        forward();
        delay(100);
    } else if(dist < 5){
        backward();
        delay(100);
    } else {

        analogWrite(led, (20-dist)*255/20);

        int distL = center_distance();

        if(distL > 260) {
            right();
        } else {
            left();
        }
        delay(250);
    }
    
}*/

void ia_update() {

    int Cdist = center_distance();
    int Rdist = right_distance();
    int Ldist = left_distance();

    if(Rdist < 12 && Ldist < 12) {
        analogWrite(led, 255);

        backward();
        delay(500); return;
    }

    if(Rdist < 20) {
        analogWrite(led, (20-Rdist)*255/20);
        left();
        delay(250); return;
    }

    if(Ldist < 20) {
        analogWrite(led, (20-Ldist)*255/20);
        right();
        delay(250); return;
    }

    if(Cdist < 20) {
        analogWrite(led, (20-Cdist)*255/20);

        right();
        delay(500); return;
    }

    if(Rdist > 20 && Ldist > 20 && Cdist > 20) {
        analogWrite(led, 0);
        
        forward();
        delay(100);
    }
    
}

#endif