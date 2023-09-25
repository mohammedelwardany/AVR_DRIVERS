/*
 * EX_EEPROM_Interface.h
 *
 * Created: 9/25/2023 10:37:21 AM
 *  Author: m2010
 */ 


#ifndef EX_EEPROM_INTERFACE_H_
#define EX_EEPROM_INTERFACE_H_

#include "types.h"


#define  EEPROMfIXED_ADD	 0x80
void EX_EEPROM_voidInit(void);
void EX_EEPROM_voidWriteByte(u16 Copy_u16WordAddress , u8 Copy_u8Data);
void EX_EEPROM_voidReadByte(u16 Copy_u16WordAddress , u8* Copy_pu8RxData);



#endif /* EX_EEPROM_INTERFACE_H_ */