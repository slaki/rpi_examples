#include "motor.h"
#include "kbhit.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	keyboard kb1,kb2,kb3,kb4;

	cout << "Initialize servo motors" << endl << "!!! Disconnect the battery" << endl << "Press any key..." << endl;
	cin.ignore();

	Motor *motors[4];
	for (int i=0;i<4;++i)
		motors[i] = new Motor(i);
	
	
	cout << "Setting up max. speed" << endl;
	bool repeat = true;


	cout << "!!! Connect the battery! And wait for beep-beep sound!" << endl << "After that press any key!" << endl;
	while (repeat) {
		for (int i=0;i<4;++i)
			motors[i]->setSpeed(Motor::maxPulseWidth);
		
		sleep(0.5);
		
		if (kb1.kbhit()!=0)
			repeat = false;
	}
	

	cout << "Setting up min. speed" << endl;
	cout << "!!! Wait for a long beep sound!" << endl << "After that press any key!" << endl;
	repeat = true;
	while (repeat) {
		for (int i=0;i<4;++i)
        	        motors[i]->stop();

		sleep(0.5);

		if (kb2.kbhit()!=0)
                        repeat = false;
	}
 
	cout << "Testing" << endl;

	cout << "Speed PW=750" << endl << "Press any key..." << endl;
	repeat = true;
        while (repeat) {
		for (int i=0;i<4;++i)
                	motors[i]->setSpeed(750);

                sleep(0.5);

                if (kb3.kbhit()!=0)
                        repeat = false;
        }
		
	cout << "Speed PW=850" << endl << "Press any key..." << endl;
        repeat = true;
        while (repeat) {
	        for (int i=0;i<4;++i)
        	        motors[i]->setSpeed(850);

                sleep(0.5);

                if (kb4.kbhit()!=0)
                        repeat = false;
        }

//	for (int i=0;i<4;++i)
//                        motors[i]->stop();

	for (int i=0;i<4;++i)
                delete motors[i];
}
