# Project: I2C communication using AVR family-based ATiny44 microcontroller (Master) and ATmega328p microcontroller (Slave)

## The aim
I2C or Inter Integrated circuit is a popular serial communication protocol built in almost every modern microcontrollers. This protocol uses full duplex communication and uses only two wires to exchange data. ATtiny44 microcontroller is equipped with Universal Serial interface aka USI which can be configured to operate in I2C mode. I2C mode using this USI interface is also referred as Two wire mode.
The aim of this application is to build a project that uses I2C communication to exchange data between the ATiny44 microcontroller (Master) and the ATmega328p microcontroller (Slave). A push-button is connected to GPIO port PA2 of the master microcontroller. While the push-button is not pressed, the master microcontroller send hex values from 0 to F to slave device. The slave microcontroller receive data via I2C then sets the PORTD outputs to turn individual segments of the LED display on or off, thus displaying a digit from 0 to F. The digits 0 to F should show in ascending order on the seven-segment LED display, and then repeat. The Embedded C is applied to compile programs using Makefile within Vim editor. 
To compile the embedded C code for the ATiny44 microcontroller, we need to open a terminal window, navigate to the project folder and enter the following command:
```
$ make
```
To upload the generated HEX file to ATiny44 microcontroller, enter the following command:
```
$ avrdude -c USBasp -p t44 -B 4 -U flash:w:main.hex:i
```

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
      2- ATiny44 microcontroller
      3- USBasp programmer
      4- 5V breadboard power supply 
      5- Two 8MHz Crystal Oscillators
      6- Solderless breadboard
      7- Jumper wires
      8- One common-cathode Seven-Segment LED display
      9- Push-button
      10- 0.1 μF ceramic capacitor
      11- Four 22 pF ceramic capacitors
      12- 1 kΩ resistor
      13- Three 10 kΩ resistors
      14- Two 4.7 kΩ  resistors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/8cd0b34b-cdce-41c1-80ab-1603e279a979" width="800">
