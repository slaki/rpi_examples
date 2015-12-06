/*
 * File:   test_temphum.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Test code for temperature and humidity sensor DHT11
 *
 * Created on 2015
 */


#include "temphum.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

int main() {
    
    Temphum th_sensor(7);
    th_sensor.init();
    
   while (1) {
	printf("Temperature: %f C*, Humidity: %f \%\n", th_sensor.getTemperature(), th_sensor.getHumidity());

	delay(500); // sleeping 500 ms

        // Poll data from the sensor
        th_sensor.update();        
    } // end of WHILE   
}

