#include<stdio.h>
#include<bcm2835.h>
#include<math.h>
#include"I2C.h"

#ifndef PWM
#define PWM

//Registers
#define __MODE1			0x00
#define __MODE2 		0x01
#define __SUBADR1 		0x02
#define __SUBADR2		0x03
#define __SUBADR3		0x04
#define __PRESCALE		0xFE
#define __LED0_ON_L		0x06
#define __LED0_ON_H		0x07
#define __LED0_OFF_L	0x08
#define __LED0_OFF_H	0x09
#define __ALL_LED_ON_L	0xFA
#define __ALL_LED_ON_H	0xFB
#define __ALL_LED_OFF_L	0XFC
#define __ALL_LED_OFF_H 0xFD

// Bits
#define __RESTART		0x80
#define __SLEEP			0x10
#define __ALLCALL		0x01
#define __INVRT			0x10
#define __OUTDRV		0x04

// Sets all PWM channels by doing some bit masking operations and calling the write8 funtion
// to write to the selected slave address on the I2C bus
void setAllPWM(int on, int off);

// Initializes PWM by first initializiing the the I2C bus and setting all the  PWM
// channels
void PWMInit(unsigned int address);

// Sets the PWM frequency by doing some bit masking operations and calling the write8 funtion
// to write to the selected slave address on the I2C bus
void setPWMFreq(int freq);

// Sets a single PWM channel by doing some bit masking operations and calling the write8 funtion
// to write to the selected slave address on the I2C bus
void setPWM(int channel, int on, int off);

#endif
