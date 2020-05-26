#include "Robot.h"

extern void initRobot(){
	int stopAtExit = 1;

	initHat(); // initialize Robi's motors and the motor hat
	
	run(RELEASE, 0);
	run(RELEASE, 1);

	if(stopAtExit){
		atexit(stop);
	}
}

extern void leftSpeed(unsigned int speed){
	if ((speed < 0) || (speed > 255)) // invalid speed
		printf("Speed must be between 0 and 255");

	speed = max(0, min(255, speed));

	setPWM(motors[0].pwm, 0, speed*16); // set speed
}

extern void rightSpeed(unsigned int speed){
	if ((speed < 0) || (speed > 255)) // invalid speed
		printf("Speed must be between 0 and 255");

	speed = max(0, min(255, speed));

	setPWM(motors[1].pwm, 0, speed*16); // set speed
}

extern void stop(){
	run(RELEASE, 0);
	run(RELEASE, 1);
}

extern void forward(unsigned int speed, double seconds){
	leftSpeed(speed);
	rightSpeed(speed);

	run(FORWARD, 0);
	run(FORWARD, 1);

	if (seconds != 0){ // run for specified amount of time
		bcm2835_delay(seconds * 1000);
		stop();
	}
}

extern void backward(unsigned int speed, double seconds){
	leftSpeed(speed);
	rightSpeed(speed);

	run(BACKWARD, 0);
	run(BACKWARD, 1);

	if (seconds != 0){ // run for specified amount of time
		bcm2835_delay(seconds * 1000);
		stop();
	}
}

extern void right(unsigned int speed, double seconds){
	leftSpeed(speed);
	rightSpeed(speed);

	run(FORWARD, 0);
	run(BACKWARD, 1);

	if(seconds != 0){ // run for specified amount of time
		bcm2835_delay(seconds * 1000);
		stop();
	}
}

extern void left(unsigned int speed, double seconds){
	leftSpeed(speed);
	rightSpeed(speed);

	run(BACKWARD, 0);
	run(FORWARD, 1);

	if (seconds != 0){ // run for specified amount of time
		bcm2835_delay(seconds * 1000);
		stop();
	}
}