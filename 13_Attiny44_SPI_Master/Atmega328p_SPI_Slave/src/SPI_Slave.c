/*
 * File_Name       :   SPI_Slave.c
 * Author          :   Mohamed Akram JABALLAH
*/

 


#include <avr/io.h>	
#include <util/delay.h>	
#include "SPI_Slave.h"	




void SPI_Slave_Init(void) {

	DDRB &= ~ ((1 << MOSI) | (1 << SCK) | (1 << SS));   
	DDRB |=   (1  << MISO);			 
	SPCR  =   (1  << SPE);			 
}


void SPI_Slave_Transmit(char SPI_Data) {
	
	SPDR = SPI_Data;			
	while (!(SPSR & (1 << SPIF)));				
	
}


char SPI_Slave_Receive(void) {

	while (!(SPSR & (1 << SPIF)));	 
	return(SPDR);			 
}













 

 


