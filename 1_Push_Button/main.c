/*
 * Project_Name    :   Push_Button
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>

#define LED    PB0
#define BUTTON PD7

int main(void) {

	int state = 0;
	DDRB  =  (1 << PB0);
	DDRD &= ~(1 << PD7);


	for (;;) {

		if ((PIND & (1 << BUTTON)) > 0) {

			_delay_ms(50);

			if (state == 0) {

				PORTB ^= (1 << LED);
				state = 1;
			}
		}
		else {
			state = 0;
		}
	}

	return 0;
}
