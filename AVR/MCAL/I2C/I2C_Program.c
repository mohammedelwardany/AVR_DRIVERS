/*
 * I2C_Program.c
 *
 * Created: 9/24/2023 2:40:51 PM
 *  Author: m2010
 */ 
#include "bitMath.h"

#include "I2C_Private.h"
#include "I2C_Interface.h"

void TWI_voidInitMaster(u8 Copy_u8Add){
	if(Copy_u8Add<128){
		TWAR = Copy_u8Add<<1;
	}
	
	/////////////////////////////////////BRESCALER///////////////////////////////////// 400KHZ
	TWBR = 12;
	ClrBit(TWSR,TWSR_TWPS0);
	ClrBit(TWSR,TWSR_TWPS1);
	
	SetBit(TWCR,TWCR_TWEA); //EN ACK
	
	SetBit(TWCR,TWCR_TWEN); //EN TWI  LAZEM TB2A A5R 5ATWA
	
}
void TWI_voidMasterSendStartCondition(void){
	SetBit(TWCR,TWCR_TWSTA);  //REQ START CONDITION
	
	SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
	
	while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
	
	while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_StartCondition);  //check status register
}
void TWI_voidMasterSendRepeatStartCondition(void){
		SetBit(TWCR,TWCR_TWSTA);  //REQ START CONDITION
		
		SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
		
		while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
		
		while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_StartRepeatCondition);  //check status register
}
void TWI_voidMasterSendStopCondition(void){
			SetBit(TWCR,TWCR_TWSTO);  //REQ STOP CONDITION
			
			SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
}
void TWI_voidMasterSendSlaveAddressRead(u8 Copy_u8SlaveAdd){
	//LOCAL ERROR STATE STATE = PASS IN ELSE FAIL
		if(Copy_u8SlaveAdd<128){
			TWDR = Copy_u8SlaveAdd<<1;
			SetBit(TWDR,0);
			
			SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
					
			while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
					
			while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_MasterRecive);  //check status register
			
			
		}
		else{
		//ERROR HANDLING	
		}
}
void TWI_voidMasterSendSlaveAddressWrite(u8 Copy_u8SlaveAdd){
		//LOCAL ERROR STATE STATE = PASS IN ELSE FAIL
		if(Copy_u8SlaveAdd<128){
			TWDR = Copy_u8SlaveAdd<<1;
			ClrBit(TWDR,0);
			
			SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
			
			while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
			
			while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_MasterTransmitted);  //check status register
			
			
		}
		else{
			//ERROR HANDLING
		}
}

void TWI_voidSendMasterDataByte(u8 Copy_u8Data){
	//write data on data bus
	TWDR = Copy_u8Data;
	
	SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
	
	while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
	
	while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_MasterSendData);  //check status register	
}

void TWI_voidReceiveMasterDataByte(u8 *TWI_u8ReadBuffer){
	if (TWI_u8ReadBuffer != '\0')
	{
			SetBit(TWCR,TWCR_TWINT);  //CLEAR FLAG MANUALY
			
			while(0 == GetBit(TWCR,TWCR_TWINT)); // FLAG CHECK IF 1 THEN START CONDITION
			
			while(TWI_STATUS_VALUE != TWI_STATUS_VALUE_MasterReciveData);  //check status register
			
			*TWI_u8ReadBuffer = TWDR;
	}

}