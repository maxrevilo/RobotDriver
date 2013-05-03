#include <Arduino.h>

#include "movement.h"
#include "sensors.h"
#include "power.h"

#include "ia.h"


void setup() {
    //Intento ver sensor
    movement_init();
    sensors_init();
    power_init();
    ia_init();
}

void loop() {

    check_push();

    if(isOn()) {
        //Turned ON:
        ia_update();
        
        /*int Cdist = center_distance();
        int Rdist = right_distance();
        int Ldist = left_distance();
        
        Serial.print("Cdist = " );
        Serial.println(Cdist);
        Serial.print("Ldist = " );
        Serial.println(Ldist);
        Serial.print("Rdist = " );
        Serial.println(Rdist);*/
    } else {
        //Turned OFF:
        stop();
        delay(250);
    }
}







