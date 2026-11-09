#include "mbed.h"

// global variables
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

// arbitrary number of times the leds blink before displaying useful info
constexpr int SIGNAL_BLINKS = 3;

// the leds blink SIGNAL_BLINKS many times
// this happens before the LEDS are
// about to display a number you care about
void imAboutToDisplaySomethingSignal(int blinks){
    for(int currentBlinks = 0; currentBlinks < blinks; currentBlinks++){
        myled1 = 1;
        myled2 = 1;
        myled3 = 1;
        myled4 = 1;
        ThisThread::sleep_for(50ms);
        myled1 = 0;
        myled2 = 0;
        myled3 = 0;
        myled4 = 0;
        ThisThread::sleep_for(50ms);
    }
}

// lights up the corresponding LEDS using a base 10 num
// 1 led = 1 bit
void lightLeds(int ledsInDecimal){
    myled1 = (ledsInDecimal >> 0) & 1;
    myled2 = (ledsInDecimal >> 1) & 1;
    myled3 = (ledsInDecimal >> 2) & 1;
    myled4 = (ledsInDecimal >> 3) & 1;
}

// sums num1 and num2, and it displays num1 then num2 then sum each loop
int main()
{
    int num1, num2, sum;
    // inclusive
    constexpr int MAX_NUM = 3;
    while (true) {
        for(num1 = 0; num1 <= MAX_NUM; num1++){
            for(num2 = 0; num2 <= MAX_NUM; num2++){
                // double the signal blinks here so that
                // it's more obvious it's starting a new calculation
                imAboutToDisplaySomethingSignal(SIGNAL_BLINKS * 2);
                lightLeds(num1);
                ThisThread::sleep_for(1500ms);

                imAboutToDisplaySomethingSignal(SIGNAL_BLINKS);
                lightLeds(num2);
                ThisThread::sleep_for(1500ms);
                
                sum = num1 + num2;

                imAboutToDisplaySomethingSignal(SIGNAL_BLINKS);
                lightLeds(sum);
                ThisThread::sleep_for(3000ms);
            }
        }
    }
}

