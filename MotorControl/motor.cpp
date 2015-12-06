#include "motor_driver.h"
#include "motor.h"

Motor::Motor(int servopin)
{
	m_servopin = servopin;
	m_pulsewidth = minPulseWidth;
	driver = MotorDriver::getInstance();
}

Motor::Motor()
{
        m_servopin = 0;
        m_pulsewidth = minPulseWidth;
        driver = MotorDriver::getInstance();
}

Motor::~Motor()
{
	stop();
}
		
void Motor::init(int servopin)
{
	m_servopin = servopin;
}

void Motor::setSpeed(int pulsewidth)
{
	if (pulsewidth>maxPulseWidth) m_pulsewidth = maxPulseWidth;
	else if (pulsewidth<minPulseWidth) m_pulsewidth = minPulseWidth;
	else m_pulsewidth = pulsewidth;

	driver->setSpeed(m_servopin, m_pulsewidth);
}

int Motor::getSpeed()
{
	return m_pulsewidth;
}
		
void Motor::stop()
{
	setSpeed(minPulseWidth);
}

