/*
 * Project_Name    :   SPI_Slave
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/




#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Slave.h"



int main(void) {   
	
	DDRD = 0xFF;
	SPI_Slave_Init(); 
	
	for (;;) { 
		
		PORTD = SPI_Slave_Receive () ;
	}
	
	return 0;
}












