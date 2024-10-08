/*
 * Project_Name    :   I2C_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Attiny44
*/


#include <avr/io.h>							
#include <util/delay.h>						
#include <stdio.h>							
#include <string.h>
#include "USI_I2C_Master.h"							
				

#define Slave_Write_Address		0x20
#define Slave_Read_Address		0x21




int main(void) {
	
	unsigned char segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
	char counter = 0;
	
	DDRA  &= ~ (1 << DDA2);
	PORTA |=   (1 << PA2);
	
	USI_I2C_Master_Init();
	USI_I2C_Master_Start ();
	USI_I2C_Master_Write_Byte (Slave_Write_Address);
	USI_I2C_Master_Write_Byte (segment_val[counter]);
	USI_I2C_Master_Stop (); 
	
	for (;;) {
		
		if((PINA & (1 << PA2))) {
			counter += 1;
			if(counter > 15) counter = 0;
			
			USI_I2C_Master_Start ();
			USI_I2C_Master_Write_Byte (Slave_Write_Address);
			USI_I2C_Master_Write_Byte (segment_val[counter & 0xF]);
			USI_I2C_Master_Stop (); 
			_delay_ms (1000);
		}
	}
	
	return 0;
}









