#include "mbed.h"

// Segments on the 7 Segment Display
DigitalOut bottomLeft(p17);
DigitalOut bottom(p18);
DigitalOut bottomRight(p19);
DigitalOut decimalPoint(p20);
DigitalOut topRight(p21);
DigitalOut top(p22);
DigitalOut topLeft(p23);
DigitalOut middle(p24);

// Dip Switch switches
DigitalOut switch1(p10);
DigitalOut switch2(p11);
DigitalOut switch3(p12);
DigitalOut switch4(p13);
DigitalOut switch5(p14);
DigitalOut switch6(p15);

// LEDs
DigitalOut redLED(p7);
DigitalOut blueLED(p8);

// Displays all off segments on the 7 Segment Display
void displayOff(){
    bottomLeft = 0;
    bottom = 0;
    bottomRight = 0;
    decimalPoint = 0;
    topRight = 0;
    top = 0;
    topLeft = 0;
    middle = 0;
}

// Displays a figure 8 shape + decimal point snaking at a fixed rate
// This is to be visually distinct to serve as an unknown output
void displayUnknownOutput(){
    displayOff();
    
    constexpr auto SNAKE_SPEED = 20ms;

    ThisThread::sleep_for(SNAKE_SPEED);
    topLeft = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    top = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    topRight = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    middle = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    bottomLeft = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    bottom = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    bottomRight = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
    decimalPoint = 1;
    ThisThread::sleep_for(SNAKE_SPEED);
}

// Displays letters a - z on the 7 Segment Display
// Need to implement letters other than those used in "go" and "end" and "p"
void charToDisplay(char c){
    switch (c){
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 0;
            topLeft = 0;
            middle = 1;
            break;
        case 'e':
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 0;
            decimalPoint = 0;
            topRight = 0;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        case 'f':
            break;
        case 'g':
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 0;
            top = 1;
            topLeft = 1;
            middle = 0;
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            break;
        case 'k':
            break;
        case 'l':
            break;
        case 'm':
            break;
        case 'n':
            bottomLeft = 1;
            bottom = 0;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 0;
            top = 0;
            topLeft = 0;
            middle = 1;
            break;
        case 'o':
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 0;
            top = 0;
            topLeft = 0;
            middle = 1;
            break;
        case 'p':
            bottomLeft = 1;
            bottom = 0;
            bottomRight = 0;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        case 'q':
            break;
        case 'r':
            break;
        case 's':
            break;
        case 't':
            break;
        case 'u':
            break;
        case 'v':
            break;
        case 'w':
            break;
        case 'x':
            break;
        case 'y':
            break;
        case 'z':
            break;
        case '.':
            break;
        default:
            displayUnknownOutput();
            break;
    }
}

void displayString(const char* str){
    constexpr int MAX_STRING_LENGTH = 1000;
    int i = 0;
    // Loop through the string until null terminator is reached
    while(str[i] != '\0'){
        charToDisplay(str[i]);
        ThisThread::sleep_for(2s);
        i++;

        // The string is either too big or lacks a null terminator
        // Exit the loop!
        if(i >= MAX_STRING_LENGTH){
            break;
        }
    }
}

// Displays 0 - 9 on the 7 Segment Display
void intToDisplay(int num){
    switch (num){
        case 0:
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 1;
            middle = 0;
            break;
        case 1:
            bottomLeft = 0;
            bottom = 0;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 0;
            topLeft = 0;
            middle = 0;
            break;
        case 2:
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 0;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 0;
            middle = 1;
            break;
        case 3:
            bottomLeft = 0;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 0;
            middle = 1;
            break;
        case 4:
            bottomLeft = 0;
            bottom = 0;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 0;
            topLeft = 1;
            middle = 1;
            break;
        case 5:
            bottomLeft = 0;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 0;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        case 6:
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 0;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        case 7:
            bottomLeft = 0;
            bottom = 0;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 0;
            middle = 0;
            break;
        case 8:
            bottomLeft = 1;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        case 9:
            bottomLeft = 0;
            bottom = 1;
            bottomRight = 1;
            decimalPoint = 0;
            topRight = 1;
            top = 1;
            topLeft = 1;
            middle = 1;
            break;
        default:
            displayUnknownOutput();
            break;
    }
}

// True when all switches are open
// False when at least 1 is closed
bool dipSwitchOpen(){
    if(switch1.read() == 1)
        return false;
    if(switch2.read() == 1)
        return false;
    if(switch3.read() == 1)
        return false;
    if(switch4.read() == 1)
        return false;
    if(switch5.read() == 1)
        return false;
    if(switch6.read() == 1)
        return false;
    
    return true;
}

// Reads dip switches to return a PWM speed
// Higher number is faster blinking
// Highest closed switch takes precedence
int readBlinkSpeed(){
    if(switch6.read() == 1){
        return 6;
    }
    if(switch5.read() == 1){
        return 5;
    }
    if(switch4.read() == 1){
        return 4;
    }
    if(switch3.read() == 1){
        return 3;
    }
    if(switch2.read() == 1){
        return 2;
    }
    if(switch1.read() == 1){
        return 1;
    }
    return 0;
}

// red led blinks twice as slow as the blue led
void displayBlinks(const int& delay){
    // blue led on, red led on
    redLED = 1;
    blueLED = 1;

    // wait for blue led
    wait_us(delay);

    //blue led off, red led unchanged
    blueLED = 0;

    // wait for blue led
    wait_us(delay);

    // blue led on, red led unchanged
    blueLED = 1;

    // wait for both
    wait_us(delay);

    // blue led off, red led off
    blueLED = 0;
    redLED = 0;

    // wait for blue
    wait_us(delay);

    // blue led on, red led unchanged
    blueLED = 1;

    // wait for blue
    wait_us(delay);

    // blue led off, red led unchanged
    blueLED = 0;

    // wait for both
    wait_us(delay);
}

void blinkLEDs(){
    // 50000 us = 0.05 s
    constexpr int MAX_WAIT_US = 50000;

    int blinkSpeed = readBlinkSpeed();

    // Display the current blink speed on the seven segment display
    // Speed "0" is slowest and when no switch is closed, speed "6" is fastest
    intToDisplay(blinkSpeed);

    int current_wait_us = MAX_WAIT_US;

    if(blinkSpeed > 0){
        current_wait_us = MAX_WAIT_US / blinkSpeed;
    }

    displayBlinks(current_wait_us);
}

// !!! IMPORTANT !!!
// Please control the blink speed using the Dip Switch.
// The 7 Segment Display will show your current speed from 0 to 6, slow to fast
int main()
{
    while (true) {
        // !!! IMPORTANT !!!
        // Please control the blink speed using the Dip Switch.
        // The 7 Segment Display will show your current speed from 0 to 6, slow to fast
        blinkLEDs();
    }
}

