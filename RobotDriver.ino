#include <Arduino.h>

#include "movement.h"
#include "sensors.h"
#include "power.h"

#include "ia.h"


void setup() {
    //Intento ver sensor
    Serial.begin(9600);
    Serial.println("Initializing");
    movement_init();
    sensors_init();
    power_init();
    ia_init();
    Serial.println("Ready!");
}

void loop() {

    check_push();

    if(isOn()) {
        //Turned ON:
        ia_update();
    } else {
        //Turned OFF:
        stop();
    }

    delay(10);
}







