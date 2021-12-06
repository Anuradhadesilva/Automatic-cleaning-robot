/*
 * dc motor new.c
 *
 * Created: 12/6/2021 10:24:45 AM
 * Author : Anuradha
 */ 
#define F_CPU 8000000UL
#include "avr/io.h"
#include <util/delay.h>

void PWM_init()
{
	
	/*set fast PWM mode with non-inverted output*/
	TCCR1B = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	TCCR1A = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRD|=(1<<PD4);  /*set OCR1B pin as output*/
}


int main ()
{
	unsigned char duty;
	
	PWM_init();
	DDRC=0xFF;
	PORTC|=(1<<PC3|1<<PC5);
	PORTC&=(~(1<<PC2|1<<PC4));
	
	
		for(duty=0; duty<255; duty++)
		{
			OCR1B=duty;  
			_delay_ms(3);
		}
		_delay_ms(2000);
		for(duty=255; duty>1; duty--)
		{
			OCR1B=duty;  
			_delay_ms(3);
		}
		_delay_ms(80);
		PORTC&=(~(1<<PC2|1<<PC5));
		PORTC|=(1<<PC3|1<<PC4);
		for(duty=0; duty<100; duty++)
		{
			OCR1B=duty;  
			_delay_ms(1);
		}
		_delay_ms(4000);
		
}
