/*
 * DCM_program.c
 *
 * Created: 9/20/2023 7:39:12 PM
 *  Author: m2010
 */ 
#include "TIMER0_Interface.h"
#include "Dio_Int.h"

#include "DCM_interface.h"

void DCM_voidOn(u8 Copy_u8Direction)
{
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/
	Dio_SetPinMode(Pin_B3,OutPut_High);
	Dio_SetPinMode(Pin_B5,OutPut_High);
	Dio_SetPinMode(Pin_B6,OutPut_High); // WILL TAKE OUTPUT FROM TIMER0 
	#if Copy_u8Direction == DCM_CLOCK_WISE
	DIO_WritePinVal(Pin_B5 , HIGH);
	
	#elif Copy_u8Direction == DCM_COUNTER_CLOCK_WISE
		DIO_WritePinVal(Pin_B5 , LOW);
#endif
}


void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
	/* Controlling DC motor speed using PWM
	mode from TMR0 by setting Duty Cycle*/
	if (Copy_u8Speed<=100){
		TMR0_voidSetDutyCycle_FastPwm(Copy_u8Speed);
	}
	
}


void DCM_voidOff(void)
{
	/* Turn DC motor off using H-Bridge
	   By Setting Enable pin with low */
	
	DIO_WritePinVal(Pin_B6 , LOW);
}