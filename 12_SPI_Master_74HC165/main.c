/*
 * Project_Name    :   SPI_Master_74HC165
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>



#define BAUDRATE 4800
#define MYUBRR   ((F_CPU / 16 / BAUDRATE) - 1)



void UART_Initialize (void) {
	
	UCSR0B = (1 << TXEN0)  | (1 << RXEN0);
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

void UART_Transmit_string (char * str) {
	
	unsigned char i =0 ;
	while (str[i] != 0) {
		UART_Transmit(str[i]) ; 
		i++;
	}
}


void SPI_Master_Init(void) {
	 
	DDRB = (1 << PB5) | (1 << PB3) | (1 << PB2);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);		
}

void SPI_Master_Transmit(char spiData) {
	
	SPDR = spiData;
	while (!(SPSR & (1 << SPIF)));	
}

char SPI_Master_Receive(void) {

	while (!(SPSR & (1 << SPIF)));
	return SPDR;
}

int main(void) {
	
	uint8_t val;
	int i;
	char buffer[5] ;
	DDRD = (1 << PD1);
	UART_Initialize();
	SPI_Master_Init();

    for (;;) {
	    
	    PORTB = (1 << PB2);	
	    SPI_Master_Transmit(0xFF);
	    PORTB &= ~(1 << PB2);
	    val = SPI_Master_Receive();
	    _delay_ms(10);
	    UART_Transmit_string("\n\r");
	    
	    for (i = 0; i < 4; i ++) {
		    
		    UART_Transmit_string("\n\rDIP");
		    buffer[0] = i+'0';
		    buffer[1] = ' ';
		    buffer[2] = 0;
		    UART_Transmit_string(buffer);
		    
		    if ((val & (1 << i)) > 0)
			    UART_Transmit_string("1");
		    else
			    UART_Transmit_string("0");
	    }

	    _delay_ms(2000);	
    }
    
    return 0;
}

