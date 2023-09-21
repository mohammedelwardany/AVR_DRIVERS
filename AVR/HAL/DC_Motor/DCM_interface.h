/*
 * DCM_interface.h
 *
 * Created: 9/20/2023 7:40:14 PM
 *  Author: m2010
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#include "types.h"

#define DCM_CLOCK_WISE                   1
#define DCM_COUNTER_CLOCK_WISE           2


void DCM_voidOn          (u8 Copy_u8Direction);
void DCM_voidControlSpeed(u8 Copy_u8Speed);
void DCM_voidOff         (void);


#endif /* DCM_INTERFACE_H_ */