/*
 * Project_Name    :   Analog _Comparator
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define GREEN PB0

ISR(ANALOG_COMP_vect) {

	if (ACSR & (1 << ACO))

			PORTB |= 1;
	else
			PORTB &= ~(1);
}

int main(void) {

	volatile long int i;
	DDRB   = (1 << PB0);
	PORTB  = 1;
	
	ACSR   = (1 << ACIE);
	ADCSRB = 0;
	sei();

	for (;;) {
		
	}

	return 0;
}
