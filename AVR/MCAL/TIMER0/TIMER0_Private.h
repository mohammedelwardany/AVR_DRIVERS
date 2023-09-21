/*
 * TIMER0_Private.h
 *
 * Created: 9/16/2023 2:56:18 PM
 *  Author: m2010
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

//Timer/Counter Control Register – TCCR0
#define TCCR0  *((volatile u8*)0x53) 

#define	FOC0 	7
#define	WGM00 	6
#define	COM01 	5
#define	COM00 	4
#define	WGM01 	3
#define	CS02 	2
#define	CS01 	1
#define	CS00	0


#define TCNT0  *((volatile u8*)0x52) 

#define OCR0  *((volatile u8*)0x5C) 

#define TIMSK  *((volatile u8*)0x59) 

#define TOIE0 0
#define OCIE0 1




#define TIFR  *((volatile u8*)0x58) 

#define TOV0 0
#define OCF0 1


#define Normal		1
#define CTC			2
#define FastPwm		3
#define PhaseCorrect		4

#define NON_INVERTING		1
#define INVERTING			2


#endif /* TIMER0_PRIVATE_H_ */