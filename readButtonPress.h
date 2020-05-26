// Reina Eustache
// Binary Counter
// Due 04/13/2020 11:59 pm
// readButtonPress.h
// This header file contains header files along with the macro
// needed for readButtonPress.c which returns the number of
// times a button is pressed.

#ifndef ReadButtonPress_H
#define ReadButtonPress_H

#include <bcm2835.h>

// int readButtonPress
// Description: This function accepts an integer for the pin
// of the button to read from and uses a flag variable that 
// is set to true with the button is released in order to
// increment the static counter variable that is used to
// keep track of the number of times the button has been pressed.
// It returns a binary value (number from 0 to 3) for the
// number of times the button has been pressed
int readButtonPress(int pin);

#endif
