/*
* Ex_Interups_prgram.c
*
* Created: 9/11/2023 11:46:14 AM
*  Author: m2010
*/


#include "types.h"
#include "bitMath.h"

#include "Ex_Interups_Private.h"
#include "Ex_Interups_Interface.h"


void EXInterupts_voidEnable(EXTI_SRC_t copy_interuptSource, EXT_TRIGGER_t copy_Trigger){
	switch (copy_interuptSource)
	{
		case EX_INT0:
		{
			switch (copy_Trigger)
			{
				case EX_RISING_EDGE:
				{
					SetBit(MCUCR,ISC00);
					SetBit(MCUCR,ISC01);
					break;
				}
				case EX_FALLING_EDGE:
				{
					ClrBit(MCUCR,ISC00);
					SetBit(MCUCR,ISC01);
					break;
				}
				case EX_LOW_LEVEL:
				{
					ClrBit(MCUCR,ISC00);
					ClrBit(MCUCR,ISC01);
					break;
				}
				case EX_ANY_OGICAL_CHANGE:
				{
					SetBit(MCUCR,ISC00);
					ClrBit(MCUCR,ISC01);
					break;
				}
			}
			SetBit(GICR,INT0); //EN INT0
			break;
		}
		
		///////////////////////////////
		
		
		case EX_INT1:
		{
			switch (copy_Trigger)
			{
				case EX_RISING_EDGE:
				{
					SetBit(MCUCR,ISC10);
					SetBit(MCUCR,ISC11);
					break;
				}
				case EX_FALLING_EDGE:
				{
					ClrBit(MCUCR,ISC10);
					SetBit(MCUCR,ISC11);
					break;
				}
				case EX_LOW_LEVEL:
				{
					ClrBit(MCUCR,ISC10);
					ClrBit(MCUCR,ISC11);
					break;
				}
				case EX_ANY_OGICAL_CHANGE:
				{
					SetBit(MCUCR,ISC10);
					ClrBit(MCUCR,ISC11);
					break;
				}
			}
			SetBit(GICR,INT1); //EN INT1
			break;
		}
		
		
		
		
		case EX_INT2:
		{
			switch (copy_Trigger)
			{
				case EX_RISING_EDGE:
				{
					SetBit(MCUCR,ISC2);
					break;
				}
				case EX_FALLING_EDGE:
				{
					ClrBit(MCUCR,ISC2);
					break;
				}
			}
			SetBit(GICR,INT2); //EN INT1
			break;
		}
		
		
		
		
	}
}
void EXInterupts_voidDisable(EXTI_SRC_t copy_interuptSource){
	switch (copy_interuptSource)
	{
		case EX_INT0:{
			ClrBit(GICR,INT0);
			break;
		}
		case EX_INT1:{
			ClrBit(GICR,INT1);
			break;
		}
		case EX_INT2:{
			ClrBit(GICR,INT2);
			break;
		}
	}
}