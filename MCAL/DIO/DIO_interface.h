/*
 * DIO_interface.h
 *
 * Created: 8/25/2024 2:13:52 PM
 *  Author: hazem alaa
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_reg.h"

#define  OUTPUT     1 
#define  INPUT      0 

#define  DIO_PORT_OUTPUT     0XFF
#define  DIO_PORT_INPUT      0X00


#define  HIGH       1
#define  LOW        0 


#define  DIO_PORTA     0 
#define  DIO_PORTB     1 
#define  DIO_PORTC     2 
#define  DIO_PORTD     3 

/* PINS  */
#define  DIO_PIN0      0
#define  DIO_PIN1      1
#define  DIO_PIN2      2
#define  DIO_PIN3      3
#define  DIO_PIN4      4
#define  DIO_PIN5      5
#define  DIO_PIN6      6
#define  DIO_PIN7      7


void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin ,u8 copy_u8Dir) ; 

void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin ,u8 copy_u8val) ;

u8 DIO_u8GetPinVal(u8 copy_u8port, u8 copy_u8pin ) ; 

void DIO_voidToggelPinVal(u8 copy_u8port, u8 copy_u8pin ) ; 


void  DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8Dir) ; 
void  DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8val) ;






#endif 