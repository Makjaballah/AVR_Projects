/*
 * Project_Name    :   Analog_Digital_Converter
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>
#include <util/delay.h>

#define BAUDRATE 4800
#define MYUBRR   ((F_CPU / 16 / BAUDRATE) - 1)



void UART_Initialize (void) {
	
	UCSR0B = (1 << TXEN0)  | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char) MYUBRR;
}


uint8_t UART_Read (void) {
	
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART_Transmit (uint8_t data) {
	
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_Transmit_string (char * str) {
	
	unsigned char i =0 ;
	while(str[i] != 0) {
		
		UART_Transmit(str[i]) ; 
		i++;
	}
}

void Initialize_ADC (void) {

	ADMUX  |= (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}


unsigned int Read_ADC (unsigned char ADC_pin) {

	ADC_pin &= 0x07;
	ADMUX    = (ADMUX & 0xF8) | ADC_pin ;
	ADCSRA  |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));

	return ADC;
}



void float2str(float in, char *out) {

	int post = (int) in;
	int pre = (int) ((in - post) * 100);
	char buf[25];
	int len = 0, i;

	while(post) {
	
		buf[len++] = post % 10 + '0';
		post = post / 10;
	}

	for(i = 0; i < len; i++)
	
		out[i] = buf[len - i - 1];
		
	if(len == 0)
	
		out[i++] = '0';
	
	out[i++] = '.';
	out[i++] = pre / 10 + '0';
	out[i++] = pre % 10 + '0';
	out[i] = 0;
}


int main(void) {
	
	char buffer[32];
	uint16_t Raw_Adc;
	float Voltage_ADC;
	
	DDRD = (1 << PD1);
	
	UART_Initialize();
	Initialize_ADC();
	
	for (;;) {
		
		Raw_Adc = Read_ADC(5);
		Voltage_ADC = 5.0 * Raw_Adc / (1 << 10);
		float2str(Voltage_ADC, buffer);
		UART_Transmit_string("Analog Input = ");
		UART_Transmit_string(buffer);
		UART_Transmit_string(" V\n\r ");
		_delay_ms(2000);
	}
	
	return 0;
}
