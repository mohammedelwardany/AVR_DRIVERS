/*
 * I2C_Interface.h
 *
 * Created: 9/24/2023 2:40:31 PM
 *  Author: m2010
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "types.h"

void TWI_voidInitMaster(u8 Copy_u8Add);
void TWI_voidMasterSendStartCondition(void); 
void TWI_voidMasterSendRepeatStartCondition(void); 
void TWI_voidMasterSendStopCondition(void); 
void TWI_voidMasterSendSlaveAddressRead(u8 Copy_u8SlaveAdd);
void TWI_voidMasterSendSlaveAddressWrite(u8 Copy_u8SlaveAdd); 
void TWI_voidReceiveMasterDataByte(u8 *TWI_u8ReadBuffer);
void TWI_voidSendMasterDataByte(u8 Copy_u8Data);


#endif /* I2C_INTERFACE_H_ */