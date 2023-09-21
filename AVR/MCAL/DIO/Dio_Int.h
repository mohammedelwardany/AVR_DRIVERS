/*
 * Dio_Int.h
 *
 * Created: 9/9/2023 1:49:23 AM
 *  Author: m2010
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "types.h"

#include "bitMath.h"

#include "DIO_Cfg.h"
#include "DIO_prv.h"


typedef enum {
	Pin_A0  ,Pin_A1	,Pin_A2	,Pin_A3	,Pin_A4	,Pin_A5	, Pin_A6 ,Pin_A7 ,
	Pin_B0	,Pin_B1 ,Pin_B2 ,Pin_B3	,Pin_B4 ,Pin_B5	, Pin_B6 ,Pin_B7 ,
	Pin_C0	,Pin_C1	,Pin_C2	,Pin_C3	,Pin_C4	,Pin_C5	, Pin_C6 ,Pin_C7 ,
	Pin_D0	,Pin_D1	,Pin_D2	,Pin_D3	,Pin_D4	,Pin_D5	, Pin_D6 ,Pin_D7 ,
}Pin_Type;

typedef enum {
	OutPut_High , OutPut_Low,
	InPut_Float,InPut_PullUp
}PinMode_type;



void DIO_Init(void);
void Dio_SetPinMode(Pin_Type Pin_ID , PinMode_type Mode);
void DIO_ReadPinVal(Pin_Type Pin_ID ,u8 * ReadBufferPTR );
void DIO_WritePinVal(Pin_Type Pin_ID ,u8 VALUE );


//void DIO_init (u8 PinNumber,u8 PortNum,u8 Dirction);

//void DIO_Write (u8 PinNumber,u8 PortNum,u8 Value);

//void DIO_Toggle (u8 PinNumber,u8 PortNum);

//void DIO_Read (u8 PinNumber,u8 PortNum,u8 *Value);


//void Dio_SetPinChMode(u8 P_ID,u8 Mode);

//void Dio_WritePinChannel(u8 P_ID,u8 Value);

//void Dio_WritePortChannel(u8 P_ID,u8 Value);

//void Dio_ReadPinChannel(u8 P_ID,u8* Buffer_Ptr);

//void Dio_ReadPortChannel(u8 P_ID,u8* Buffer_Ptr);
 



#endif /* DIO_INT_H_ */