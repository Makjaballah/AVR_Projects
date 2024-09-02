/*
 * Project_Name    :   UART_Interrupt
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>
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
	
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART_Transmit (uint8_t data) {
	
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


ISR(USART_RX_vect) {

	cli();
	UDR0 = UDR0 + 1;
	sei();
}

int main(void) {
	
	DDRD = (1 << PD1);
	DDRB = (1 << PB0);

	UART_Initialize();
	sei();

	for (;;) {

		PORTB ^= (1 << PB0);
		_delay_ms(250);
	}
	
	return 0;
}
