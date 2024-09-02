# Project: Interfacing Seven-Segment LED display with the Atmega328p microcontroller using Timer/Counter1

## The aim
Generally, we use a timer/counter to generate time delays, waveforms, or to count events. Also, the timer is used for PWM generation, capturing events, etc. In the Atmega328p microcontroller, there are three timers:
```
-> Timer0: 8-bit timer
-> Timer1: 16-bit timer
-> Timer2: 8-bit timer
```
The aim of this project is to show how to control seven-segment LED display with the Atmega328p microcontroller using the 16-bit Timer/Counter1. The Embedded C is applied to compile program using Makefile within Vim editor.
To compile the embedded C code for the Atmega328p microcontroller, we need to open a terminal window, navigate to the project folder and enter the following command:
```
$ make
```
To upload the generated HEX file to the Atmega328p microcontroller, enter the following command:

```
$ avrdude -c USBasp -p m328p -B 4 -U flash:w:main.hex:i
```

## Hardware Requirements

```
      1- ATmega328P-PU microcontroller
      2- USBasp programmer
      3- 16MHz Crystal Oscillator
      4- Solderless breadboard
      5- Jumper wires
      6- One common-cathode Seven-Segment LED display
      7- 10 kΩ resistor
      8- Two 22 pF ceramic capacitor
```

## The main circuit diagram

<img src="https://github.com/user-attachments/assets/9e84d976-38ca-4c37-ac00-c34428aa775a" width="800">
