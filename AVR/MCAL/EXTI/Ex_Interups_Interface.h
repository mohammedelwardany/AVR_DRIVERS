/*
 * Ex_Interups_Interface.h
 *
 * Created: 9/11/2023 11:46:54 AM
 *  Author: m2010
 */ 


#ifndef EX_INTERUPS_INTERFACE_H_
#define EX_INTERUPS_INTERFACE_H_

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define ISC2 6


#define INT0 6
#define INT1 7
#define INT2 5

typedef enum{
	EX_INT0, //D2
	EX_INT1,  //D3
	EX_INT2,	//B2
	}EXTI_SRC_t;
	

typedef enum{
	EX_RISING_EDGE,
	EX_FALLING_EDGE,
	EX_LOW_LEVEL,
	EX_ANY_OGICAL_CHANGE,
}EXT_TRIGGER_t;




void EXInterupts_voidEnable(EXTI_SRC_t copy_interuptSource, EXT_TRIGGER_t copy_Trigger);
void EXInterupts_voidDisable(EXTI_SRC_t copy_interuptSource);


#endif /* EX_INTERUPS_INTERFACE_H_ */