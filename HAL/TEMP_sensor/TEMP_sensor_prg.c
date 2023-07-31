/*
 * TEMP_sensor_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "TEMP_sensor_cfg.h"
#include "TEMP_sensor_int.h"
#include <avr/delay.h>

/*
 * steps:
 * 1- read temperature by volt
 * 2-asking ADC to convert it to digital
 * 2- transverse it to temp
 *      10 mv=1 C
 * 3-return with it
 */
void LM35_vid_init(void)
{
	ADC_init();
}
u32 LM35_u16_value(u8 u8channelNumCopy )
{
	u32 temp;
	temp=u8ADC_Channel_Reading(u8channelNumCopy);
	temp= (temp*150*5)/(1023*1.5);
			return temp;
}
