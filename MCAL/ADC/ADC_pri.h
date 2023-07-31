/*
 * ADC_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_PRI_H_
#define MCAL_ADC_ADC_PRI_H_

#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)
#define ADCH  *((volatile u8*)0x25)
#define ADCL  *((volatile u8*)0x24)
#define ADC_DATA *((volatile u16*)0x24)
#endif /* MCAL_ADC_ADC_PRI_H_ */
