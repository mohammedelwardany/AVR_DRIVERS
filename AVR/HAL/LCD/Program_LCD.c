/*
* Program_LCD.c
*
* Created: 9/10/2023 1:48:37 PM
*  Author: m2010
*/
#include <util/delay.h>
#include <math.h>
#include "types.h"

#include "SPI_Interface.h"
#include "Interface_LCD.h"

#include "Configure_LCD.h"
#include "Private_LCD.h"



void LCD_init(void){
	_delay_ms(30);
	Private_LCDHalfPort(0b0010);
	DIO_WritePinVal(EN,HIGH);
	_delay_ms(30);
	DIO_WritePinVal(EN,LOW);
	LCD_SendCommend(0b00101000);//last2
	_delay_us(30);
	LCD_SendCommend(0b00001111);  // last3
	_delay_us(30);
	LCD_SendCommend(0b00000001);  //
	_delay_ms(30);
	LCD_SendCommend(0b00000110);  //last2

	_delay_ms(30);

}





u8 Garbage;
///////////////////////////////////prepare///////////////////////////////////////
static void Private_LCDHalfPort(u8 copy_u8value){
// 	DIO_WritePinVal(LCD_D4,GetBit(copy_u8value,0));
// 	DIO_WritePinVal(LCD_D5,GetBit(copy_u8value,1));
// 	DIO_WritePinVal(LCD_D6,GetBit(copy_u8value,2));
// 	DIO_WritePinVal(LCD_D7,GetBit(copy_u8value,3));
SPI_u8SendRecieveByte(copy_u8value,&Garbage);
}





///////////////////////////////////SENDING///////////////////////////////////////

void LCD_SendData(u8 Val_u8){
	DIO_WritePinVal(RS,HIGH);
	Private_LCDHalfPort(Val_u8>>4);
	DIO_WritePinVal(EN,HIGH);
	_delay_ms(5);
 	DIO_WritePinVal(EN,LOW);
	_delay_ms(5);
	Private_LCDHalfPort(Val_u8);
	DIO_WritePinVal(EN,HIGH);
	_delay_ms(5);
	DIO_WritePinVal(EN,LOW);
	_delay_ms(5);
}

void LCD_SendCommend(u8 Val_u8){
	DIO_WritePinVal(RS,LOW);
	Private_LCDHalfPort(Val_u8>>4);
	DIO_WritePinVal(EN,HIGH);
	_delay_us(1);
	DIO_WritePinVal(EN,LOW);
	
	//_delay_ms(1);
	Private_LCDHalfPort(Val_u8);
	DIO_WritePinVal(EN,HIGH);
	_delay_us(1);

	DIO_WritePinVal(EN,LOW);
	
	//_delay_ms(1);
}







void LCD_voidWriteString(u8* copy_pu8String){
	while(*copy_pu8String!='\0'){
		LCD_SendData(*copy_pu8String);  //last2
		(copy_pu8String++);
	}
}	




void LCD_voidWriteNumber(u32 copy_u32Number){
	u8 arr[10];
	u8 i = 0;
	for(i=0;copy_u32Number!=0;i++){
		arr[i] = (copy_u32Number%10)+48;
		//LCD_SendData(arr[i]);
		copy_u32Number/=10;
	}
	for(u8 j=0;j<i;j++){
		LCD_SendData(arr[i-j-1]);
	}
}


void LCD_voidClear(void){
	LCD_SendCommend(0b00000001);  //
	_delay_ms(2);
}


void LCD_voidShift(DIRICTIONS copy_ShifttingDirection,ShiftingPlatform copy_ShifttingPlatform){
	switch (copy_ShifttingPlatform)
	{
		case Cursor:{
			switch (copy_ShifttingDirection)
			{
				case LEFT:{
					LCD_SendCommend(0b00010000);  //
					break;
				}
				case RIGHT:{
					LCD_SendCommend(0b00010100);  //
					break;
				}
			}
			break;
		}
		case Screen:{
			
			switch (copy_ShifttingDirection)
			{
				case LEFT:{
					LCD_SendCommend(0b00011000);  //
					break;
				}
				case RIGHT:{
					LCD_SendCommend(0b00011100);  //
					break;
				}
			}
			
			break;
		}
	}
	_delay_us(45);

}
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position){
	switch (copy_u8LineNumber)
	{
		case 1:{
			LCD_SendCommend(0b10000000+copy_u8Position);
			break;
		}
		case 2:{
			LCD_SendCommend(0b11000000+copy_u8Position);
			break;
		}
		
	}
	
}