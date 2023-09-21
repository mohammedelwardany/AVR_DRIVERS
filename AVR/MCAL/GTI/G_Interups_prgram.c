/*
 * G_Interups_prgram.c
 *
 * Created: 9/11/2023 11:54:09 AM
 *  Author: m2010
 */ 
#include "types.h"
#include "bitMath.h"


#include "G_Interups_Interface.h"
#include "G_Interups_Private.h"


void GINTERUPTS_voidEnable(void){
	SetBit(SREG,G_I);
}
void GINTERUPTS_voidDesable(void){
	ClrBit(SREG,G_I);
}