/*
 * TIMER1_Program.c
 *
 * Created: 9/18/2023 3:23:18 PM
 *  Author: m2010
 */ 
#define F_CPU 16000000
#include <util/delay.h>

#include "bitMath.h"

#include "Dio_Int.h"
#include "TIMER1_Private.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Config.h"



void TMR1_Init(void){
	
	
	//select mode >>
	ClrBit(TCCR1A,WGM10);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1B,WGM13);
	
	
	//SET WITH NON INVERTING
	
		ClrBit(TCCR1A,COM1A0);
		SetBit(TCCR1A,COM1A1);


}


// void timer1_init() {
// 	ICR1_u16 = F_CPU / (2 * NOTE_G4) - 1;  // Set the top value for the lowest note frequency
// 	
// 	TCCR1A |= (1 << COM1A1) | (1 << WGM11);   // Set non-inverted PWM mode on OC1A (BUZZER_PIN)
// 	TCCR1B |= (1 << WGM13) | (1 << WGM12);    // Configure Timer 1 for Mode 14 (Fast PWM)
// 	TCCR1B |= (1 << CS10);                    // Start Timer 1 with no prescaler
// }



void TMR1_voidStart(void){

		SetBit(TCCR1B,CS10);
		SetBit(TCCR1B,CS11);
		ClrBit(TCCR1B,CS12);
}

void TMR1_voidStop(void){
			ClrBit(TCCR1B,CS10);
			ClrBit(TCCR1B,CS11);
			ClrBit(TCCR1B,CS12);
}






void TMR1_voidSetOutputCompareMatchValueA_FASTPWM(u16 Copy_u16CompareMatchVale){

		OCR1A_u16 = Copy_u16CompareMatchVale;

}

void TMR1_voidSetFrequencyA_FASTPWM(u16 Copy_u16FrequencyVale){
	ICR1_u16=((1000000 / Copy_u16FrequencyVale)/4)-1;
	
}



void buzzer_init() {
	Dio_SetPinMode(Pin_C6,OutPut_High);
	
}

void buzzer_stop() {
	DIO_WritePinVal(Pin_C6,LOW);  // Set the buzzer pin as an output
}



void buzzer_start() {
	DIO_WritePinVal(Pin_C6,HIGH);  // Set the buzzer pin as an output
}

void setHalfDutyCycle() {
	OCR1A_u16 = ICR1_u16/2;
}


// void play_note(u16 frequency, u16 duration) {
 	//ICR1_u16 = 1 / (0.000004 * frequency) - 1;    // Set the top value for the note frequency
//	ICR1_u16 = (((u32)1000000 / (u32)frequency)/4)-1; //SET FREQUENCY

///	ICR1_u16 = F_CPU / (2 * frequency) - 1;    // Set the top value for the note frequency
	
//	OCR1A_u16 = ICR1_u16 / 2;                      // Set the compare value for 50% duty cycle
// TMR1_voidStart();
// 	buzzer_start();

// 	buzzer_stop();

//}