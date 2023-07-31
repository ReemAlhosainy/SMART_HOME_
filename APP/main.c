/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include "../HAL/Lcd/lcd_cfg.h"
#include "../HAL/Lcd/lcd_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/TEMP_sensor/TEMP_sensor_int.h"
#include "../HAL/LDR/LDR_int.h"

#include "../HAL/SERVO_PWM/SERVO_int.h"
#include <avr/delay.h>
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_pri.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/timer1_PWM/timer1PWM_int.h"


int main (void)
{
	LED_vid_init();
	LCD_vidInit();
	u32 temp,Light;
	LCD_vidInit();
	LM35_vid_init();
	SERVO_init_vid(PORTD,PIN5);
	timer1_FAST_PWM_init_vid();
	LDR_vid_init();

	LCD_vidSendCommand(LCD_CLEAR);

	DIO_SetPinDirection(PORTD,PIN7,OUTPUT);
	/*fan*/
	DIO_SetPinDirection(PORTD,PIN4,OUTPUT);




	while(1)
	{
		temp=u8ADC_Channel_Reading(CHANNEL2);
		temp= (temp*150*5)/(1023*1.5);


		if(temp<50)
		{
			if (temp>30)
			{
				DIO_SetPinValue(PORTD,PIN4,HIGH);
				DIO_SetPinValue(PORTD,PIN7,LOW);
				LCD_VidGotoRawCol(0,0);
				LCD_vidWriteString("Temp:");
				LCD_VidGotoRawCol(0,8);
				LCD_vid_num_to_str(temp);
				LCD_VidGotoRawCol(0,10);
				LCD_vidWriteChar('c');
				LED_vid_LOW();
			}
			else
			{
				DIO_SetPinValue(PORTD,PIN4,LOW);
				DIO_SetPinValue(PORTD,PIN7,LOW);
				LCD_VidGotoRawCol(0,0);
				LCD_vidWriteString("Temp:");
				LCD_VidGotoRawCol(0,8);
				LCD_vid_num_to_str(temp);
				LCD_VidGotoRawCol(0,10);
				LCD_vidWriteChar('c');
				LED_vid_LOW();
			}

		}

		else
		{
			LED_vid_toggle();
			LCD_VidGotoRawCol(0,0);
			LCD_vidWriteString("WARNING !! FIRE!!");
			DIO_SetPinValue(PORTD,PIN7,HIGH);
			_delay_ms(50);
			DIO_SetPinValue(PORTD,PIN7,LOW);
			_delay_ms(50);
			LCD_vidSendCommand(LCD_CLEAR);
			DIO_SetPinValue(PORTD,PIN4,HIGH);//fan

		}


		Light=u8ADC_Channel_Reading(CHANNEL3);
		if(Light>70)
		{
			Timer_set_dutyCycle(124);
			_delay_ms(1500);
		}
		else
		{
			Timer_set_dutyCycle(250);
				_delay_ms(1500);
		}
	}
	return 0;
}
