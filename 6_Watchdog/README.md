# Project: Handling a Watchdog Timer with Atmega328p Microcontroller

## The aim
The aim of this project is to design a simple application that demonstrates the use of watchdog timer in Atmega328p microcontroller. In this application, the LED is controlled over input from USB to TTL Serial Adapter Module. If 'S' is pressed then LED is ON. If 'R' is pressed then LED is OFF. If 'A' is pressed then the watchdog timer resets the main program after a 2 second. The Embedded C is applied to compile program using Makefile within Vim editor. 
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
      6- Traffic Light LED Display Module
      7- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      8- 10 kΩ resistor
      9- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/096e833e-1f70-4501-b106-f18ec2d3fe26" width="800">
