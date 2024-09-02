# Project: 74HC165 shift register SPI interface with Atmega328p Microcontroller

## The aim
Reading a digital data from 74HC165 shift register require the SPI module of the microcontroller. The aim of this application is to use the SPI communication protocol of the Atmega328p microcontroller to read the digital data from 74HC165 shift register and transfer the result through UART serial communication protocol. The Embedded C is applied to compile program using Makefile within Vim editor.
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
      6- 24MHz 8-Channel USB Logic Analyzer Device
      7- One 74HC165 shift register IC
      8- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      9- One DIP switch
      10- Five 10 kΩ resistors
      11- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/6bac0e67-c7f3-4a96-a3b7-0a8089593b72" width="800">
