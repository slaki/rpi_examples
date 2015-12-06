/*
 * File:   test_pir.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Test code for PIR sensors
 *
 * Created on 2015
 */


#include "pir.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

int main() {
    
    PIR pir_sensor(7);
    pir_sensor.init();
    
   while (1) {

	if (pir_sensor.isOn()) {
		printf("The light is ON...\n");
	}
	else {
		printf("The light is OFF...\n");
	}

	delay(500); // sleeping 500 ms

	// Poll data from the sensor
        pir_sensor.update();
        
    } // end of WHILE   
}

