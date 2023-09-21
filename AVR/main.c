/*
 * AVR.c
 *
 * Created: 9/16/2023 1:47:36 PM
 * Author : m2010
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL

#include <util/delay.h>


#include "Dio_Int.h"
#include "Interface_LCD.h"
#include "Interface_KeyBad.h"
#include "ADC_Interface.h"
#include "Calculator_LCD_KEYS_interface.h"
#include "Ex_Interups_Interface.h"
#include "G_Interups_Interface.h"
#include "TIMER0_Interface.h"
#include "TIMER1_Interface.h"
#include "DCM_interface.h"
#include "MusicPlayer_Interface.h"

// 
// void action(void);
u8 KeyBad_Retrive;


// 
// 
// 	void action(){
// 		static u8 flag=0;
// 		if (flag==1)
// 		{
// 			DIO_WritePinVal(Pin_A4,HIGH);
// 			flag =0 ;
// 		}
// 		else{
// 			DIO_WritePinVal(Pin_A4,LOW);
// 			flag =1 ;
// 		}
// 	}
// 	
int main(void)
{
	DIO_Init();
	//SRVM_voidOn (90);
	//SRVM_voidOff();
	TMR1_Init();
	LCD_init();
	 	//TMR1_voidStart();
	BUZZER_PlayTrack();

// 	TMR0_voidInit();
// 	TMR0_voidStart();
// 	DCM_voidOn(DCM_CLOCK_WISE);
// 	DCM_voidControlSpeed(80);
	
    //timer1_init();
 //Keypad_VidInit();

// 
  
// 	 
   //	ADC_init();


// TMR0_voidSetDutyCycle_FastPwm(40);
// TMR0_voidStart();
// u8 x = 0;
/*TMR0_voidStart();*/
// 	Dio_SetPinMode(Pin_A4,OutPut_Low);
// 
 // 	GINTERUPTS_voidEnable();
//  	TMR0_voidInit();
// 	TMR0_voidSetCompareMatchValue(249);
// 	TMR0_voidCTC_SetDelay_ms(1000);
//  	TMR0_voidSetCallBackCTC(action);
// // 
// 	TMR0_voidStart();
// 	
	

	
// 	KEYPAD_uint8Init();
// 	
//u16 BUFFF [4];
//Ssegmintinit();
//ADC_Scan_Sync_Group(ScanGroup1 , &BUFFF );

// 	EXInterupts_voidEnable(EX_INT1,EX_LOW_LEVEL);
// 	CharToNumber('2');
// CharToNumber('3');
// CharToNumber('6');



	/*DIO_WritePinVal(Pin_A1,LOW);
	_delay_ms(500);*/
	int x = 0;
 	//LCD_voidWriteString("hello world");
	


    while(1)
	{


        // "Super Mario Bros." theme melody
	
         
// 
//         play_note(6272, DURATION_QUARTER);
// // 		 TMR0_voidStop();_delay_ms(5000);
// TMR1_voidStop();
// _delay_ms(2);  // Pause between notes
//           play_note(7040, DURATION_QUARTER);
// 		   	_delay_ms(10);
// 		  TMR1_voidStop();
// 		  _delay_ms(2);  // Pause between notes
// 		    play_note(6272, DURATION_QUARTER);
// 		    _delay_ms(10);
// 		    TMR1_voidStop();
// 		    _delay_ms(2);  // Pause between notes
// 		  play_note(7459, DURATION_QUARTER);
// 		   	_delay_ms(10);
// 		  TMR1_voidStop();
// 		  _delay_ms(2);  // Pause between notes
// 		  play_note(6272, DURATION_QUARTER);
// 		   	_delay_ms(10);
// 		  TMR1_voidStop();
// 		  _delay_ms(2);  // Pause between notes
// 		  play_note(6272, DURATION_QUARTER);
// 		   	_delay_ms(20);
// 		  TMR1_voidStop();
// 		  _delay_ms(2);  // Pause between notes
// 		  play_note(5500, DURATION_QUARTER);
// 		  play_note(4500, DURATION_QUARTER);
// 		  play_note(4500, DURATION_QUARTER);
 		//x++;
// 
// 		if (x==3000)
// 		{
// 			x=0;
// 		}





// 		LCD_voidGoToSpecificPosition(0,0);
		//LCD_voidWriteNumber();
		
// TMR0_voidSetDutyCycle_FastPwm(x);
// _delay_ms(5);
/*x++;*/
// 	LCD_SendData(Keypad_U8GetKeyPressed());
		
		
		
		
		////////////////////task2///////////////////////////
//    u32 X = ADC_Scan_Single(0);
//     LCD_voidWriteNumber(X);
// 	TMR1_voidSetOutputCompareMatchValueA_FASTPWM(X) ;
//     _delay_ms(50);
//     LCD_voidClear();
//     _delay_ms(5);
// 	
	
	
	
	
	
	
	
	
	
	
	
	
// 
// _delay_ms(500);
	//SevenSegment_Value(5480);
	
// 		u8 KYP_Data = Keypad_U8GetKeyPressed();
// 					
// 		if (KYP_Data!=255)
// 		{
// 			if(KYP_Data == 'C'){
// 				LCD_voidClear();
// 				continue;
// 			}
// 			ScanChar(KYP_Data);
// 			LCD_SendData(KYP_Data);
// 
// 		}
// 		
// 		
		
		
		
		

		
	/*	_delay_ms(50);*/
		//_delay_ms(5000);
	}
	return 0;
}











// 
// 
// void __vector_16(void) __attribute__((signal));
// void __vector_16(void){
// 	  static u8 flag=0;
// 	  if (flag==1)
// 	  {
// 		  DIO_WritePinVal(Pin_A4,HIGH); 
// 		  flag =0 ;
// 	  }
// 	  else{
// 		  DIO_WritePinVal(Pin_A4,LOW);
// 		  flag =1 ;
// 	  }
// }


#endif

