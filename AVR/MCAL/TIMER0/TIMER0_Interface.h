/*
 * TIMER0_Interface.h
 *
 * Created: 9/17/2023 11:37:51 AM
 *  Author: m2010
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "types.h"



void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
void TMR0_voidSetCompareMatchValue(u8 Copy_u8CompareValue);
void TMR0_voidSetDutyCycle_FastPwm(u8 Copy_u8CompareValue);
void TMR0_voidCTC_SetDelay_ms(u16 Delay_Time);
void TMR0_voidSetCallBackOVF(void (*ptr) (void));
void TMR0_voidSetCallBackCTC(void (*ptr) (void));

#endif /* TIMER0_INTERFACE_H_ */