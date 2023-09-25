/*
 * I2C_Private.h
 *
 * Created: 9/24/2023 2:40:15 PM
 *  Author: m2010
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWI_STATUS_VALUE							(TWSR&0xf8)
#define TWI_STATUS_VALUE_StartCondition				0x08
#define TWI_STATUS_VALUE_StartRepeatCondition		0x10
#define TWI_STATUS_VALUE_MasterTransmitted			0x18
#define TWI_STATUS_VALUE_MasterRecive				0x40
#define TWI_STATUS_VALUE_MasterSendData				0x28
#define TWI_STATUS_VALUE_MasterReciveData			0x50

#define TWBR    *((volatile u8 *)0x20)
//////////////////////////////////////////////////////////////////////////


#define TWSR    *((volatile u8 *)0x21)

#define TWSR_TWPS1             1
#define TWSR_TWPS0             0

//////////////////////////////////////////////////////////////////////////
#define TWAR    *((volatile u8 *)0x22)
#define TWAR_TWGCE             0

//////////////////////////////////////////////////////////////////////////
#define TWDR    *((volatile u8 *)0x23)

//////////////////////////////////////////////////////////////////////////
#define TWCR    *((volatile u8 *)0x56)
#define TWCR_TWINT             7
#define TWCR_TWEA              6
#define TWCR_TWSTA             5
#define TWCR_TWSTO             4
#define TWCR_TWWC              3
#define TWCR_TWEN              2
#define TWCR_TWIE              0



#endif /* I2C_PRIVATE_H_ */