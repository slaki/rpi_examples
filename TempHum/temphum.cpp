/*
 * File:   temphum.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Sensor su
 *
 * Created on 2015
 */

#include "temphum.h"
#include <stdio.h>
#include <sys/time.h>
#include <wiringPi.h>

#define MAX_TIME 100

Temphum::Temphum() {
	// default pins
	temp = 0.0;
	hum = 0.0;
	pin = 7;

	if (wiringPiSetup()==-1) return;
}

Temphum::Temphum(int pin) {
	// default pins
	temp = 0.0;
	hum = 0.0;
	this->pin = pin;

	if (wiringPiSetup()==-1) return;
}

Temphum::Temphum(const Temphum& orig) {
}

Temphum::~Temphum() {
}

void Temphum::init() {
	this->update();
}


void Temphum::update() {
	int dht11_val[5]={0,0,0,0,0};
	
	uint8_t lststate=HIGH;
	uint8_t counter=0;  
	uint8_t j=0,i;  
	float farenheit;

	for(i=0;i<5;i++)  
		dht11_val[i]=0;  

	pinMode(pin, OUTPUT);  
	digitalWrite(pin, LOW);  
	delay(18);  
	digitalWrite(pin, HIGH);
	delayMicroseconds(40);
	pinMode(pin, INPUT);

	for(i=0;i<MAX_TIME;i++)  
	{  
		counter=0;  
		while(digitalRead(pin)==lststate) {  
			counter++;  
			delayMicroseconds(1);  
			if(counter==255)  
				break;  
		}
  
		lststate=digitalRead(pin);  
		if(counter==255)  
			break;

		// top 3 transistions are ignored  
		if((i>=4)&&(i%2==0)){  
			dht11_val[j/8]<<=1;  
			if(counter>16)  
				dht11_val[j/8]|=1;  
			j++;  
		}  
	}  

	// verify cheksum and print the verified data  
	if((j>=40)&&(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)))  
	{  
		temp = 1.0 * dht11_val[2];
		hum = 1.0 * dht11_val[0];
 
		//printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit);  
	}  
	else
	{
		temp = -100.0;
		hum = -100.0;
		// printf("Invalid Data!!\n");
	}

}

double Temphum::getTemperature() {
	return temp;
}

double Temphum::getHumidity() {
        return hum;
}

int Temphum::getCycleLength() {
	return 0;
}
