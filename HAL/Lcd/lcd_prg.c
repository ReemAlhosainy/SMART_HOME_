/*
 * lcd_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "lcd_cfg.h"
#include "lcd_int.h"
#include <avr/delay.h>
#include <stdlib.h>

void LCD_vidInit(void)
{
  DIO_SetPORTDirection(LCD_DATA_PINS,OUTPUT);
  DIO_SetPinDirection(LCD_CTRL_PINS,LCD_RS_PIN,OUTPUT);
  DIO_SetPinDirection(LCD_CTRL_PINS,LCD_RW_PIN,OUTPUT);
  DIO_SetPinDirection(LCD_CTRL_PINS,LCD_EN_PIN,OUTPUT);
  _delay_ms(30);

  LCD_vidSendCommand(LCD__HOME);
  _delay_ms(15);

  LCD_vidSendCommand(LCD_FUNCTION_SET_8BIT);
  _delay_ms(1);
  LCD_vidSendCommand(LCD_DISPLAY_ON);
  _delay_ms(1);
  LCD_vidSendCommand(LCD_CLEAR);
  _delay_ms(15);
  LCD_vidSendCommand(LCD_ENTRY_MODE);
  _delay_ms(2);

}

void LCD_vidSendCommand(u8 u8CmdCopy)
{
	/*1- Set RS = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_RS_PIN,LOW);

   /*2- Set RW = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_RW_PIN,LOW);

  /*3- Set EN = HIGH*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,HIGH);

  /*4- Set command on bus*/
DIO_SetPort_Value(LCD_DATA_PINS,u8CmdCopy);

  /*5- Set EN = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,LOW);

  /*6- wait 5 ms-sec*/
 _delay_ms(5);

 /*7-Set EN = HIGH*/
 DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,HIGH);

 /*8- wait 10 ms-sec*/
 _delay_ms(10);


}

void LCD_vidWriteChar (u8 u8DataCopy)
{
	/*1- Set RS = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_RS_PIN,HIGH);

   /*2- Set RW = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_RW_PIN,LOW);

  /*3- Set EN = HIGH*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,HIGH);

  /*4- Set command on bus*/
DIO_SetPort_Value(LCD_DATA_PINS,u8DataCopy);

  /*5- Set EN = LOW*/
DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,LOW);

  /*6- wait 5 ms-sec*/
 _delay_ms(5);

 /*7-Set EN = HIGH*/
 DIO_SetPinValue(LCD_CTRL_PINS,LCD_EN_PIN,HIGH);

 /*8- wait 10 ms-sec*/
 _delay_ms(10);
}

void LCD_vidWriteString (u8* pu8StringCopy)
{
u8 i=0;
while(pu8StringCopy[i]!='\0')
{
 LCD_vidWriteChar(pu8StringCopy[i]);
 i++;
 _delay_ms(2);
}
}
void LCD_VidGotoRawCol (u8 u8RawCopy, u8 u8ColCopy)

{u8 Address;
  switch(u8RawCopy)
  {
  case 0:     Address=u8ColCopy;               break;
  case 1:     Address=u8ColCopy+0x40;          break;
  /*if it 4*16*/
  case 2:     Address=u8ColCopy+0x10;          break;
  case 3:     Address=u8ColCopy+0x50;          break;
  }
  LCD_vidSendCommand(Address|LCD_SET_CURSOR );
}

void LCD_vid_num_to_str(u8 u8NumCopy)
{
	{
		u8 u8CharArr[3]={' '};
		for(u8 j=0;j<3;j++)
		{
			u8CharArr[j]=' ';
		}
		LCD_VidGotoRawCol(0,5);
	itoa(u8NumCopy,u8CharArr,10);
	for(u8 j=0;j<3;j++)
			{
		if(u8CharArr[j]<'0'||u8CharArr[j]>'9')
		{
			LCD_vidWriteChar(' ');
		}
		else
		{
			LCD_vidWriteChar(u8CharArr[j]);
		}
 			}
	}
}




