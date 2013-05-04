#ifndef IA_H
#define IA_H

#include <Arduino.h>

#include "movement.h"
#include "sensors.h"

int led = 2;

char commands_history[3];
int hist_index;

void ia_init() {
    pinMode(led, OUTPUT);

    commands_history[0] = 0;
    commands_history[1] = 1;
    commands_history[2] = 2;
    hist_index = 0;
}

void add_command(char command) {
    commands_history[hist_index % 3] = command;
    hist_index++;
}

char isDerp() {
    char ch0 = commands_history[0];
    char ch1 = commands_history[1];
    char ch2 = commands_history[2];

    if(ch0 == 'R' && ch2 == 'R') {
        return ch1 == 'L';
    } else if(ch0 == 'L' && ch2 == 'L') {
        return ch1 != 'R';
    }
}

void ia_update() {
  
    Serial.print("Hist 0");
    Serial.println(commands_history[0]);
    Serial.print("Hist 1");
    Serial.println(commands_history[1]);
    Serial.print("Hist 2");
    Serial.println(commands_history[2]);
    Serial.println();


    if(isDerp()) {
        analogWrite(led, 0);
        Serial.println("DERP!!!!!!");
        left();
        add_command('\0');
        delay(750); return;
    }

    int Cdist = center_distance();
    int Rdist = right_distance();
    int Ldist = left_distance();

    if(Rdist < 10 && Ldist < 10) {
        analogWrite(led, 255);

        backward();
        add_command('B');
        delay(500); return;
    }

    if(Rdist < 20) {
        analogWrite(led, (20-Rdist)*255/20);
        left();
        add_command('L');
        delay(250); return;
    }

    if(Ldist < 20) {
        analogWrite(led, (20-Ldist)*255/20);
        right();
        add_command('R');
        delay(250); return;
    }

    if(Cdist < 20) {
        analogWrite(led, (20-Cdist)*255/20);

        right();
        add_command('R');
        delay(500); return;
    }

    if(Rdist > 20 && Ldist > 20 && Cdist > 20) {
        analogWrite(led, 0);
        
        forward();
        add_command('F');
        delay(100);
    }
    
}

#endif





