CC=g++
CFLAGS=-std=c++0x -Wall
IMULIB=-lwiringPi

all: test_pir

test_pir:
	$(CC) $(CFLAGS) $(IMULIB) sensor.cpp pir.cpp test_pir.cpp -o test_pir

clean:
	rm -f test_pir
