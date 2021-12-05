/*
 * GccApplication4.c
 *
 * Created: 11/29/2021 1:00:38 PM
 * Author : Anuradha
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA=0x80;
	
	PORTA=(1<<7);
	_delay_ms(10000);
	PORTA=PORTA&(~(1<<7));
   
    
}
