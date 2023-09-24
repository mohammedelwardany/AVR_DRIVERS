/*
 * USART_Interface.h
 *
 * Created: 9/22/2023 2:57:53 PM
 *  Author: m2010
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "USART_Private.h"
#include "USART_Config.h"

void USART_voidInit(void);
void DataTransmit(u8 DataValues);
void DataRecive(u8 * ReadBufferPTR);

#endif /* USART_INTERFACE_H_ */