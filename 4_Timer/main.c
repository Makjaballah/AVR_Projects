/*
 * Project_Name    :   Timer
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


volatile uint8_t  cnt = 0;

ISR (TIMER1_COMPA_vect) {

	cnt ++;
	TCNT1 = 0x00;
}

int main(void) {

	int state = 0;
	uint8_t segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

	DDRC = 0x3F;
	DDRD = 0x01;

	TCCR1B = (1 << CS12) | (1 << CS10) | (1 << WGM12);
	OCR1A  = 9766; 
	TIMSK1 = (1 << OCIE1A);
	sei();

	for (;;) {

		PORTC  = segment_val[cnt & 0xF] & 0x3F;
		PORTD &= ~(1 << PD0);

		if ((segment_val[cnt & 0xF] & 0x40) > 0) 
			PORTD |= (1 << PD0);
	}

	return 0;
}
