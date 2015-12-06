/*
 * File:   test_blinking.cpp
 * Author: Sandor Laki, lakis@inf.elte.hu
 *
 * Description:
 * Test code for blinking a LED
 *
 * Created on 2015
 */

#include <wiringPi.h>
#include <stdio.h>

#define PIN 7
#define MAXITER 60

int main (void)
{
  if (wiringPiSetup()==-1) return -1;

  pinMode(PIN, OUTPUT);

  for (int i=0;i<MAXITER;++i)
  {
	printf("Iteration: #%d\n", i);
	// Turn the LED on, and wait 500 ms
	digitalWrite(PIN, HIGH); 
	delay(500);

	// Turn it off and wait 500 ms
	digitalWrite(PIN, LOW); 
	delay(500);
  }
  return 0;
}
