#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "motor_driver.h"

class Motor {
	private:
		int m_servopin;
		int m_pulsewidth;
		MotorDriver *driver;
	public:
		static const int minPulseWidth = 1000;
		static const int maxPulseWidth = 2000;

		Motor(int servopin);
		Motor();
		~Motor();
		
		void init(int servopin);
		void setSpeed(int pulsewidth);
		int getSpeed();		
		void stop();
};



#endif
