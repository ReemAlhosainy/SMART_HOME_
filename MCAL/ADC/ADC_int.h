/*
 * ADC_int.h
 *
 *  Created on: ??�/??�/????
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3
#define CHANNEL4 4
#define CHANNEL5 5
#define CHANNEL6 6
#define CHANNEL7 7




void ADC_init(void);

u32 u8ADC_Channel_Reading(u8 u8ChannelReadCopy);


#endif /* MCAL_ADC_ADC_INT_H_ */
