/*
 * TIMER0_Config.h
 *
 * Created: 9/17/2023 11:41:51 AM
 *  Author: m2010
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define Timer0_Preload			49

#define  TMR0_OVFCounter		4883



#define  TMR0_CTCCounter		4500

#define Timer0_Mode   PhaseCorrect

// Normal	-	CTC	  - FastPwm

#define Timer0_PWM_Action   NON_INVERTING


#define NUL    'NULL'

#endif /* TIMER0_CONFIG_H_ */