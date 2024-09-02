# Project: SPI communication using AVR family-based ATiny44 microcontroller (Master) and ATmega328p microcontroller (Slave)

## The aim
Serial communication protocols provides the means to communicate for microcontrollers with external hardware, peripherals or other microcontrollers. USART, SPI, I2C are some of the popular serial communication protocols in embedded world. In order to facilitate serial communication in ATtiny44 microcontroller it is equipped with a Universal Serial Interface USI module. This USI module can operate in Two wire Synchronous data transfer (I2C protocol) and Three wire Synchronous data transfer (SPI protocol) modes.
The aim of this application is to build a project that uses SPI communication to exchange data between the ATiny44 microcontroller (Master) and the ATmega328p microcontroller (Slave). A push-button is connected to GPIO port PA2 of the master microcontroller. While the push-button is not pressed, the master microcontroller send hex values from 0 to F to slave device. The slave microcontroller receive data via SPI then sets the PORTD outputs to turn individual segments of the LED display on or off, thus displaying a digit from 0 to F. The digits 0 to F should show in ascending order on the seven-segment LED display, and then repeat. The Embedded C is applied to compile programs using Makefile within Vim editor.
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
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/0666f4db-127a-4626-ae70-574a6190711a" width="800">
