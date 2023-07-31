/*
 * LDR_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"

void LDR_vid_init(void)
{
	ADC_init();
}
u32 LDR_u32_value(u8 u8channelNumCopy )
{
	u32 Light;
	Light=u8ADC_Channel_Reading(u8channelNumCopy);
			return Light;
}
