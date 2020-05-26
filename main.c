// Reina Eustache
// Binary Counter
// Due 04/13/2020 11:59 pm
// main.c
// This main function continuously calls the readButtonPress
// function that returns the number of times a button is pressed
// and passes that value to the binaryCounter function which lights
// up two LEDs representing the number of times the button was pressed.

#include "main.h"

int main(int argc, char **argv){
    if (!bcm2835_init())
        return 1;

    bcm2835_gpio_fsel(PINONE, BCM2835_GPIO_FSEL_OUTP); // left bit
    bcm2835_gpio_fsel(PINTWO, BCM2835_GPIO_FSEL_OUTP); // right bit
    
    bcm2835_gpio_fsel(PINTHREE, BCM2835_GPIO_FSEL_INPT); // button
    bcm2835_gpio_set_pud(PINTHREE, BCM2835_GPIO_PUD_UP); // button

    int rval = 0; // stores return value of readButtonPress function

    while(1){
        rval = readButtonPress(PINTHREE);
        binaryCounter(PINONE, PINTWO, rval);
    }

    bcm2835_close();

    return 0;
}
