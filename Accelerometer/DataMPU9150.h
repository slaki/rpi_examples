/*
 * File:   DataMPU9150.h
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Sample code for using MPU9150 sensor that includes an accelerometer, gyroscope and magnetometer. The sensor uses I2C for communication and can be managed via the library RTIMULib
 *
 * Created on 2015
 */

#ifndef DATAMPU9150_H
#define	DATAMPU9150_H

#include "sensor.h"
#include "RTIMULib.h"

class DataMPU9150 : public Sensor {
public:
    DataMPU9150();
    DataMPU9150(const DataMPU9150& orig);
    virtual ~DataMPU9150();

    virtual void init();    // Initialization of MPU9150 sensor
    virtual void update();  // Update MPU9150 sensor values
    virtual int getCycleLength(); // Get the MPU9150 update frequency in usecs

    // Get current measurement values:
    float* getFusionPose() {return _fusion_vector;}
    float* getGyro() {return _gyro_vector;}
    float* getAccel() {return _accel_vector;}
    float* getCompass() {return _compass_vector;}

private:

    float   _fusion_vector[3],
            _gyro_vector[3],
            _accel_vector[3],
            _compass_vector[3];

    RTIMUSettings *settings;
    RTIMU *imu;
};

#endif	/* DATAMPU9150_H */

