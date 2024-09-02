# Project: Handling the Analog Comparator module with Atmega328p Microcontroller

## The aim
Atmega328p Microcontroller has two pins for analog voltage compare i.e. AIN0 and AIN1. AIN0 is the positive terminal whereas AIN1 is the negative terminal. When the voltage on positive pin AIN0 is higher than negative pin AIN1, the ACO bit of ACSR register is set. The aim of this project is to show how to handle analog input from a potentiometer with the analog Comparator module. The output of the comparator is shown by the LED which is connected to the PB0 pin. When the AIN0 pin voltage is greater than the AIN1 pin voltage then the output LED will glow, otherwise LED will off. The Embedded C is applied to compile program using Makefile within Vim editor.
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
      7- 10 kΩ potentiometer
      8- 330 Ω resistor
      9- Three 10 kΩ resistors
      10- Two 22 pF ceramic capacitor
```
## The main circuit diagram
<img src="https://github.com/user-attachments/assets/647dc0a6-d3b1-4623-af7b-014b7ff83d8b" width="800">
