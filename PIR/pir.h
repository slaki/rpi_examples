/*
 * File:   pir.h
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * PIR sensor class - IR-based movement detection
 *
 * Created on 2015
 */


#ifndef __PIR_H__
#define	__PIR_H__

class PIR {
public:
    PIR();
    PIR(int pin);
    PIR(const PIR& orig);
    ~PIR();
    
    void init();  // initializing sensor's initial values
    void update();  // updating values
    int getCycleLength(); // length of a cycle period in usec
    bool isOn() const; // check if movement is detected or not

private:
    bool on;
    int pin;
};

#endif	/* PIR_H */

