# Project: Building a Single-Digit Numerical Counter with Atmega328p Microcontroller

## The aim

The aim of this project is to show how to interface seven-segment LED display with the Atmega328p microcontroller.The Embedded C is applied to compile program using Makefile within Vim editor.
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
      7- One Push-button
      8- Two 10 kΩ resistors
      9- 1 kΩ resistor
      10- 0.1 μF ceramic capacitor
      11- Two 22 pF ceramic capacitor
```

## The main circuit diagram

<img src="https://github.com/user-attachments/assets/928fec78-74f6-49d0-a788-ad3653db7bbd" width="800">
