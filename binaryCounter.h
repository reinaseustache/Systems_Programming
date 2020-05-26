// Reina Eustache
// Binary Counter
// Due 04/13/2020 11:59 pm
// binaryCounter.h
// This header file contains header files along with the macro
// needed for binaryCounter.c which lights up two LEDs based on a
// binary number.

#ifndef BinaryCounter_H
#define BinaryCounter_H

#include <bcm2835.h>

// void binaryCounter
// Description: This function accepts two numbers for the pins to light up
// along with a number to light up and lights up two LEDs, a series of
// conditions checks for which number was passed in in order to behave
// appropriately
void binaryCounter(int pinOne, int pinTwo, int times);

#endif
