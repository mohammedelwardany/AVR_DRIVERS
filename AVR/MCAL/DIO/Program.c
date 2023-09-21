/*
* Program.c
*
* Created: 9/9/2023 1:38:56 AM
*  Author: m2010
*/




#include "Dio_Int.h"

u8 Dio_PinInitArray[]={
	Dio_PinA0_init, Dio_PinA1_init, Dio_PinA2_init, Dio_PinA3_init,
	Dio_PinA4_init, Dio_PinA5_init, Dio_PinA6_init, Dio_PinA7_init,
	Dio_PinB0_init, Dio_PinB1_init, Dio_PinB2_init, Dio_PinB3_init,
	Dio_PinB4_init, Dio_PinB5_init, Dio_PinB6_init, Dio_PinB7_init,
	Dio_PinC0_init, Dio_PinC1_init, Dio_PinC2_init, Dio_PinC3_init,
	Dio_PinC4_init, Dio_PinC5_init, Dio_PinC6_init, Dio_PinC7_init,
	Dio_PinD0_init, Dio_PinD1_init, Dio_PinD2_init, Dio_PinD3_init,
	Dio_PinD4_init, Dio_PinD5_init, Dio_PinD6_init, Dio_PinD7_init
};


u8 * const DIO_RegPORT[4]={&PORTA,&PORTB,&PORTC,&PORTD};
u8 * const DIO_RegDDR[4]= {&DDRA,&DDRB,&DDRC,&DDRD};
u8 * const DIO_RegPIN[4]= {&PINA,&PINB,&PINC,&PIND};


void Dio_SetPinMode(Pin_Type Pin_ID , PinMode_type Mode){
	
	Pin_Type Port_Index = Pin_ID/8;
	Pin_Type Pin_Index  = Pin_ID%8;
	
	switch(Mode){
		
		case OutPut_High :
		SetBit(*DIO_RegDDR[Port_Index] ,Pin_Index);
		SetBit(*DIO_RegPORT[Port_Index],Pin_Index);
		
		break;
		
		case OutPut_Low  :
		SetBit(*DIO_RegDDR[Port_Index] ,Pin_Index);
		ClrBit(*DIO_RegPORT[Port_Index],Pin_Index);
		break;
		
		case InPut_Float :
		ClrBit(*DIO_RegDDR[Port_Index] ,Pin_Index);
		
		break;
		
		case InPut_PullUp :
		ClrBit(*DIO_RegDDR[Port_Index] ,Pin_Index);
		ClrBit(*DIO_RegPORT[Port_Index],Pin_Index);
		break;
	}
	
	
}

void DIO_Init(void)
{
	for(u8 PinCount=Pin_A0;PinCount<=Pin_D7;PinCount++){
		
		Dio_SetPinMode(PinCount,Dio_PinInitArray[PinCount]);
		
	}
	
	
	
	
}
/*****************************DIO_u8ReadPinVal***********************************/

void DIO_ReadPinVal(Pin_Type Pin_ID ,u8 * ReadBufferPTR )
{
	
	Pin_Type Port_Index = Pin_ID / 8;
	Pin_Type Pin_Index  = Pin_ID % 8;
	
	*ReadBufferPTR = GetBit(*DIO_RegPIN[Port_Index],Pin_Index);
	
	
}

void DIO_WritePinVal(Pin_Type Pin_ID ,u8 VALUE )
{
	
	Pin_Type Port_Index = Pin_ID / 8;
	Pin_Type Pin_Index  = Pin_ID % 8;
	if (VALUE==HIGH)
	{
		SetBit(*DIO_RegPORT[Port_Index],Pin_Index);
	}
	else if (VALUE==LOW)
	{
		ClrBit(*DIO_RegPORT[Port_Index],Pin_Index);
	}
	
}




/*




void DIO_SETPINDIR (u8 PinNumber,u8 PortNum,u8 Dirction){
	switch(PortNum){
		case Port_A:
		if(Dirction==IN){
			ClrBit(DDRA,PinNumber);
		}
		else if(Dirction==OUT){
			SetBit(DDRA,PinNumber);
		}
		else{
			//printf("err");
		}
		break;
		
		
		
		case Port_B:
		if(Dirction==IN){
			ClrBit(DDRB,PinNumber);
		}
		else if(Dirction==OUT){
			SetBit(DDRB,PinNumber);
		}
		else{
			//printf("err");
		}
		break;
		
		
		case Port_C:
		if(Dirction==IN){
			ClrBit(DDRC,PinNumber);
		}
		else if(Dirction==OUT){
			SetBit(DDRC,PinNumber);
		}
		else{
			//printf("err");
		}
		break;
		
		
		
		case Port_D:
		if(Dirction==IN){
			ClrBit(DDRD,PinNumber);
		}
		else if(Dirction==OUT){
			SetBit(DDRD,PinNumber);
		}
		else{
			//printf("err");
		}
		break;
		
		
	}
}

void DIO_Write (u8 PinNumber,u8 PortNum,u8 Value){
	
	switch( PortNum ){
		case Port_A:{
			if(Value==LOW){
				ClrBit(PORTA,PinNumber);
			}
			else if(Value==HIGH){
				SetBit(PORTA,PinNumber);
			}
			else{
				//printf("err");
			}
			break;
		}
		
		
		case Port_B:{
			if(Value==LOW){
				ClrBit(PORTB,PinNumber);
			}
			else if(Value==HIGH){
				SetBit(PORTB,PinNumber);
			}
			else{
				//printf("err");
			}
			break;
		}
		
		case Port_C:{
			if(Value==LOW){
				ClrBit(PORTC,PinNumber);
			}
			else if(Value==HIGH){
				SetBit(PORTC,PinNumber);
			}
			else{
				//printf("err");
			}
			break;
		}
		
		
		case Port_D:{
			if(Value==LOW){
				ClrBit(PORTD,PinNumber);
			}
			else if(Value==HIGH){
				SetBit(PORTD,PinNumber);
			}
			else{
				//printf("err");
			}
			break;
		}
		
	}
	
}



void DIO_Read (u8 PinNumber,u8 PortNum,u8 *Value){
	
	switch( PortNum ){
		case Port_A:{
			
			*Value=GetBit(PORTA,PinNumber);
			break;
		}
		
		
		case Port_B:{
			*Value=GetBit(PORTB,PinNumber);
			break;
		}
		
		case Port_C:{
			*Value=GetBit(PORTC,PinNumber);
			break;
		}
		
		
		case Port_D:{
			*Value=GetBit(PORTD,PinNumber);
			break;
		}
		
	}
}
*/