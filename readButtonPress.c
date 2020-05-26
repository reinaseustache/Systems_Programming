// Reina Eustache 
// Binary Counter
// Due 04/13/2020 11:59 pm
// readButtonPress.c
// This file contains a function which returns the number of
// times a button is pressed.

#include "readButtonPress.h"

int readButtonPress(int pin){
    static int count = 0; //keeps total number of button presses
    int flag = 1;

    while(1){
        uint8_t value = bcm2835_gpio_lev(pin);

        if ((value != flag)){ // when pressed or released
            flag = value;

            if(flag == 1){ // after its done being pressed
                count++;
                break;
            }
        }
        
        delay(500);
    }

    return count % 4;
}
