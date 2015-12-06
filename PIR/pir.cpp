/*
 * File:   pir.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * 
 *
 * Created on 2015
 */

#include "pir.h"
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

PIR::PIR() {
	// default pins
	on = false;
	pin = 7;

	if (wiringPiSetup()==-1) return;
}

PIR::PIR(int pin) {
	on = false;
	this->pin = pin;

	if (wiringPiSetup()==-1) return;
}

PIR::PIR(const PIR& orig) {
}

PIR::~PIR() {
}

void PIR::init() {
	pinMode(pin, INPUT);
	this->update();
}


void PIR::update() {
	on = (digitalRead(pin) == HIGH); 
}

int PIR::getCycleLength() {
	return 0;
}

bool PIR::isOn() {
	return on;
}
