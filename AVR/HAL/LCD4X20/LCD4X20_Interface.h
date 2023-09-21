/*
 * LCD4X20_Interface.h
 *
 * Created: 9/16/2023 8:42:37 PM
 *  Author: m2010
 */ 


#ifndef LCD4X20_INTERFACE_H_
#define LCD4X20_INTERFACE_H_


#define F_CPU 16000000
#include <util/delay.h>

#include "types.h"
#include "bitMath.h"

#include "Dio_Int.h"

#include "LCD4X20_Private.h"
#include "LCD4X20_Config.h"


void LCD4X20_init();
void LCD_Write_CMD(u8 CMD);
void LCD_Write_CHAR(u8 CHAR);
void LCD_WriteString(const u8 * str);

void LCD_WriteNUM(s64 NUM);
void LCD_WriteFLOAT(f64 num,u8 Percision);
void LCD_Clear(void);




#endif /* LCD4X20_INTERFACE_H_ */