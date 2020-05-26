// Reina Eustache
// Binary Counter
// Due 04/13/2020 11:59 pm
// binaryCounter.c
// This file contains a function which lights up two LEDs based on a
// binary number.

#include "binaryCounter.h"

void binaryCounter(int pinOne, int pinTwo, int num){
    if (num == 0){
        bcm2835_gpio_write(pinOne, LOW); // turn off left bit
        
        bcm2835_gpio_write(pinTwo, LOW); // turn off right bit
    
    }
    else if (num == 1){
        bcm2835_gpio_write(pinTwo, HIGH); // light right bit

    } else if(num == 2){
        bcm2835_gpio_write(pinTwo, LOW); // turn off right bit

        bcm2835_gpio_write(pinOne, HIGH); // light left bit
    
    } else if (num == 3){
        bcm2835_gpio_write(pinTwo, HIGH); // light right bit
    
    }
}
