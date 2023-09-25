/*
 * EX_EEPROM_Program.c
 *
 * Created: 9/25/2023 10:37:54 AM
 *  Author: m2010
 */ 

#include <util/delay.h>

#include "bitMath.h"

#include "I2C_Interface.h"

#include "EX_EEPROM_Interface.h"

void EX_EEPROM_voidInit(void){
	TWI_voidInitMaster(255);
}
void EX_EEPROM_voidWriteByte(u16 Copy_u16WordAddress , u8 Copy_u8Data){
	u8 addressRes =(Copy_u16WordAddress>>8)|EEPROMfIXED_ADD;
	TWI_voidMasterSendStartCondition();
	TWI_voidMasterSendSlaveAddressWrite(addressRes);
	TWI_voidSendMasterDataByte((u8)Copy_u16WordAddress);
	TWI_voidSendMasterDataByte(Copy_u8Data);
	TWI_voidMasterSendStopCondition();
	_delay_ms(5);
}

void EX_EEPROM_voidReadByte(u16 Copy_u16WordAddress , u8* Copy_pu8RxData){
	u8 addressRes = (u8)(Copy_u16WordAddress>>8)|EEPROMfIXED_ADD;
	TWI_voidMasterSendStartCondition();
	TWI_voidMasterSendSlaveAddressWrite(addressRes);
	TWI_voidSendMasterDataByte((u8)Copy_u16WordAddress);
	TWI_voidMasterSendRepeatStartCondition();
	TWI_voidMasterSendSlaveAddressRead(addressRes);
	TWI_voidReceiveMasterDataByte(Copy_pu8RxData);
	TWI_voidMasterSendStopCondition();
	_delay_ms(5);
}