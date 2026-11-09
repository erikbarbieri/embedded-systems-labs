#include "mbed.h"

// Opto sensor
DigitalIn optoSensor(p15);

// Push bottom transistors
DigitalIn whitePush(p10);
DigitalIn blackPush(p11);
DigitalIn yellowPush(p12);

// TODO HERE
DigitalOut whitePushLED(LED4);
DigitalOut blackPushLED(LED3);
DigitalOut yellowPushLED(LED2);

// Segments on the 7 Segment Display
DigitalOut bottomLeft(p17);
DigitalOut bottom(p18);
DigitalOut bottomRight(p19);
DigitalOut decimalPoint(p20);
DigitalOut topRight(p21);
DigitalOut top(p22);
DigitalOut topLeft(p23);
DigitalOut middle(p24);

DigitalOut blueLED(p7);

// Displays all off segments on the 7 Segment Display
void displayOff() {
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
void displayUnknownOutput() {
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

// Displays 0 - 9 on the 7 Segment Display
void intToDisplay(int num) {
    switch (num) {
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

bool isPushed = false;
bool whiteBit = false;
bool blackBit = false;
bool yellowBit = false;
int timer = 0;
int counter = 0;

int getCountFromBits() {
    counter = 0;
    if (whiteBit)
        counter += 1;
    if (blackBit)
        counter += 2;
    if (yellowBit)
        counter += 4;
    return counter;
}

void displayBitLEDs() {
    if (whiteBit) {
        whitePushLED = 1;
    }
    else {
        whitePushLED = 0;
    }
    if (blackBit) {
        blackPushLED = 1;
    }
    else {
        blackPushLED = 0;
    }
    if (yellowBit) {
        yellowPushLED = 1;
    }
    else {
        yellowPushLED = 0;
    }
}

// main() runs in its own thread in the OS
int main()
{
    while (true) {

        displayBitLEDs();
        intToDisplay(getCountFromBits());

        while (whitePush.read() == 1) {
            isPushed = true;

            if (whiteBit == false) {
                whiteBit = true;
            }
            else if (whiteBit == true) {
                whiteBit = false;
            }

            displayBitLEDs();

            while (true) {
                if (whitePush.read() == 0) {
                    isPushed = false;
                    break;
                }
            }
        }

        while (blackPush.read() == 1) {
            isPushed = true;

            if (blackBit == false) {
                blackBit = true;
            }
            else if (blackBit == true) {
                blackBit = false;
            }

            displayBitLEDs();

            while (true) {
                if (blackPush.read() == 0) {
                    isPushed = false;
                    break;
                }
            }
        }

        while (yellowPush.read() == 1) {
            isPushed = true;

            if (yellowBit == false) {
                yellowBit = true;
            }
            else if (yellowBit == true) {
                yellowBit = false;
            }

            displayBitLEDs();

            while (true) {
                if (yellowPush.read() == 0) {
                    isPushed = false;
                    break;
                }
            }
        }

        // this starts the countdown
        if (optoSensor.read() == 1) {
            // count down from set point
            timer = getCountFromBits();

            for (int i = timer; i >= 0; i--) {
                intToDisplay(i);
                ThisThread::sleep_for(1s);
            }
        }
    }
}
