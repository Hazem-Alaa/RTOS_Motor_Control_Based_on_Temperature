/*
 * TIM0_prog.c
 *
 * Created: 9/9/2024 10:39:08 AM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_math.h" 
#include "../../LIB/STD_types.h" 
#include "TIM0_interface.h" 
#include "TIM0_reg.h" 
#include <stddef.h>

void (*TIM0_PTR[2])(void)={NULL}; 



void TIM0_voidOVCTCInit( u8 copy_u8mode){
	
	/* set prescaler */
	
	TCCR0_REG&=0b11111000 ;
	TCCR0_REG|=TIM0_PRESCALER ;
	
	
	 if (copy_u8mode==OV_MODE)
	 {
		  /* select mode */
		  
		  CLR_BIT(TCCR0_REG,3) ;
		  CLR_BIT(TCCR0_REG,6) ;
		  	
		  	/* enable  ov interrupt */
		  	SET_BIT(TIMSK_REG,0) ;
	 }
	  else if (copy_u8mode==CTC_MODE)
	  {
		   /* select mode */
		   
		   SET_BIT(TCCR0_REG,3) ;
		   CLR_BIT(TCCR0_REG,6) ;
		   
		   /* enable  CTC interrupt */
		   SET_BIT(TIMSK_REG,1) ;
		  
		  /*SET OCR VAL */
		  
		  OCR0_REG=OCR_VAL  ; 
	  }

}




void TIM0_voidSetCallBack(void(*ptr)(void), u8 copy_u8mode)
{
	
	switch(copy_u8mode){
		
		case  OV_MODE : TIM0_PTR[0]= ptr ; break; 
		case  CTC_MODE : TIM0_PTR[1]=ptr ; break  ; 
	}
	
	
	
}
void TIM0_voidFastPWM(u8 copy_dc){
	/*select mode : fast pwm mode  */
	
	SET_BIT(TCCR0_REG,3) ;
	SET_BIT(TCCR0_REG,6) ;
	/* set prescaler */
	TCCR0_REG&=0b11111000 ;
	TCCR0_REG|=TIM0_PRESCALER ;
	#if FASTPWMMODE == NON_INVERTING_MODE
	SET_BIT(TCCR0_REG,5) ;
	CLR_BIT(TCCR0_REG,4) ;
	#elif 	FASTPWMMODE ==INVERTING_MODE
	SET_BIT(TCCR0_REG,5) ;
	SET_BIT(TCCR0_REG,4) ;
	#endif

	OCR0_REG=copy_dc * 2.56 ;
	
}



/* isr overflow */
void __vector_11(void)__attribute__((signal)) ;
void __vector_11(void){
	
 TIM0_PTR[0]() ; 

}
/* isr ctc */
void __vector_10(void)__attribute__((signal)) ;
void __vector_10(void){
	
	TIM0_PTR[1]() ; 

}