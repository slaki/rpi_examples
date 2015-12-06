CC=g++
CFLAGS=-std=c++0x -Wall
IMULIB=-lwiringPi

all: test_temphum

test_temphum:
	$(CC) $(CFLAGS) $(IMULIB) sensor.cpp temphum.cpp test_temphum.cpp -o test_temphum

clean:
	rm -f test_temphum
