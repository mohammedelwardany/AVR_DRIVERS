/*
* Interface_LCD.h
*
* Created: 9/10/2023 1:48:58 PM
*  Author: m2010
*/


#ifndef INTERFACE_LCD_H_
#define INTERFACE_LCD_H_

#include "types.h"

#include "bitMath.h"

#include "Dio_Int.h"



typedef enum{
	type8bit,type4bit
}Bitlvl;

typedef enum{
	Commend,Data
}MODE;

typedef enum{
	Cursor,Screen
}ShiftingPlatform;

typedef enum{
	LEFT,RIGHT
}DIRICTIONS;





void LCD_init(void);
void LCD_SendData(u8 Val_u8);

void LCD_SendCommend(u8 Val_u8);


void LCD_voidWriteString(u8* copy_pu8String);
void LCD_voidWriteNumber(u32 copy_u32Number);
void LCD_voidClear(void);
void LCD_voidShift(DIRICTIONS copy_ShifttingDirection,ShiftingPlatform copy_ShifttingPlatform);
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);
// 	Create Special Pattern




#endif /* INTERFACE_LCD_H_ */