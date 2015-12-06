CC=g++
CFLAGS=-std=c++0x -Wall
IMULIB=-lwiringPi

all: test_blinking

test_blinking:
	$(CC) $(CFLAGS) $(IMULIB) test_blinking.cpp -o test_blinking

clean:
	rm -f test_blinking
