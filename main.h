// Reina Eustache 
// Binary Counter
// Due 04/13/2020 11:59 pm
// main.h
// This header file contains header files along with the macro
// needed for main.c which continuously calls the readButtonPress
// function that returns the number of times a button is pressed
// and passes that value to the binaryCounter function which lights 
// up two LEDs representing the number of times the button was pressed.

#ifndef Main_H
#define Main_H

#include <bcm2835.h>
#include "readButtonPress.h"
#include "binaryCounter.h"

#define PINONE RPI_V2_GPIO_P1_11 // left bit
#define PINTWO RPI_V2_GPIO_P1_13 // right bit
#define PINTHREE RPI_V2_GPIO_P1_15 // button

#endif
