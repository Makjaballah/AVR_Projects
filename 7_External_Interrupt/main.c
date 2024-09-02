/*
 * Project_Name    :   External_Interrupt
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BUTTON PD2

int cnt = 0;

ISR(INT0_vect) {

	cli(); 
	_delay_ms(50); 
	cnt ++;
	sei(); 
}

int main(void) {

	uint8_t segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

	
	DDRB   = 0x3F;
	DDRD   =  (1 << PD7);
	DDRD  &= ~(1 << PD2);
	PORTD |=  (1 << BUTTON);

	EICRA = 0x02; 
	EIMSK = 0x01; 
	sei(); 

	for (;;) {
		
		PORTB = segment_val[cnt & 0xF] & 0x3F;
		PORTD &= ~(1 << PD7);
		if((segment_val[cnt & 0xF] & (1 << 6)) > 0)
			PORTD |= (1 << PD7);
	}

	return 0;
}
