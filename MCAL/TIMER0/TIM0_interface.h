/*
 * TIM0_interface.h
 *
 * Created: 9/9/2024 10:38:38 AM
 *  Author: AMIT
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_



/* FAST PWM MODE */

#define  INVERTING_MODE       0
#define  NON_INVERTING_MODE   1

/*select  your mode */

#define  FASTPWMMODE     NON_INVERTING_MODE

/* TIM0  prescaler */
/*select timer0 prescaler */
#define  NO_PRESCALER         1 
#define _8_PRESCALER          2 
#define _64_PRESCALER         3
#define _256_PRESCALER        4
#define _1024_PRESCALER       5 


#define  TIM0_PRESCALER      _64_PRESCALER


/* timer0 mode */
#define  OV_MODE      0 
#define  CTC_MODE     1 

/* OCR VAL */

#define  OCR_VAL    250

void TIM0_voidOVCTCInit( u8 copy_u8mode) ; 
void TIM0_voidSetCallBack(void(*ptr)(void), u8 copy_u8mode) ; 

void TIM0_voidFastPWM(u8 copy_dc) ; 
#endif /* TIM0_INTERFACE_H_ */