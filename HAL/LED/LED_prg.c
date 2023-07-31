/*
 * LED_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_cfg.h"
#include "avr/delay.h"
void LED_vid_init(void)
{
DIO_SetPinDirection(LED_PORT,LED_PIN,OUTPUT);
}

void LED_vid_toggle(void)
{
 DIO_SetPinValue(LED_PORT,LED_PIN,HIGH);
 _delay_ms(200);
 DIO_SetPinValue(LED_PORT,LED_PIN,LOW);
}

void LED_vid_LOW(void)
{
	 DIO_SetPinValue(LED_PORT,LED_PIN,LOW);
}
