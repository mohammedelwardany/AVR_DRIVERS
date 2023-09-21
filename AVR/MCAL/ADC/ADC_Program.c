/*
 * ADC_Program.c
 *
 * Created: 9/16/2023 9:10:42 AM
 *  Author: m2010
 */ 
#include "types.h"
#include "bitMath.h"



#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"


//ARRAY OF OUR GROUPS
u8 AdcScanGroup1[4]={ SG1Channel0,SG1Channel1,SG1channel2,SG1channel3 };
u8 AdcScanGroup0[4]={ SG0Channel0,SG0Channel1,SG0channel2,SG0channel3 };
u8 * ptr[2]={AdcScanGroup0 , AdcScanGroup1}	;
	
void ADC_init() {
	

	#if (AUTO_TRIGGER_MODE == DISABLED)
	
	ADC_ADCSRA    =  (1 <<AD_EN) | (1<<ADIE) | ADC_Division_Factor ;

	#else
	
	ADC_ADCSRA    = ADC_Division_Factor| (1 <<AD_EN) | (1<<ADIE) | 1<<ADATE;
	
	ADC_SFIOR = (AUTO_TRIGGER_SOURCE << ADTS0)| (SFIOR & 0x0F);
	
	#endif
	

	
	
}	
	

void ADC_Scan_Sync_Group(ScanGroup_t ScanGroupId , u16 *buffer ){
	u8 CHindex = 0;
	for (CHindex;CHindex<4;CHindex++)
	{
		buffer[CHindex]=ADC_Scan_Single(ptr[ScanGroupId][CHindex]);
	}
}

u16 ADC_Scan_Single(u8 ADC_CH){
	ADC_ADMUX = (VOLTAGE_REFERENCE<<REFS0) | (ADC_ADJUSTMENT<<ADLAR) | ADC_CH;
	SetBit(ADC_ADCSRA,ADSC);
	//while(ISLOW(ADC_ADCSRA,ADIF));
	SetBit(ADC_ADCSRA,ADIF);
	return ADC_REG;
}