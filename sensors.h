#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

#define USound_PinEcho0 4
#define USound_PinTrig0 3

#define USound_PinEcho1 32
#define USound_PinTrig1 28

#define USound_PinEcho2 34
#define USound_PinTrig2 30

//#define InfraR_Pin0 A8

void sensors_init() {
    pinMode(USound_PinEcho0, INPUT);
    pinMode(USound_PinTrig0, OUTPUT);

    pinMode(USound_PinEcho1, INPUT);
    pinMode(USound_PinTrig1, OUTPUT);

    pinMode(USound_PinEcho2, INPUT);
    pinMode(USound_PinTrig2, OUTPUT);
}


//Sensor tests
int USound_test(int echoPin, int trigPin){
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int distance = pulseIn(echoPin, HIGH, 4000) / 58;
    return distance;
}

int InfraR_test(int Analogic_pin){ 
    int i = 10;
    int sum = 0;
    while(i-- > 0) sum += analogRead(Analogic_pin);
    return sum / 10;
}


//Specific Distances
int right_distance() {
    return USound_test(USound_PinEcho1, USound_PinTrig1);
}

int left_distance() {
    return USound_test(USound_PinEcho2, USound_PinTrig2);
}

int center_distance() {
    //return InfraR_test(InfraR_Pin0);
    return USound_test(USound_PinEcho0, USound_PinTrig0);
}


#endif
