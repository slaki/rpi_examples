CC=g++
CFLAGS=-std=c++0x -Wall
IMULIB=-lRTIMULib

all: test_accelerometer

test_accelerometer:
	$(CC) $(CFLAGS) $(IMULIB) sensor.cpp DataMPU9150.cpp test_accelerometer.cpp -o test_accelerometer

clean:
	rm -f test_accelerometer
