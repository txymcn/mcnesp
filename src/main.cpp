/*
EEEN20011 - Blinky

This program will flash the onboard green LED at 0.5Hz (the green LED under the blue application shield board)

*/

#include "mbed.h"

DigitalOut LD2(D13); // Creating a digitalout object assigned to pin D13

int main()                                          //Begin main function - program starts executing here.
{
    while(1) {                                      //Main while() loop
        LD2 = 1;
        wait_us(1e6);
        LD2 = !LD2;
        wait_us(1e6);
    }
}
