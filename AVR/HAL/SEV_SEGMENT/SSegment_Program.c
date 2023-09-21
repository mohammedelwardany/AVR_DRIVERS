/*
 * SSegment_Program.c
 *
 * Created: 9/15/2023 9:24:05 AM
 *  Author: m2010
 */ 
#include <util/delay.h>
#include "types.h"
#include "bitMath.h"

#include "Dio_Int.h"

#include "SSegment_Config.h"
#include "SSegment_Interface.h"


void Ssegmintinit(){
Dio_SetPinMode(A,OutPut_High);
Dio_SetPinMode(B,OutPut_High);
Dio_SetPinMode(C,OutPut_High);
Dio_SetPinMode(D,OutPut_High);
Dio_SetPinMode(COM1,OutPut_High);
Dio_SetPinMode(COM2,OutPut_High);
Dio_SetPinMode(COM3,OutPut_High);
Dio_SetPinMode(COM4,OutPut_High);

}




void SevenSegment_Value(u16 copy_u32value){
	
u16 arr[COM_Numbers];
DIO_WritePinVal(arrayLocation[0],HIGH);
DIO_WritePinVal(arrayLocation[1],HIGH);
DIO_WritePinVal(arrayLocation[2],HIGH);
DIO_WritePinVal(arrayLocation[3],HIGH);
for(u8 j=0;copy_u32value!=0;j++){
	
	arr[j] = (copy_u32value%10);
		DIO_WritePinVal(A,GetBit(numbersArr[copy_u32value%10],0));
		DIO_WritePinVal(B,GetBit(numbersArr[copy_u32value%10],1));
		DIO_WritePinVal(C,GetBit(numbersArr[copy_u32value%10],2));
		DIO_WritePinVal(D,GetBit(numbersArr[copy_u32value%10],3));
	copy_u32value/=10;
	DIO_WritePinVal(arrayLocation[j],LOW);
	_delay_ms(2);
	DIO_WritePinVal(arrayLocation[j],HIGH);
}






}