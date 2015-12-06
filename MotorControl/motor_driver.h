#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include <exception>
#include <cstdio>

class MotorDriverException : public std::exception {
	const char * what () const throw ()
	{
		return "Opening /dev/servoblaster failed!";
	}
};

class MotorDriver {

    public:
        static MotorDriver * getInstance()
        {
            static MotorDriver instance;           
            return &instance;
        }

	void setSpeed(int servopin, int pulsewidth) 
	{
		//if (fid_servoblaster==NULL) throw MotorDriverException();
		fprintf(fid_servoblaster, "%d=%d\n", servopin, pulsewidth);
		fflush(fid_servoblaster);
	}

    private:
        MotorDriver() {
		fid_servoblaster=fopen("/dev/servoblaster","w");
		if (fid_servoblaster==NULL) {
			throw MotorDriverException();
		}
	};       

	~MotorDriver() {
		fclose(fid_servoblaster);
	}


        MotorDriver(MotorDriver const&)     = delete;
        void operator=(MotorDriver const&)  = delete;

//	int minWidth = 700;
//	int maxWidth = 2000;
	FILE* fid_servoblaster;
};



#endif
