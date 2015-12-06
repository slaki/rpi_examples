/*
 * File:   temphum.h
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * DHT11 sensor class - Temperature and humidity 
 *
 * Created on 2015
 */


#ifndef __TEMPHUM_H__
#define	__TEMPHUM_H__

class Temphum {
public:
    Temphum();
    Temphum(int pin);
    Temphum(const Temphum& orig);
    ~Temphum();
    
    void init();  // initializing sensor's initial values
    void update();  // updating values
    int getCycleLength(); // length of a cycle period in usec
    double getTemperature() const; // return the measured temperature
    double getHumidity() const; // return the measured humidity

private:
    double temp;
    double hum;
    int pin;
};

#endif	/* TEMPHUM_H */

