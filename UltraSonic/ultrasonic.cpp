/*
 * File:   sensor.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Sensor superclass.
 *
 * Created on 2015
 */

#include "ultrasonic.h"
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

#define PULSELENGTH 5

void sendPulse(int pin, int mode) {
	if (mode==1) {
		pinMode(pin,OUTPUT);
		digitalWrite(pin, 0); // Reinitialze to 0 level
		delayMicroseconds(2);
	}

	// Generate a pulse
	digitalWrite(pin, 1); // Impulse starts
	delayMicroseconds(PULSELENGTH);
	digitalWrite(pin, 0); // Get back to zero level
}

double getDistCM(int pin, int mode) {
	timeval t1, t2;
	double elapsedTime;
	int exitcounter = 0;

	if (mode==1) pinMode(pin,INPUT);

	while (digitalRead(pin) == 0) { 
		delayMicroseconds(1); 
		exitcounter++; 
		if (exitcounter>1000) return -1.0; // out of range, no echo received
	}

	// Incoming echo - determining the pulse length
	gettimeofday(&t1, NULL);
	while (digitalRead(pin) == 1) { delayMicroseconds(1);  }
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_usec - t1.tv_usec);
	return (elapsedTime/14.5);
}


Ultrasonic::Ultrasonic() {
	// default pins
	echo = 7;
	trigger = 7;
	mode = 1;
	distanceCm = 0.0;
	if (wiringPiSetup()==-1) 
		mode = -1;
}

Ultrasonic::Ultrasonic(int trigger, int echo) {
	// default pins
	this->echo = echo;
	this->trigger = trigger;
	mode = (trigger==echo?1:0;
	distanceCm = 0.0;
	if (wiringPiSetup()==-1) 
		mode = -1;
}

Ultrasonic::Ultrasonic(const Ultrasonic& orig) {
}

Ultrasonic::~Ultrasonic() {
}

void Ultrasonic::init() {
	this->update();
}


void Ultrasonic::update() {
        sendPulse(echo, mode);
        distanceCm = getDistCM(trigger, mode);
}

double Ultrasonic::getDistanceCm() {
	return distanceCm;
}

int Ultrasonic::getCycleLength() {
	return 0;
}
