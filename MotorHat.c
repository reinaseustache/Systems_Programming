#include "MotorHat.h"

extern void initMotors(int num){
	int pwm = 0;
	int in1 = 0;
	int in2 = 0;

	if (num == 0){ // motor 1
		pwm = 8;
		in2 = 9;
		in1 = 10;
	} else if (num == 1){ // motor 2
		pwm = 13;
		in2 = 12;
		in1 = 11;
	} else if (num == 2){
		pwm = 2;
		in2 = 3;
		in1 = 4;
	} else if (num == 3){
		pwm = 7;
		in2 = 6;
		in1 = 5;
	} else
		printf("MotorHat Motor must be between 0 and 3");
	
	motors[num].pwm = pwm;
	motors[num].in1 = in1;
	motors[num].in2 = in2;
}

extern void initHat(){
	// initialize Robi's motors
	initMotors(0);
	initMotors(1);

	PWMInit(0x60); // initialize PWM
	setPWMFreq(1600); // set frequency
}

extern void run(unsigned char command, unsigned char motorID){
	if (command == FORWARD){
		setPin(motors[motorID].in2, 0);
		setPin(motors[motorID].in1, 1);
	}

	if (command == BACKWARD){
		setPin(motors[motorID].in1, 0);
		setPin(motors[motorID].in2, 1);
	}

	if (command == RELEASE){
		setPin(motors[motorID].in1, 0);
		setPin(motors[motorID].in2, 0); 
	}
}

extern void setPin(unsigned char pin, unsigned char value){
	if ((pin < 0) || (pin > 15)) // invalid pin
		printf("PWM must be between 0 and 15 inclusive");

	if ((value != 0) && (value != 1)) // invalid value
		printf("Pin value must be 0 or 1");

	if (value == 0)
		setPWM(pin, 0, 4096);

	if (value == 1)
		setPWM(pin, 4096, 0);
}
