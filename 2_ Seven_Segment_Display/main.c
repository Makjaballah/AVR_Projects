/*
 * Project_Name    :   Seven_Segment_Display
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/



#include <avr/io.h>
#include <util/delay.h>

#define BUTTON PB0

int main(void) {

	int state = 0, cnt = 0;
	uint8_t segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };

	
	DDRD   = 0xFF;
	DDRB  &= ~(1 << PB0);
	PORTB |=  (1 << BUTTON);

	for (;;) {

		if((PINB & (1 << BUTTON)) == 0) {
			_delay_ms(50); 

			if(state == 0) {
				cnt++;
				state = 1;
			}
		}
		else {
			state = 0;
		}

		PORTD = segment_val[cnt & 0xF];
	}

	return 0;
}
