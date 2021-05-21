/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vidya Viswanathan
 * @brief          : USART3 interrupt pending demo
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include<stdio.h>

#define USART3_IRQNO 39

int main(void)
{
	//1. Manually pend the pending bit for the USART3 IRQ number in NVIC
	uint32_t *pISPR1 = (uint32_t*)0XE000E204; //Base addr of ISPR1 = = Base addr of ISPR0 + 4
	*pISPR1 |= ( 1 << (USART3_IRQNO % 32)); //Enable 7th bit position

	//2. Enable the USART3 IRQ number in NVIC
	uint32_t *pISER1 = (uint32_t*)0xE000E104; //Base addr of ISER1 = Base addr of ISER0 + 4
	*pISER1 |= ( 1 << (USART3_IRQNO % 32));

	for(;;);
}

//USART3 ISR
void USART3_IRQHandler(void)
{
	printf("in USART3 isr\n");
}
