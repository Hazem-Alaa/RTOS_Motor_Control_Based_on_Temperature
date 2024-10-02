/*
 * UART_prog.c
 *
 * Created: 6/28/2024 11:33:37 AM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_math.h" 
#include "../../LIB/STD_types.h" 
#include "UART_reg.h" 


void UART_voidInit(void){
	
	u8 temp=0 ; 
	
	/* set bit7 to select UCSRC REG */
	     SET_BIT(temp,7) ; 
		 
	/* set bit 1& bit 2 in UCSRC reg to write 8 bit data */	 
	      SET_BIT(temp,1) ; 
		  SET_BIT(temp,2) ; 
		  
		  /* set UCSRC reg */
		  UCSRC_REG=temp ; 
		  
	/* set Baud rate */
	UBRRL_REG=103 ; 
	
	/* Enable tx  & rx */
	SET_BIT(UCSRB_REG,4) ; 
	SET_BIT(UCSRB_REG,3) ; 
}
void UART_voidTX(u8 copy_u8data) {

            UDR_REG=copy_u8data ; 
			
			while(GET_BIT(UCSRA_REG,5)==0);        

}


u8 UART_u8RX(void){
	while(GET_BIT(UCSRA_REG,7)==0); 
	
	return UDR_REG ; 
}
