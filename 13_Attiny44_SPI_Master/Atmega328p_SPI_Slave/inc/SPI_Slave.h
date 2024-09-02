/*
 * File_Name       :   SPI_Slave.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_


#include <avr/io.h>
#include <util/delay.h>

#define MOSI DDB3
#define MISO DDB4
#define SCK  DDB5
#define SS   DDB2
#define SS_Enable  PORTB  &= ~(1 << PORTB2)
#define SS_Disable PORTB  |=  (1 << PORTB2)



void SPI_Slave_Init(void);
void SPI_Slave_Transmit(char SPI_Data);
char SPI_Slave_Receive(void);




#endif 







