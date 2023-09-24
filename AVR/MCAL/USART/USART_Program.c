/*
 * USART_Program.c
 *
 * Created: 9/22/2023 2:58:33 PM
 *  Author: m2010
 */ 
#include "bitMath.h"

#include "USART_Interface.h"
void USART_voidInit(void){
	//USART Control and Status Register C init
	SetBit(UCSRC,URSEL);
	//async mode
	ClrBit(UCSRC,UMSEL);
	//dont use parity
	ClrBit(UCSRC,UPM0);
	ClrBit(UCSRC,UPM1);
	//set 1 stop bit--
	ClrBit(UCSRC,USBS);
	// set Character Size
	ClrBit(UCSRC,UCSZ2);
	SetBit(UCSRC,UCSZ1);
	SetBit(UCSRC,UCSZ0);
	// no need for any polarity
	
	//set INTERUPTS
/*	SetBit(UCSRB,UDRIE);*/

	
	//.. ENABLE Communication
	SetBit(UCSRB,TXEN);
	SetBit(UCSRB,RXEN);
	
	// tx -- rx 8-bit
// 	SetBit(UCSRB,RXB8);
// 	SetBit(UCSRB,TXB8);
// 	
	
	//SET POUD RATE
	UBRRL = 103;
}

void DataTransmit(u8 DataValues){
// 	SetBit(UCSRB,TXCIE);
// 	ClrBit(UCSRB,RXCIE);


	while(GetBit(UCSRA,UDRE)==0);
	UDR = DataValues;
	while(GetBit(UCSRA,TXC)==0);
}
void DataRecive(u8 * ReadBufferPTR){

	while(GetBit(UCSRA,UDRE)==0);
	*ReadBufferPTR=UDR;
	while(GetBit(UCSRA,RXC)==0);
}