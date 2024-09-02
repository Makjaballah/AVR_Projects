/*
 * Project_Name    :   Watchdog
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

#define BAUDRATE 4800
#define MYUBRR   ((F_CPU / 16 / BAUDRATE) - 1)



void UART_Initialize (void) {
	
	UCSR0B = (1 << TXEN0)  | (1 << RXEN0) | (1 << RXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char) MYUBRR;
}


uint8_t UART_Read (void) {
	
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART_Transmit (uint8_t data) {
	
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_Transmit_string (char *str) {
	
	unsigned char i =0 ;
       	while(str[i] != 0) {
		UART_Transmit(str[i]) ; 
		i++;
	}
}

ISR(USART_RX_vect) {
	
	uint8_t cmd;
	cli();
	cmd = UDR0;
	UART_Transmit(cmd);
	UART_Transmit_string(" pressed\n\r");
	switch(cmd) {
		case 's':
		case 'S':
			PORTB |= 0x01;
			UART_Transmit_string("LED on\n\r");
			break;
		case 'r':
		case 'R':
			PORTB &= 0xFE;
			UART_Transmit_string("LED off\n\r");
			break;
		case 'A':
			while(1);
			break;
		default:
			break;
	}
	sei();
}

int main(void) {
	
	DDRD = (1 << PD1);
	DDRB = (1 << PB0);
	
	UART_Initialize ();
	sei();
	wdt_enable(WDTO_2S); 

	UART_Transmit_string("Start program\n\r");

	for (;;) {

		wdt_reset();
		_delay_ms(250);
	}
	
	return 0;
}
