# Project: Handling the USART module with Atmega328p Microcontroller

## The aim
The Atmega328p microcontroller has flexible USART module, which can be used for serial communication with other devices like computers, serial GSM, GPS modules, etc. Normally in USART protocol communication, we only need Tx(Transmit), Rx(Receive), and GND wires. The Atmega328p microcontroller USART module has a TTL voltage level which is 0V for logic 0 and 5V for logic 1.
The aim of this project is to show how to use the USART module with the Atmega328p Microcontroller. The Embedded C is applied to compile program using Makefile within Vim editor. 
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
      6- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      7- 10 kΩ resistor
      8- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/da512ecf-4c4f-4474-98ef-805816bcaef4" width="800">
