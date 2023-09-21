/*
 * SSegment_Config.h
 *
 * Created: 9/15/2023 9:23:07 AM
 *  Author: m2010
 */ 


#ifndef SSEGMENT_CONFIG_H_
#define SSEGMENT_CONFIG_H_


#define A Pin_B0
#define B Pin_B1
#define C Pin_B2
#define D Pin_B4

//////////////////////////////////////

#define COM1 Pin_A3
#define COM2 Pin_A2
#define COM3 Pin_B5
#define COM4 Pin_B6

#define COM_Numbers 4


const u8 numbersArr[10] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001};
u8 arrayLocation[COM_Numbers] =  {COM1,COM2,COM3,COM4};

#endif /* SSEGMENT_CONFIG_H_ */