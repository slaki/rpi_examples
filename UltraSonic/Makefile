CC=g++
CFLAGS=-std=c++0x -Wall
IMULIB=-lwiringPi

all: test_ultrasonic

test_accelerometer:
	$(CC) $(CFLAGS) $(IMULIB) sensor.cpp ultrasonic.cpp test_ultrasonic.cpp -o test_ultrasonic

clean:
	rm -f test_ultrasonic
