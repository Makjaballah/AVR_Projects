# Project: Read an GPIO pin as an input using push-button to turn on an LED with Atmega328p Microcontroller

## The aim

In this project, a push-button and an LED are used. The push-button is connected to GPIO port PD7 of the Atmega328p microcontroller. LED is connected through the GPIO port PB0 of the microcontroller. The LED is turned ON whenever the button is pressed. The aim of this project is to show how the state of a button can be read in a program. The Embedded C is applied to compile program using Makefile within Vim editor. 
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
      6- One LED
      7- One Push-button
      8- 330 Ω resistor
      9- Two 10 kΩ resistors
      10- 1 kΩ resistor
      11- 0.1 μF ceramic capacitor
      12- Two 22 pF ceramic capacitors
```

## The main circuit diagram

<img src="https://github.com/user-attachments/assets/9582c911-4680-495b-a30c-4914ebec9ea4" width="800">
