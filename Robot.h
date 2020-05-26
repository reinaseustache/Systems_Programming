#include<stdio.h>
#include<bcm2835.h>
#include"MotorHat.h"

#ifndef ROBOT
#define ROBOT

#define min(a, b) ((a < b) ? a : b) // finds min of  numbers
#define max(a, b) ((a > b) ? a : b) // finds max of  numbers

// Initializes the left and right motor and starts with the motors
// turned off by passing the release command
void initRobot();

// Set the speed of the left motor, Speed must be a value between 0 
// to 255 inclusive otherwise it will reset it if too big or too small
void leftSpeed(unsigned int speed);

// Set the speed of the right motor, Speed must be a value between 0 
// to 255 inclusive otherwise it will reset it if too big or too small
void rightSpeed(unsigned int speed);

// Stops the robot from any movement
void stop();

// Move forward at the specified speed.  Will start spinning and
// return unless a seconds value is specified, in which case the robot will
// spin for that amount of time and then stop.
void forward(unsigned int speed, double seconds);

// Move backward at the specified speed.  Will start spinning and
// return unless a seconds value is specified, in which case the robot will
// spin for that amount of time and then stop.
void backward(unsigned int speed, double seconds);

// Spin to the right at the specified speed.  Will start spinning and
// return unless a seconds value is specified, in which case the robot will
// spin for that amount of time and then stop.
void right(unsigned int speed, double seconds);

// Spin to the left at the specified speed.  Will start spinning and
// return unless a seconds value is specified, in which case the robot will
// spin for that amount of time and then stop.
void left(unsigned int speed, double seconds);

#endif