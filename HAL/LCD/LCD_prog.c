/*
 * CFile1.c
 *
 * Created: 14/08/2024 10:38:08 ص
 *  Author: hazem alaa
 */ 

#include "LCD_int.h"

void LCD_voidSendCMD(u8 u8CMD)//Send Instruction to LCD
{

	DIO_voidSetPinVal(LCD_RS,LOW);	
	DIO_voidSetPinVal(LCD_RW,LOW);	
	DIO_voidSetPortVal(LCD_PORT,u8CMD);
		
	DIO_voidSetPinVal(LCD_E,HIGH);
	DIO_voidSetPinVal(LCD_E,LOW);
	_delay_ms(5);
}


void LCD_voidWriteChar(u8 u8CHAR) //Send data to LCD
{
		DIO_voidSetPinVal(LCD_RS,HIGH);
		DIO_voidSetPinVal(LCD_RW,LOW);
		DIO_voidSetPortVal(LCD_PORT,u8CHAR);
		
		DIO_voidSetPinVal(LCD_E, HIGH);
		DIO_voidSetPinVal(LCD_E, LOW);
		_delay_ms(5);
}

void LCD_voidLCDInit(){
	
	DIO_voidSetPinDir(LCD_RS,OUTPUT);
	DIO_voidSetPinDir(LCD_RW,OUTPUT);
	DIO_voidSetPinDir(LCD_E,OUTPUT);
	DIO_voidSetPortDir(LCD_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(31);
	LCD_voidSendCMD(LCD_FUNSET_8BIT);
	_delay_us(40);
	LCD_voidSendCMD(LCD_DISPON_CURON);
	_delay_us(40);
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(1.54);
	LCD_voidSendCMD(LCD_ENTRY_MODE);
	_delay_ms(2);

}

void LCD_voidGoTo(u8 X, u8 Y)
{
	if (X>0 && X<=16)
	{
		switch(Y)
		{
			case 0: LCD_voidSendCMD(127+X);break;
			case 1: LCD_voidSendCMD(191+X);break;
			default:break;	
		}	
	}
}

void LCD_ClrLCD()
{
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(2);
	
}
void LCD_voidWriteStrig(u8 *ptrStr)
{
	u8 counter=0;
	
	while(ptrStr[counter]!='\0')
	{
		LCD_voidWriteChar(ptrStr[counter]);
		counter++;
	}
	
}

void LCD_voidWriteNum(s32 s32NUM)
{
	u32 temp= 1;
	if(s32NUM==0){
		LCD_voidWriteChar('0');
	}

	if(s32NUM<0){
		LCD_voidWriteChar('-');
		s32NUM*=-1;
	}
	while(s32NUM!=0)
	{
		temp= (temp*10)+s32NUM%10;
		s32NUM/=10;
	}
	while(temp !=1)
	{
		LCD_voidWriteChar((temp%10)+48);
		temp/=10;
	}
}

void LCD_voidSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[])
{
	
	LCD_voidSendCMD(LCD_CGRAM_ADDRESS+CGRAMIndex*8);
	
	for(u8 i = 0 ; i<8; i++)
	{
		
		LCD_voidWriteChar(CustomChar[i]);
	}
	
	LCD_voidSendCMD(LCD_DDRAM_SETCURS);
}

void LCD_voidWriteCustomChar(u8 CGRAMIndex)
{
	if(CGRAMIndex)
	{
		LCD_voidWriteChar(CGRAMIndex);
		
	}
}
