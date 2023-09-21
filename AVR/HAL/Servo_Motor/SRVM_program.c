/*
 * SRVM_program.c
 *
 * Created: 9/20/2023 11:07:53 PM
 *  Author: m2010
 */ 


/* UTILES_LIB */

#include "bitMath.h"

/* MCAL */
#include "TIMER1_Interface.h"


void SRVM_voidOn(u8 Copy_u8Angle)
{
	/* TMR1 init at pwm mode 14 */
	TMR1_Init();
	/* Set pwm fre. = 50 */
	TMR1_voidSetFrequencyA_FASTPWM(50);
	/* Set pwm duty cycle between 5 : 10
	 depend on desired angle[0 : 180] */
	if (Copy_u8Angle>=0 && Copy_u8Angle<=180)
	{
		//TMR1_voidSetOutputCompareMatchValueA_FASTPWM(50+((Copy_u8Angle/180)*50));
		TMR1_voidSetOutputCompareMatchValueA_FASTPWM(250);
	}
	else{
		//error handle
	}

	/* TMR1 start */
	TMR1_voidStart();
}


void SRVM_voidOff(void)
{
	TMR1_voidStop();
	/* TMR1 stop */
}