/*
 * File:   ultrasonic.h
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Ultrasonic sensor with one pin. The same pin is used to trigger and echo events.  
 *
 * Created on 2015
 */


#ifndef __ULTRASONIC_H__
#define	__ULTRASONIC_H__

class Ultrasonic {
public:
    Ultrasonic();
    Ultrasonic(int echo, int trigger);
    Ultrasonic(const Ultrasonic& orig);
    ~Ultrasonic();
    
    void init();  // initializing sensor's initial values
    void update();  // updating values
    int getCycleLength(); // length of a cycle period in usec
    double getDistanceCm() const; // return the measured distance

private:
    int echo;
    int trigger;
    int mode; // 0: different pins for echo and trigger, 1: a single pin for echo and trigger
    double distanceCm;
};

#endif	/* ULTRASONIC_H */

