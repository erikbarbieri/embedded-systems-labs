# Embedded Systems Labs

A collection of individual embedded systems lab exercises written in **C++ with the Mbed API**. The labs explore microcontroller input/output through LEDs, a seven-segment display, switches, an optical sensor, and a PWM-controlled buzzer.

Each question is a standalone program intended to run on the corresponding hardware setup. Short videos demonstrate the physical results.

## Labs

### Lab 1 - Blinky LEDs

**Concepts:** Digital output, binary representation, timing, bitwise operations.

- **[Q1 - Binary counter](labs/lab-01-leds/q1.cpp):** Cycle through the values 0-7 in binary using three LEDs.
- **[Q2 - Binary addition](labs/lab-01-leds/q2.cpp):** Iterate through pairs of values from 0-3, displaying each operand and their sum in binary on four LEDs. A short all-LED blink sequence separates the values.
- **[Demo](labs/lab-01-leds/demos/demo.mp4):** Both exercises.

### Lab 2 - Seven-Segment Display

**Concepts:** Segment control, digital inputs, DIP switches, LED timing.

- **[Q1 - Number and character display](labs/lab-02-seven-segment/q1.cpp):** Display a `go` message, cycle through digits 0-9, and then display `end`. DIP-switch settings interrupt the sequence to show a selected value on the display.
- **[Q2 - Switch-controlled LED blink rates](labs/lab-02-seven-segment/q2.cpp):** Use a six-position DIP switch to select a blink-speed level (0-6). Show the level on the seven-segment display while driving two LEDs at different rates.
- **Demos:** [Q1](labs/lab-02-seven-segment/demos/q1.mp4) , [Q2](labs/lab-02-seven-segment/demos/q2.mp4)

### Lab 3 - Optical Sensor

**Concepts:** Digital sensing, pushbutton inputs, state tracking, event counting.

- **[Q1 - Sensor-triggered countdown](labs/lab-03-opto-sensor/q1.cpp):** Use three pushbuttons to set a binary countdown value from 0-7, then start the seven-segment countdown when the optical sensor is activated. LEDs indicate the selected bits.
- **[Q2 - Object/event counter](labs/lab-03-opto-sensor/q2.cpp):** Count optical sensor activations, display the count modulo 10 on the seven-segment display, and flash an LED for feedback.
- **Demos:** [Q1](labs/lab-03-opto-sensor/demos/q1.mp4) , [Q2](labs/lab-03-opto-sensor/demos/q2.mp4)

### Lab 4 - Buzzer

**Concepts:** Pulse-width modulation (PWM), audio frequency, analog input.

- **[Q1 - Sensor-triggered melody](labs/lab-04-buzzer/q1.cpp):** Play a short sequence of notes through a PWM-controlled buzzer when the optical sensor is triggered, with an LED as a visual indicator.
- **[Q2 - Potentiometer-controlled pitch](labs/lab-04-buzzer/q2.cpp):** Read a potentiometer and continuously map its position to a buzzer frequency of approximately 100-1,000 Hz.
- **Demos:** [Q1 (with audio)](labs/lab-04-buzzer/demos/q1.mp4) , [Q2 (with audio)](labs/lab-04-buzzer/demos/q2.mp4)

## Repository layout

```text
embedded-systems-labs/
├── README.md
├── .gitignore
└── labs/
├── lab-01-leds/
│ ├── q1.cpp
│ ├── q2.cpp
│ └── demos/
│ └── demo.mp4
├── lab-02-seven-segment/
│ ├── q1.cpp
│ ├── q2.cpp
│ └── demos/
│ ├── q1.mp4
│ └── q2.mp4
├── lab-03-opto-sensor/
│ ├── q1.cpp
│ ├── q2.cpp
│ └── demos/
│ ├── q1.mp4
│ └── q2.mp4
└── lab-04-buzzer/
├── q1.cpp
├── q2.cpp
└── demos/
├── q1.mp4
└── q2.mp4
```

## Running the programs

The examples use the Mbed API (`mbed.h`) and depend on the connected board and lab circuit. **Each `q1.cpp` or `q2.cpp` has its own `main()`** and should be built and flashed **individually**. Also it's Mbed OS 6.17.0.

To reproduce a lab, create a compatible Mbed project for your target board, use the chosen question's source as the application entry point, and connect the peripherals to the pins referenced in that file. Hardware pin assignments differ by exercise! :D

## Notes

- Demonstration videos are linked using relative paths under each lab's `demos/` folder.
