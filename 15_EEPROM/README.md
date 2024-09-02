# Project: EEPROM in Atmega328p Microcontroller

## The aim
EEPROM is Electrically Erasable Programmable Read-Only Memory. It is non-volatile type of memory as it holds the data even when power is off. The main advantage of this memory is that microcontroller can read, modify/write this memory in runtime application. So EEPROM can be used for storing sensor values, important parameters etc. The Atmega328p microcontroller contain 1 KB of data EEPROM memory. Access over EEPROM memory is made through three registers:
```
-> EEAR (EEPROM Address register).
-> EEDR (EEPROM Data register).
-> EECR (EEPROM Control register).
```
The aim of this application is to show how to access the internal EEPROM memory of the Atmega328p microcontroller. The Embedded C is applied to compile program using Makefile within Vim editor. 
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
      7- Push-button
      8- 0.1 μF ceramic capacitor
      9- Two 22 pF ceramic capacitors
      10- 1 kΩ resistor
      11- Two 10 kΩ resistors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/61ecd03a-3059-4361-b8d8-8c23d65024d6" width="800">
