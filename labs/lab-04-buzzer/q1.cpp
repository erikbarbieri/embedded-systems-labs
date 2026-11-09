#include "mbed.h"

// IR sensor input pin
DigitalIn optoSensor(p15);

// Potentiometer input pin
// AnalogIn potentiometer(p14);

// Buzzer/LED output pin
PwmOut buzzer(p21);

DigitalOut debugLED(LED1);

constexpr float frequencies[] = {
    523, 622, 698, 740, 698, 622, 523, 466, 587, 523
};

constexpr int durations_ms[] = {
    180, 180, 180, 180, 180, 180, 350, 160, 160, 450
};

void setBuzzerPitch(float frequency){
    buzzer.period(1.0f / frequency);
}

// Trying to replicate the Among Us sound here
void playBuzzerSound(){
    // Among Us sound notes:
    // C - D# - F - F# - F - D# - C ... A# - D - C
    for (int i = 0; i < 10; i++) {
        setBuzzerPitch(frequencies[i]);
        buzzer.write(0.5);

        // Tweaking this to get the timing to be more correct for the among us sound
        constexpr float TIMING_TUNING = 1.9;

        ThisThread::sleep_for(
            std::chrono::milliseconds(static_cast<int>(durations_ms[i] * TIMING_TUNING))
        );

        // Brief silence between notes, sounds better this way
        buzzer.write(0.0);

        // Brief pause after 7th note
        if (i == 6) {
            ThisThread::sleep_for(160ms);
        } else {
            ThisThread::sleep_for(40ms);
        }
    }
}

int main()
{
    while (true) {
        if(optoSensor.read() == 1){
            debugLED.write(1);
            playBuzzerSound();
        }
        else{
            debugLED.write(0);
        }
        ThisThread::sleep_for(1s);
    }
}
