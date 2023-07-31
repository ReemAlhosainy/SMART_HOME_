/*
 * ADC_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "ADC_pri.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
u32 u8ADC_Channel_Reading(u8 u8ChannelReadCopy)
{
ADMUX&=0b11100000;
ADMUX|=u8ChannelReadCopy;

SET_BIT(ADCSRA,6);   /*start conversion*/
while(GET_BIT(ADCSRA,4)==0);
SET_BIT(ADCSRA,4); /*clear the flag==set the bit 1*/

return ADC_DATA;
}

void ADC_init(void)
{
	/*8 bit mode , aVcc ref voltage polling (not interrupt)*/
	    CLR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	/*activate left adjust mode*/
		CLR_BIT(ADMUX,5);
    /*prescaller division by 128*/
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);

    /*ADC enable*/
		SET_BIT(ADCSRA,7);
}
