#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>

#ifndef SENSOR
#define SENSOR

#define ECHO RPI_V2_GPIO_P1_18
#define TRIG RPI_V2_GPIO_P1_16

// Resets the ECHO and TRIG pins and selects them for input
// from the sonic sensor
void gpio_reset();

// Gets the current time of day
double get_time();

// Retuns a decimal of the current distance of the nearest
// object away from the sonic sensor
float getDistance();

#endif
