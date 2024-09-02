/*
 * Project_Name    :   PWM
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>

int main(void) {

	uint8_t i;

	DDRD = (1 << PD6);
	
	TCCR0A = (1 << COM0A1) | (1  << WGM00);
	TCCR0B = (1 << CS00)   | (1  << CS02);
 
	for (;;) {

		OCR0A = 0x00;
		_delay_ms(100);
		OCR0A = 0x40;
		_delay_ms(100);
		OCR0A = 0x80;
		_delay_ms(100);
		OCR0A = 0xC0;
		_delay_ms(100);
		OCR0A = 0xFF;
		_delay_ms(100);
	}

	return 0;
}
