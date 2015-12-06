/*
 * File:   test_ultrasonic.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Test code for Ultrasonic distance measurement sensors
 *
 * Created on 2015
 */


#include "ultrasonic.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

int main() {
    
    Ultrasonic u_sensor(7,7);
    u_sensor.init();
    
   while (1) {

	printf("Distance: %f cm\n", u_sensor.getDistanceCm());

	delay(500); // sleeping 500 ms

        // Poll data from the sensor
        u_sensor.update();
        
    } // end of WHILE   
}

