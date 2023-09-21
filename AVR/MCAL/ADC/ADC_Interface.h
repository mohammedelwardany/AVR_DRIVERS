/*
 * ADC_Interface.h
 *
 * Created: 9/16/2023 9:10:12 AM
 *  Author: m2010
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


//ENUM OF OUR SELECTION GROUP
typedef enum { ScanGroup0,ScanGroup1 }ScanGroup_t 	 ;

void ADC_Init(void);
void ADC_Scan_Sync_Group(ScanGroup_t ScanGroupId , u16 *buffer );
u16 ADC_Scan_Single(u8 ADC_CH);

#endif /* ADC_INTERFACE_H_ */