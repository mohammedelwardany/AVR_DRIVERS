/*
 * TIMER1_Interface.h
 *
 * Created: 9/18/2023 3:22:34 PM
 *  Author: m2010
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


////////////////////////////////////////music rules//////////////////////////////////

// Define note frequencies
#define NOTE_G3  196
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Define note durations (in milliseconds)
#define DURATION_HALF    500
#define DURATION_QUARTER    250
#define DURATION_EIGHTH     125
#define DURATION_SIXTEENTH  63

#define BUZZER_PIN 6

#include "types.h"




void TMR1_Init(void);
void TMR1_voidStart(void);
void TMR1_voidStop(void);
void TMR1_voidSetOutputCompareMatchValueA_FASTPWM(u16 Copy_u16CompareMatchVale);
void TMR1_voidSetFrequencyA_FASTPWM(u16 Copy_u16FrequencyVale);
void setHalfDutyCycle();


void timer1_init();

void buzzer_init();
void buzzer_start();
void buzzer_stop();

void play_note(u16 frequency, u16 duration);





#endif /* TIMER1_INTERFACE_H_ */