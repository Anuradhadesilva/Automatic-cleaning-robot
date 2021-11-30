#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000L
#endif

#include <util/delay.h>
#include "driver.h"

int main(void)
{
	driver_init(2, 3, 4, 5, 4, 4);
	
	driver_go('f', 255);
	_delay_ms(1000);
	driver_go('b', 255);
	_delay_ms(1000);
	driver_rotate('l', 255);
	_delay_ms(1000);
	driver_rotate('r', 255);
	_delay_ms(1000);
	driver_stop(1, 1);
	
	return 0;
}