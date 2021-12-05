/***********************************************************************
  
           
  -------------------------------- (C) ---------------------------------
  
  @name driver.h
  @description Control Motor Functionalities

************************************************************************/


#ifndef DRIVER_H_
#define DRIVER_H_

void driver_init(
unsigned char _in1,
unsigned char _in2,
unsigned char _in3,
unsigned char _in4,
unsigned char _ena,
unsigned char _enb
);

void driver_go(unsigned char direction, unsigned char speed);
void driver_rotate(unsigned char direction, unsigned char speed);
void driver_stop(unsigned char motor_l, unsigned char motor_r);

#endif /* DRIVER_H_ */
