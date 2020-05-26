#include<stdio.h>
#include<bcm2835.h>
#include"PWM.h"

#ifndef MOTOR_HAT
#define MOTOR_HAT

// structure for each motor
typedef struct MOTOR{
	int pwm;
	int in2;
	int in1;
}motor;

motor motors[4];

#define FORWARD 	1
#define BACKWARD 	2
#define BRAKE		3
#define RELEASE		4

#define SINGLE		1
#define	DOUBLE		2
#define INTERLEAVE	3
#define MICROSTEP	4

// Initializes a specific motor in the motors array based on the number passed in and sets the pwm according to the motor
void initMotors(int num);

// Sets the default address and frequency on the HAT as will as initializes each of the 
// motors in the motors array (the first 2 since Robi only has 2 motors)
void initHat();

// Take a command - FORWARD, BACKWARD or RELEASE and sets the pins accordingly to 
// run the specific motor
void run(unsigned char command, unsigned char motorID);

// Takes a pin between 1 and 16 and a value of 0 or 1 and set a single PWM channel
void setPin(unsigned char pin, unsigned char value);

#endif
