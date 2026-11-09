#include "mbed.h"

// global variables
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);

// displays 0 to 7 in binary using the LEDs
int main()
{
    int i;
    while (true) {
        for(i = 0; i < 8; i++){
            myled1 = (i >> 0) & 1;
            myled2 = (i >> 1) & 1;
            myled3 = (i >> 2) & 1;
            ThisThread::sleep_for(500ms);
        }
    }
}

