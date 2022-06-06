/*
 * GccApplication9.c
 *
 * Created: 5/8/2022 9:59:57 AM
 * Author : Anuradha
 */ 

#define F_CPU 8000000L
#include "avr/io.h"
#include <util/delay.h>


void main(){
	
	DDRC=0xFF;
	
	motor_go('f');
	_delay_ms(3000);
	
	motor_rotate('r');
	_delay_ms(3000);
	
	motor_rotate('l');
	_delay_ms(3000);
	
	motor_stop(0);
	
	
}


void motor_go(unsigned char dir){
	
	
	if(dir=='f'){
		PORTC|=(1<<PC3|1<<PC5);
		PORTC&=(~(1<<PC2|1<<PC4));
	}
	
	
	
}
void motor_rotate(unsigned char dir){
	
	
	if (dir=='r'){
		PORTC|=(1<<PC3|1<<PC4);
		PORTC&=(~(1<<PC2|1<<PC5));
	}
	
	else if (dir== 'l'){
		PORTC|=(1<<PC2|1<<PC5);
		PORTC&=(~(1<<PC3|1<<PC4));
	}
}
void motor_stop(unsigned char dir){
	
	if(dir==0){
	PORTC&=(~(1<<PC2)&~(1<<PC3));
	PORTC&=(~(1<<PC4)&~(1<<PC5));
	}
}
