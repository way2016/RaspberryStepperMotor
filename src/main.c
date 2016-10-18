#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "gpio.h"

#define pin1 19
#define pin2 20
#define pin3 21
#define pin4 26

int StepCount = 4;
int StepDir = -1;
//int WaitTime = 400;
int WaitTime = 20;
int StepCounter = 0;
int Seq[4][4] = {{0,1,0,1},{1,0,0,1},{1,0,1,0},{0,1,1,0}};
int XPin;
int StepPins[4] = { pin1, pin2, pin3, pin4};
int i = 0;

int main(int argc, char *argv[]) {
    printf("Starting LittleCrane\n");

    if( argc >= 1) {
	
    }

    gpio_setup_io();

    gpio_direction_output(pin1);
    gpio_direction_output(pin2);
    gpio_direction_output(pin3);
    gpio_direction_output(pin4);
    
 
 
//    gpio_direction_output(7);
//    gpio_direction_output(8);

//    gpio_clear(8);

    for (;;) {
//        gpio_set(7);
//        usleep(400);

//        gpio_clear(7);

        for( i = 0; i < 4; i++) {
		XPin = StepPins[i]; 
		if( Seq[StepCounter][i] != 0) {
			gpio_set(XPin);
		} 
		else {
			gpio_clear(XPin);
		}
        	usleep(WaitTime);
	}
	StepCounter += StepDir;
	if( StepCounter >= StepCount) {
		StepCounter = 0;
	}
	if( StepCounter < 0) {
		StepCounter = StepCount + StepDir;
	}

        usleep(WaitTime);
    }
}
