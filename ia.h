#ifndef IA_H
#define IA_H

#include <Arduino.h>

#include "movement.h"
#include "sensors.h"

int led = 2;

void ia_init() {
    pinMode(led, OUTPUT);
}

void ia_update() {
    int Cdist = center_distance();
    int Rdist = right_distance();
    int Ldist = left_distance();

    int minDist = (Cdist < Rdist? (Cdist < Ldist? Cdist: Ldist) : (Rdist < Ldist? Rdist : Ldist));
    int malDist = (Cdist > Rdist? (Cdist > Ldist? Cdist: Ldist) : (Rdist > Ldist? Rdist : Ldist));

    if(minDist > 15) {
        //Smoth movements
        float speedR, speedL;
        float l, r;
        
        if(Ldist > 60) l = 1.0;
        else l = (Ldist - 15) / (60 - 15);
        if(Rdist > 60) r = 1.0;
        else r = (Rdist - 15) / (60 - 15);

        float tri = ceil(l-r);

        //http://www.livephysics.com/tools/mathematical-tools/online-3-d-function-grapher/?xmin=0&xmax=1&ymin=0&ymax=1&zmin=0&zmax=1&f=ceil%28x-y%29*%28y-x*0.3%2B0.3%29%2B%281-ceil%28x-y%29%29*%28y*0.7%2B0.3%29
        speedR =     tri*(r-l*0.3+0.3) + (1-tri)*(r*0.7+0.3);
        //http://www.livephysics.com/tools/mathematical-tools/online-3-d-function-grapher/?xmin=0&xmax=1&ymin=0&ymax=1&zmin=0&zmax=1&f=%281-ceil%28x-y%29%29*%28x-y*0.3%2B0.3%29+%2B+++++ceil%28x-y%29*%28x*0.7%2B0.3%29
        speedL = (1-tri)*(l-r*0.3+0.3) +     tri*(l*0.7+0.3);

        move(speedR, speedL);

        analogWrite(led, (60-minDist)*255/15);
    } else {
        //Hard movements
        int mR = (float) (Cdist - Rdist);
        int mL = (float) (Ldist - Cdist);

        /*if(abs(mR - mL) < 3) {
            move(1.0, -1.0); //Full Left
            delar(500);
        }*/

        if(mR + mL > 0) {
            move(-1.0, 1.0); //Full Right
        } else {
            move(1.0, -1.0); //Full Left
        }
        
        analogWrite(led, (15-Rdist)*255/15);
    }
    

    
}

#endif
