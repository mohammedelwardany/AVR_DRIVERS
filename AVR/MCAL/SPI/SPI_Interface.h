/*
 * SPI_Interface.h
 *
 * Created: 9/23/2023 11:55:33 AM
 *  Author: m2010
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Private.h"
#include "SPI_Config.h"


void SPI_voidInit(void);
u8 SPI_u8SendRecieveByte(u8 Copy_u8Data, u8 *Copy_pu8RecData);



#endif /* SPI_INTERFACE_H_ */