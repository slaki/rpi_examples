/*
 * File:   sensor.h
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Sensor superclass. 
 *
 * Created on 2015
 */


#ifndef __SENSOR_H__
#define	__SENSOR_H__

class Sensor {
public:
    Sensor();
    Sensor(const Sensor& orig);
    virtual ~Sensor();
    
    virtual void init()   = 0;  // initializing sensor's initial values
    virtual void update() = 0;  // updating values
    virtual int getCycleLength() = 0; // length of a cycle period in usec

private:

};

#endif	/* SENSOR_H */

