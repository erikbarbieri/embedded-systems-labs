#include "mbed.h"

// IR sensor input pin
DigitalIn optoSensor(p15);

// Potentiometer input pin
AnalogIn potentiometer(p16);

// Buzzer/LED output pin
PwmOut buzzer(p21);

//DigitalOut debugLED(LED1);

constexpr float MAX_FREQUENCY = 1000;
constexpr float MIN_FREQUENCY = 100;

void setBuzzerPitch(float frequency){
    buzzer.period(1.0f / frequency);
}

int main()
{
    buzzer.write(0.5);
    while (true) {
        setBuzzerPitch((potentiometer.read() * (MAX_FREQUENCY - MIN_FREQUENCY)) + MIN_FREQUENCY);
        ThisThread::sleep_for(10ms);
    }
}
