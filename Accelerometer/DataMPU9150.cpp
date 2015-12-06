/* 
 * File:   DataMPU9150.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 * 
 * Description:
 * Sample code for using MPU9150 sensor that includes an accelerometer, gyroscope and magnetometer. The sensor uses I2C for communication and can be managed via the library RTIMULib 
 *
 * Created on 2015
 */

#include "DataMPU9150.h"

DataMPU9150::DataMPU9150() {
    settings = new RTIMUSettings("RTIMULib");
    imu = RTIMU::createIMU(settings);

    if ((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)) {
        printf("No IMU found\n");
        exit(1);
    }
}

DataMPU9150::DataMPU9150(const DataMPU9150& orig) {
}

DataMPU9150::~DataMPU9150() {
}

void DataMPU9150::init() {

    //  This is an opportunity to manually override any settings before the call IMUInit

    //  set up IMU
    imu->IMUInit();

    //  this is a convenient place to change fusion parameters

    imu->setSlerpPower(0.02);
    imu->setGyroEnable(true);
    imu->setAccelEnable(true);
    imu->setCompassEnable(true);

    usleep(imu->IMUGetPollInterval() * 1000); // We have to wait  before the first sensor reading...
    // usleep(16000); // this waiting time is generally between 15000-20000 usecs
}

void DataMPU9150::update() {
    if ( imu->IMURead() )
    {
        RTIMU_DATA imuData = imu->getIMUData();
        for (int i=0;i<3;i++){_fusion_vector[i]=imuData.fusionPose.data(i);}
        for (int i=0;i<3;i++){_gyro_vector[i]=imuData.gyro.data(i);}
        for (int i=0;i<3;i++){_accel_vector[i]=imuData.accel.data(i);}
        for (int i=0;i<3;i++){_compass_vector[i]=imuData.compass.data(i);}
    }
}

int DataMPU9150::getCycleLength() {
	return imu->IMUGetPollInterval() * 1000; //in usec, cycle length expreses the time resolution of the sensor. Faster polling than this number may cause errors or empty results...
}
