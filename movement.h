#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>

const int motorA1Pin = 5;    // H-bridge leg 1 (pin 2, 1A)
const int motorA2Pin = 6;    // H-bridge leg 2 (pin 7, 2A)
const int AenablePin = 9;    // H-bridge enable pin

const int motorB1Pin = 7;    // H-bridge leg 1 (pin 2, 3A)
const int motorB2Pin = 8;    // H-bridge leg 2 (pin 7, 4A)
const int BenablePin = 10;   // H-bridge enable pin


void movement_init() {
    pinMode(motorA1Pin, OUTPUT);
    pinMode(motorA2Pin, OUTPUT);
    pinMode(AenablePin, OUTPUT);

    pinMode(motorB1Pin, OUTPUT);
    pinMode(motorB2Pin, OUTPUT);
    pinMode(BenablePin, OUTPUT);

    digitalWrite(AenablePin, LOW);
    digitalWrite(BenablePin, LOW);
}

void stop() {
    digitalWrite(AenablePin, LOW);
    digitalWrite(BenablePin, LOW);
}

void forward() {
    digitalWrite(AenablePin, HIGH);
    digitalWrite(BenablePin, HIGH);

    digitalWrite(motorA1Pin, HIGH);
    digitalWrite(motorA2Pin, LOW);

    digitalWrite(motorB1Pin, HIGH);
    digitalWrite(motorB2Pin, LOW);
    
    /*analogWrite(motorA1Pin, 255);
    analogWrite(motorA2Pin, 0);
    analogWrite(motorB1Pin, 128);
    analogWrite(motorB2Pin, 0);*/
}

void backward() {
    digitalWrite(AenablePin, HIGH);
    digitalWrite(BenablePin, HIGH);

    digitalWrite(motorA1Pin, LOW);
    digitalWrite(motorA2Pin, HIGH);

    digitalWrite(motorB1Pin, LOW);
    digitalWrite(motorB2Pin, HIGH);
}


void right() {
    digitalWrite(AenablePin, HIGH);
    digitalWrite(BenablePin, HIGH);

    digitalWrite(motorA1Pin, HIGH);
    digitalWrite(motorA2Pin, LOW);

    digitalWrite(motorB1Pin, LOW);
    digitalWrite(motorB2Pin, HIGH);
}

void left() {
    digitalWrite(AenablePin, HIGH);
    digitalWrite(BenablePin, HIGH);

    digitalWrite(motorA1Pin, LOW);
    digitalWrite(motorA2Pin, HIGH);

    digitalWrite(motorB1Pin, HIGH);
    digitalWrite(motorB2Pin, LOW);
}


#endif