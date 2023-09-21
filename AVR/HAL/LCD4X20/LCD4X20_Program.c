/*
 * LCD4X20_Program.c
 *
 * Created: 9/16/2023 8:52:06 PM
 *  Author: m2010
 */ 


#include "LCD4X20_Interface.h"

void LCD4X20_init(){

	_delay_ms(16);
	LCD_Write_CMD(0x33);
	_delay_ms(1);
	LCD_Write_CMD(0x32);
	_delay_ms(1);
	LCD_Write_CMD(CMD_LCD_4Bit_Mode_1_Line_5X8);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Display_Cursor_ON_Blink_OFF);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Clear_Display);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Return_Home);
	_delay_ms(2);
	
	
	
	
	
}

void LCD_Write_CMD(u8 CMD){
	

DIO_WritePinVal(RS_PIN,LOW);
DIO_WritePinVal(E_PIN,LOW);
	
_delay_ms(1);
DIO_WritePinVal(E_PIN,HIGH);
	
	#if( LCD_DATA_PORT==DIO_PORTA )
	PORTA= (CMD & 0xF0) | (PORTA & 0x0F) ;
	#elif( LCD_DATA_PORT==DIO_PORTB )
	PORTB= (CMD & 0xF0) | (PORTB & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTC )
	PORTC= (CMD & 0xF0) | (PORTC & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTD )
	PORTD= (CMD & 0xF0) | (PORTD & 0x0F) ;
	#endif
	DIO_WritePinVal(E_PIN,LOW);
	_delay_ms(1);
	DIO_WritePinVal(E_PIN,HIGH);
	
	#if( LCD_DATA_PORT==DIO_PORTA )
	PORTA= (CMD << 4) | (PORTA & 0x0F) ;
	#elif( LCD_DATA_PORT==DIO_PORTB )
	PORTB= (CMD << 4 ) | (PORTB & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTC )
	PORTC= (CMD << 4) | (PORTC & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTD )
	PORTD= (CMD << 4) | (PORTD & 0x0F) ;
	#endif
	DIO_WritePinVal(E_PIN,LOW);
	_delay_ms(1);
	
	
	
}

void LCD_Write_CHAR(u8 CHAR){
	DIO_WritePinVal(RS_PIN,HIGH);
	
	DIO_WritePinVal(E_PIN,LOW);
	_delay_ms(1);
	DIO_WritePinVal(E_PIN,HIGH);
	
	#if( LCD_DATA_PORT==DIO_PORTA )
	PORTA= (CHAR & 0xF0) | (PORTA & 0x0F) ;
	#elif( LCD_DATA_PORT==DIO_PORTB )
	PORTB= (CHAR & 0xF0) | (PORTB & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTC )
	PORTC= (CHAR & 0xF0) | (PORTC & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTD )
	PORTD= (CHAR & 0xF0) | (PORTD & 0x0F) ;
	#endif
	DIO_WritePinVal(E_PIN,LOW);
	_delay_ms(1);
	
	
	
	DIO_WritePinVal(E_PIN,HIGH)	;
	#if( LCD_DATA_PORT==DIO_PORTA )
	PORTA= (CHAR << 4) | (PORTA & 0x0F) ;
	#elif( LCD_DATA_PORT==DIO_PORTB )
	PORTB= (CHAR << 4 ) | (PORTB & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTC )
	PORTC= (CHAR << 4) | (PORTC & 0x0F) ;
	
	#elif( LCD_DATA_PORT==DIO_PORTD )
	PORTD= (CHAR << 4) | (PORTD & 0x0F) ;
	#endif
	DIO_WritePinVal(E_PIN,LOW);
	_delay_ms(1);
	
	
	
}


void LCD_GoTo(u8 ROW, u8 COL)
{
	u8 Address[2] = {LCD_Line1_1stAddress, LCD_Line2_1stAddress};
	LCD_Write_CMD(Address[ROW] + COL);
}


void LCD_Clear(void)
{
	LCD_Write_CMD(CMD_Clear_Display);
}

void LCD_WriteString(const u8 * str){
	
	while( (*str) !='\0'){
		
		
		LCD_Write_CHAR(*str);
		str++;
		
	}
	
	
}




void LCD_WriteNUM(s64 NUM){
	u64 Multiplier=1;
	
	if(NUM == 0){	LCD_Write_CHAR('0'); 	}
	
	else
	{
		if(NUM < 0) {	LCD_Write_CHAR('-');
		NUM *= -1;		 }
		
		if(NUM > 0){
			
			while( (s64)(NUM/Multiplier) != 0){	Multiplier*=10;	}

			do
			{
				Multiplier/=10;
				LCD_Write_CHAR( NUM/Multiplier +'0');
				NUM %=Multiplier;
			}
			while(Multiplier != 1 );
			
		}
	}
}

void LCD_WriteFLOAT(f64 num,u8 Percision)
{



	u64 val,i;
	val = (u64) num;
	LCD_WriteNUM(val);
	LCD_Write_CHAR('.');
	num -= val;
	for (i = 0; i < Percision; i++)
	{
		num *=10;
		val = (int)num;
		LCD_Write_CHAR(val+'0');
		num -=val;
	}
}


