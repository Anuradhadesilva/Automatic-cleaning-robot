#include <avr/io.h>

#define DDDR_ROTATE DDRC	// control rotate direction
#define DDDR_SPEED DDRD		// control motor speed
#define DPORT_ROTATE PORTC	// control rotate direction

unsigned char in1;
unsigned char in2;
unsigned char in3;
unsigned char in4;
unsigned char ena;
unsigned char enb;

// PWM initialization function
void PWM_init(){	// set fast PWM mode with non-inverted output	TCCR1B = ((1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00));	TCCR1A = ((1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00));}

void driver_init(
unsigned char _in1,
unsigned char _in2,
unsigned char _in3,
unsigned char _in4,
unsigned char _ena,
unsigned char _enb
)
{
	in1 = _in1;
	in2 = _in2;
	in3 = _in3;
	in4 = _in4;
	ena = _ena;
	enb = _enb;

	DDDR_ROTATE |= ((1 << in1) | (1 << in2) | (1 << in3) | (1 << in4));
	DDDR_SPEED |= ((1 << ena) | (1 << enb));
	PWM_init();
	
}



void driver_go(unsigned char direction, unsigned char speed)
{
	OCR1B = speed;
	
	if(direction == 'f')
	{
		DPORT_ROTATE &= (~(1 << in1) & ~(1 << in3));
		DPORT_ROTATE |= ((1 << in2) | (1 << in4));
	}
	else if(direction == 'b')
	{
		DPORT_ROTATE |= ((1 << in1) | (1 << in3));
		DPORT_ROTATE &= (~(1 << in2) & ~(1 << in4));
	}

}

void driver_rotate(unsigned char direction, unsigned char speed)
{
	OCR1B = speed;
	
	if(direction == 'r')
	{
		DPORT_ROTATE |= ((1 << in2) | (1 << in3));
		DPORT_ROTATE &= (~(1 << in1) & ~(1 << in4));
	}
	else if(direction == 'l')
	{
		DPORT_ROTATE |= ((1 << in1) | (1 << in4));
		DPORT_ROTATE &= (~(1 << in2) & ~(1 << in3));
	}
}

void driver_stop(unsigned char motor_l, unsigned char motor_r)
{
	OCR1B = 0;
	
	if(motor_l == 1) DPORT_ROTATE &= (~(1 << in1) & ~(1 << in2));
	if(motor_r == 1) DPORT_ROTATE &= (~(1 << in3) & ~(1 << in4));
}