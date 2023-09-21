/*
 * MusicPlayer_Program.c
 *
 * Created: 9/21/2023 12:33:00 AM
 *  Author: m2010
 */ 
#include "types.h"
#include <util/delay.h>
#include "Interface_LCD.h"

#include "MusicPlayer_Config.h"
#include "MusicPlayer_Interface.h"

// void BUZZER_voidInit(){
// 	
// }


void my_delay_ms(u16 ms)
{
	while (0 < ms)
	{
		_delay_ms(1);
		--ms;
	}
}


void BUZZER_PlayTrack(){
	LCD_WriteString("START");
	_delay_ms(100);
	u16 length = sizeof(melody) / sizeof(melody[0]);
	
	for(u16 i=0;i<length;i++){
		LCD_voidWriteNumber(melody[i]);
		TMR1_voidSetFrequencyA_FASTPWM(melody[i]);
		setHalfDutyCycle();
		TMR1_voidStart();
		my_delay_ms(1000/durations[i] );
		LCD_voidClear();
// 		TMR1_voidStop();
	}
	LCD_WriteString("ENDED");
	TMR1_voidStop();
		
}
//void BUZZER_voidStop();