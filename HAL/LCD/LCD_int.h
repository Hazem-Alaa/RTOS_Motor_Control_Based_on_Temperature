/*
 * LCD_int.h
 *
 * Created: 14/08/2024 10:36:54 ص
 *  Author: hazem alaa
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_



#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_config.h"


#define LCD_CLR             0X01
#define LCD_HOME            0X02
#define LCD_ENTRY_MODE      0X06
#define LCD_FUNSET_8BIT     0X38
#define LCD_DISPON_CURON    0X0C

#define LCD_CGRAM_ADDRESS   0X40
#define LCD_DDRAM_SETCURS   0X80


void LCD_voidSendCMD(u8 u8CMD); //Send Instruction to LCD
void LCD_voidWriteChar(u8 u8CHAR); //Send data to LCD
void LCD_voidLCDInit();
void LCD_voidGoTo(u8 X, u8 Y); // X: 1->16  Y: 1-2
void LCD_ClrLCD();
void LCD_voidWriteStrig(u8 *ptrStr);
void LCD_voidWriteNum(s32 s32NUM);

void LCD_voidSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[]);
void LCD_voidWriteCustomChar(u8 CGRAMIndex);
#endif /* LCD_INT_H_ */