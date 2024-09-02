# Project: 74HC595 shift register SPI interface with Atmega328p Microcontroller

## The aim
The aim of this application is to use the SPI communication protocol of the Atmega328p microcontroller to interface with 74HC595 serial in parallel out shift register. The 74HC595 shift register is used to drive a single common cathode seven-segment LED display. The Atmega328p microcontroller send hex values from 0 to F to the 74HC595. The digits 0 to F should show in ascending order on the seven-segment LED display, and then repeat. The Embedded C is applied to compile program using Makefile within Vim editor.
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
      7- 24MHz 8-Channel USB Logic Analyzer Device
      8- One 74HC595 shift register IC
      9- 10 kΩ resistor
      10- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/6b356195-a076-40d3-94dc-9babefa3def7" width="800">
