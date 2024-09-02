# Project: Handling the UART Serial Communication using Interrupt with Atmega328p Microcontroller

## The aim
The UART Serial communication using the polling method causes the wastage of time of the Atmega328p microcontroller. To enable interrupt-based transmission we have to set HIGH the USART Data Register Empty Interrupt Enable (UDRIE). On the other hand, to enable interrupt-based reception we need to set HIGH the Receive Complete Interrupt Enable(RXCIE) bit in UCSRB. The aim of this project is to show how to handle Atmega328p microcontroller UART Serial Communication using Interrupt. The Embedded C is applied to compile program using Makefile within Vim editor. 
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
      7- Traffic Light LED Display Module
      8- 10 kΩ resistors
      9- Two 22 pF ceramic capacitors
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/87ad5901-7fcf-402c-8b11-ca678d51c377" width="800">
