#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <math.h>

#define PI 3.14159265359

#define USound_PinEcho0 4
#define USound_PinTrig0 3

#define USound_PinEcho1 32
#define USound_PinTrig1 28

#define USound_PinEcho2 34
#define USound_PinTrig2 30

//#define InfraR_Pin0 A8

#define WALLS_LEN 3
#define OPENING_DEGREES 90
// 0 (Der) ... WALLS_LEN/2 (Centro) ... WALLS_LEN (Izq)
unsigned char walls[WALLS_LEN];

unsigned char min_rad_dist;
int wall_df;

void sensors_init() {
    pinMode(USound_PinEcho0, INPUT);
    pinMode(USound_PinTrig0, OUTPUT);

    pinMode(USound_PinEcho1, INPUT);
    pinMode(USound_PinTrig1, OUTPUT);

    pinMode(USound_PinEcho2, INPUT);
    pinMode(USound_PinTrig2, OUTPUT);

    int i = WALLS_LEN;
    while(i-- > 0) {
        walls[i] = 128;
    }
    min_rad_dist = 255;
}


//Sensor tests
int USound_test(int echoPin, int trigPin){
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int distance = pulseIn(echoPin, HIGH) / 58;
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

void sensors_update() {
    //correr motores a 0

    int i = WALLS_LEN;
    int deg_diff = OPENING_DEGREES / WALLS_LEN;

    float rad_diff = deg_diff / 2 / PI;
    float degrees = (OPENING_DEGREES - 180) / 2 / PI;
    
    while(i-- > 0) {
        unsigned char cDist = (unsigned char) center_distance();

        walls[i] = cDist * sin(degrees);

        min_rad_dist = cDist < min_rad_dist ? cDist : min_rad_dist;

        //girar deg_diff
    }





}


#endif
