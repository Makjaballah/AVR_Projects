/*
 * Project_Name    :   SPI_Master_75HC595
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>



void SPI_Master_Init(void) {
	
	DDRB   =   (1 << PB5) | (1 << PB3) | (1 << PB2) | (1 << PB1);
	PORTB &= ~ (1 << PB1); 
	SPCR   =   (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);		
}


int main(void) {

	int cnt = 0;
	uint8_t Seg_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

	SPI_Master_Init ();
	
	for (;;) {
		
		SPDR = Seg_val[cnt & 0x0F];
		while (!(SPSR & (1 << SPIF)));
		
		PORTB |=   (1 << PB1);
		_delay_ms(5);
		PORTB &= ~ (1 << PB1);  
		
		cnt++;
		_delay_ms(1000);

	}
	
	return 0;
}
