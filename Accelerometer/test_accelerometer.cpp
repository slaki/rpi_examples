/*
 * File:   test_accelerometer.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Test code for IMU MPU9150 sensors.
 *
 * Created on 2015
 */


#include "RTIMULib.h"
#include "DataMPU9150.h"
#include <unistd.h>

int main() {
    
    DataMPU9150 imu_sensor;
    imu_sensor.init();
    
    uint64_t rateTimer;
    uint64_t displayTimer;
    uint64_t now;

    // Current time in usecs provided by RTIMU library
    rateTimer = displayTimer = RTMath::currentUSecsSinceEpoch();
    
    float   *fusion,
            *gyro,
            *accel,
            *compass;

    printf("Cycle length: %d us\n", imu_sensor.getCycleLength());
    while (1) {
        //  poll at the rate recommended by the sensor
        usleep( imu_sensor.getCycleLength() );

	// Current time in usecs - using RTIMU library
        now = RTMath::currentUSecsSinceEpoch();

        // Poll data from the sensor
        imu_sensor.update();
        
        //  display 10 times per second
        if ((now - displayTimer) > 100000) {
            
            // Get data from the sensor class
            fusion = imu_sensor.getFusionPose();
            gyro = imu_sensor.getGyro();
            accel = imu_sensor.getAccel();
            compass = imu_sensor.getCompass();
           
	    // Printing data 
            printf("Fusion x:% -8.1f y:% -8.1f z:% -8.1f\n", fusion[0], fusion[1], fusion[2] );
            printf("Gyro x:% -8.1f y:% -8.1f z:% -8.1f\n", gyro[0], gyro[1], gyro[2] );
            printf("Accelerometer x:% -8.1f y:% -8.1f z:% -8.1f\n", accel[0], accel[1], accel[2] );
            printf("Compass x:% -8.1f y:% -8.1f z:% -8.1f\n", compass[0], compass[1], compass[2] );

            fflush(stdout);
            displayTimer = now;
        }
    } // end of WHILE   
}

