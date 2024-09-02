# Project: Using the Atmega328p Microcontroller Analog to Digital Conversion (ADC) Module

## The aim
The Atmega328p microcontroller has an analog-to-digital conversion (ADC) module capable of converting an analog voltage into a 10-bit number from 0 to 1023 or an 8 bit number from 0 to 255. The input to the module can be selected to come from any one of six inputs on the chip. While this gives the microcontroller the ability to convert the signals from six different analog sources into 10-bit values. In the Atmega328p microcontroller ADC module, we need to understand four main register:
```
-> ADCH: Holds digital converted data higher byte
-> ADCL: Holds digital converted data lower byte
-> ADMUX: ADC Multiplexer selection register
-> ADCSRA: ADC Control and status register
```
The aim of this project is to show how to read an analog voltage value from a potentiometer and transfer the result through UART serial communication protocol. The Embedded C is applied to compile program using Makefile within Vim editor.
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
      6- 10 kΩ potentiometer
      7- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      8- 10 kΩ resistor
      9- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/a447ea74-49be-448d-ae5f-d73b1950fba6" width="800">
