/*
 * TIMER0_Program.c
 *
 * Created: 9/17/2023 11:38:18 AM
 *  Author: m2010
 */ 



#include "bitMath.h"

#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"

static u16 prv_TMR0_CTCCounter ;
static void(*prv_callbackovf)(void) = NUL;
static void(*prv_callbackCTC)(void) = NUL;

void TMR0_voidInit(void){
	//set mode
	#if Timer0_Mode == Normal
	ClrBit(TCCR0,WGM00);
	ClrBit(TCCR0,WGM01);
	
	TCNT0 =  Timer0_Preload;
	
	//enable overflow intererupt
	
	SetBit(TIMSK,TOIE0);
	
	
	#elif Timer0_Mode == CTC
	ClrBit(TCCR0,WGM00);
	SetBit(TCCR0,WGM01);
		
		
		//enable output - compare intererupt
		
	SetBit(TIMSK,OCIE0);

	#elif Timer0_Mode == FastPwm
	SetBit(TCCR0,WGM00);
	SetBit(TCCR0,WGM01);
	
	
	//no interupt
	
	//inverting - MODE
	#if Timer0_PWM_Action == NON_INVERTING
	ClrBit(TCCR0,COM00);	
	SetBit(TCCR0,COM01);	
	#elif Timer0_PWM_Action == INVERTING
	SetBit(TCCR0,COM00);
	SetBit(TCCR0,COM01);
	#endif
	//////////////////////////////////////////
	#elif Timer0_Mode == PhaseCorrect
	SetBit(TCCR0,WGM00);
	ClrBit(TCCR0,WGM01);
	
	
	//no interupt
	
	//inverting - MODE
	#if Timer0_PWM_Action == NON_INVERTING
	ClrBit(TCCR0,COM00);
	SetBit(TCCR0,COM01);
	#elif Timer0_PWM_Action == INVERTING
	SetBit(TCCR0,COM00);
	SetBit(TCCR0,COM01);
	#endif
	
	
	
	
	#endif
	
	
}




void TMR0_voidStart(void){
	//prescaler set
	SetBit(TCCR0,CS00);
	SetBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);
}
void TMR0_voidStop(void){
		ClrBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
}

TMR0_voidSetCompareMatchValue(u8 Copy_u8CompareValue){
	OCR0 = Copy_u8CompareValue;
}

void TMR0_voidSetDutyCycle_FastPwm(u8 Copy_u8DutyCycleValue){
		
	if (Copy_u8DutyCycleValue<=100)
	{
		#if Timer0_PWM_Action == NON_INVERTING
		OCR0 = (((u16)Copy_u8DutyCycleValue*256)/100)-1;
	
		#elif Timer0_PWM_Action == INVERTING
	
		Copy_u8DutyCycleValue = 100 - Copy_u8DutyCycleValue;
		OCR0 = (((u16)Copy_u8DutyCycleValue*256)/100)-1;
		
		#endif
	
	}
		

}



void TMR0_voidSetDutyCycle_PhaseCorrect(u8 Copy_u8DutyCycleValue){
	
	if (Copy_u8DutyCycleValue<=100)
	{
		#if Timer0_PWM_Action == NON_INVERTING
		OCR0 = (((u16)Copy_u8DutyCycleValue*255)/100);
		
		#elif Timer0_PWM_Action == INVERTING
		
		Copy_u8DutyCycleValue = 100 - Copy_u8DutyCycleValue;
		OCR0 = (((u16)Copy_u8DutyCycleValue*255)/100);
		
		#endif
		
	}
	

}






void TMR0_voidCTC_SetDelay_ms(u16 Delay_Time){
	//under condition tick time 4 ms
	OCR0 = 249;
	prv_TMR0_CTCCounter = Delay_Time;
}




void TMR0_voidSetCallBackOVF(void (*ptr) (void)){
	if (ptr != NUL)
	{
		prv_callbackovf = ptr;
	}
}


void TMR0_voidSetCallBackCTC(void (*ptr) (void)){
	if (ptr != NUL)
	{
		prv_callbackCTC = ptr;
	}
}


 void __vector_11(void) __attribute__((signal));
 void __vector_11(void){
	 static u16 OvfCounter = 0 ;
	 OvfCounter++;

	 if (TMR0_OVFCounter == OvfCounter)
	 {
		 TCNT0 =  Timer0_Preload;
		 
		 //clear counter
		 OvfCounter = 0;
		 if (prv_callbackovf != NUL)
		 {
			 prv_callbackovf();
		 }
		 
		 // call action
	 }
	 
	 
 }
 
 
 
 
 
 
  void __vector_10(void) __attribute__((signal));
  void __vector_10(void){
	  static u16 CTCCounter = 0 ;
	  CTCCounter++;

	  if (prv_TMR0_CTCCounter == CTCCounter)
	  {
		  
		  //clear counter
		  CTCCounter = 0;
		  if (prv_callbackCTC != NUL)
		  {
			  prv_callbackCTC();
		  }
		  
		  // call action
	  }
	  
	  
  }
  