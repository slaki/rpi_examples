CC=g++
CFLAGS=-std=c++0x -Wall

all: calibrateESC

calibrateESC:
	$(CC) $(CFLAGS) motor.cpp kbhit.cpp calibrateESC.cpp -o calibrateESC

clean:
	rm -f calibrateESC
