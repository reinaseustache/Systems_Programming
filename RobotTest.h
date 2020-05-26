#include <bcm2835.h>
#include <stdio.h>
#include <pthread.h>
#include "Robot.h"
#include "Sensor.h"

#ifndef ROBOTTEST
#define ROBOTTEST

// Moves Robi forward if there are no objects in coming up 
// in his way otherwise if his is at most 30 cm away from an
// obstacle he moves backward and tries to go another direction
void *runRobi(void * null);

// Continually reads from the sonic sensor and updates the 
// distance variable as Robi is moving
void *calculateDistance(void * null);

#endif

