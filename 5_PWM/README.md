# Project: Phase Correct PWM with Atmega328p Microcontroller

## The aim
The advantage of using PWM mode in Atmega328p microcontroller is that it is an in-built hardware unit for waveform generation and once we set the PWM mode and duty cycle, this unit starts generating PWM and the controller can do other work. ATmega328p micrcontroller Timer/Counter0 can be used to generate two kinds of PWM signals which are Fast PWM and Phase Correct PWM. The aim of this project is to control LED brightness using Phase Correct PWM mode.The 24MHz 8-Channel USB Logic Analyzer Device is used here to monitor the PWM features, such as frequency and duty cycle. The Embedded C is applied to compile program using Makefile within Vim editor.
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
      6- Oscilloscope
      7- 24MHz 8-Channel USB Logic Analyzer Device
      8- One LED
      9- 330 Ω resistor
      10- 10 kΩ resistor
      11- Two 22 pF ceramic capacitors
```

## The main circuit diagram

<img src="https://github.com/user-attachments/assets/67156b84-4133-4813-b125-c27fe6b854be" width="800">
