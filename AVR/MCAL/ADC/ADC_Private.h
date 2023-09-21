/*
 * ADC_Private.h
 *
 * Created: 9/15/2023 2:44:28 PM
 *  Author: m2010
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADC_ADMUX *((volatile u8*)0x27)

#define  REFS1		7
#define  REFS0		6
#define  ADLAR		5
#define  MUX4		4
#define  MUX3	    3
#define  MUX2	   	2
#define  MUX1		1
#define  MUX0		0


#define ADC_ADCSRA *((volatile u8*)0x26)

#define  AD_EN		7 //set enable
#define  ADSC		6 //start conversion
#define  ADATE		5 // ADC Auto Trigger Enable
#define  ADIF		4 //ADC Interrupt Flag
#define  ADIE	    3 // ADC Interrupt Enable
#define  ADPS2	   	2 // ADPS2:0: ADC Prescaler Select Bits
#define  ADPS1		1
#define  ADPS0		0

#define ADC_ADCL *((volatile u8*)0x25)
#define ADC_ADCH *((volatile u8*)0x24)
//16 TO ADCL + ADCH
#define ADC_REG *((volatile u16*)0x24)

#define  ADC_SFIOR (*((volatile u8 *)(0x50)))

//ADTS2:0: ADC Auto Trigger Source
#define  ADTS2 7
#define  ADTS1 6
#define  ADTS0 5









#endif /* ADC_PRIVATE_H_ */