/*
 * UART_reg.h
 *
 * Created: 6/28/2024 11:32:56 AM
 *  Author: AMIT
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_



#define  UDR_REG              *((volatile u8*)0x2C)
#define  UCSRA_REG            *((volatile u8*)0x2B)
#define  UCSRB_REG            *((volatile u8*)0x2A)
#define  UBRRL_REG            *((volatile u8*)0x29)
#define  UCSRC_REG            *((volatile u8*)0x40)

#endif /* UART_REG_H_ */