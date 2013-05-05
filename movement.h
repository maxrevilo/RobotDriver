#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>
#include <Math.h>

const int motorA1Pin = 5;    // H-bridge leg 1 (pin 2, 1A)
const int motorA2Pin = 6;    // H-bridge leg 2 (pin 7, 2A)
const int AenablePin = 9;    // H-bridge enable pin

const int motorB1Pin = 7;    // H-bridge leg 1 (pin 2, 3A)
const int motorB2Pin = 8;    // H-bridge leg 2 (pin 7, 4A)
const int BenablePin = 10;   // H-bridge enable pin


void stop() {
    digitalWrite(AenablePin, LOW);
    digitalWrite(BenablePin, LOW);

    analogWrite(motorA1Pin, 0);
    analogWrite(motorA2Pin, 0);
    analogWrite(motorB1Pin, 0);
    analogWrite(motorB2Pin, 0);
}

void movement_init() {
    pinMode(motorA1Pin, OUTPUT);
    pinMode(motorA2Pin, OUTPUT);
    pinMode(AenablePin, OUTPUT);

    pinMode(motorB1Pin, OUTPUT);
    pinMode(motorB2Pin, OUTPUT);
    pinMode(BenablePin, OUTPUT);

    stop();
}

// SpeedR y SpeedL [-1.0, 1.0]
void move(float speedR, float speedL) {
    unsigned char speed_FR = 0, speed_BR = 0, speed_FL = 0, speed_BL = 0;

    if(speedR < 0.0039 & speedL < 0.0039) {
        stop();
        return;
    }

    if(speedR > 0) {
        speed_FR = (unsigned char) (speedR * 255.0);
    } else {
        speed_BR = (unsigned char) (-speedR * 255.0);
    }

    if(speedL > 0) {
        speed_FL = (unsigned char) (speedL * 255.0);
    } else {
        speed_BL = (unsigned char) (-speedL * 255.0);
    }

    digitalWrite(AenablePin, HIGH);
    digitalWrite(BenablePin, HIGH);

    analogWrite(motorB1Pin, speed_FL);
    analogWrite(motorB2Pin, speed_BL);

    analogWrite(motorA1Pin, speed_FR);
    analogWrite(motorA2Pin, speed_BR);
}


#endif