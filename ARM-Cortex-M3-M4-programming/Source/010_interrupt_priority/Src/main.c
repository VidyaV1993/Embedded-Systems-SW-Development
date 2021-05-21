/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vidya Viswanathan
 * @brief          : Interrupt priority configuration
 ******************************************************************************
 */

/*
 * Generate the below peripheral interrupts using NVIC interrupt pending register and observe the execution of ISRs when priorities
 * are same and different: TIM2 global interrupt and I2C1 event interrupt.
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define IRQNO_TIMER2  28 //IRQ number from vector table.
#define IRQNO_I2C1    31 //IRQ number from vector table.

#include<stdint.h>
#include<stdio.h>

/* NVIC register addresses. Refer to the processor generic guide section 4.2 table */
uint32_t *pNVIC_IPRBase =  (uint32_t*)0xE000E400;
uint32_t *pNVIC_ISERBase = (uint32_t*)0xE000E100;
uint32_t *pNVIC_ISPRBase = (uint32_t*)0XE000E200;


void configure_priority_for_irqs(uint8_t irq_no, uint8_t priority_value)
{
	//1. find out iprx
	uint8_t iprx = irq_no / 4;
	uint32_t *ipr =  pNVIC_IPRBase+iprx;

	//2. position in iprx
	uint8_t pos = (irq_no % 4) * 8;

	//3. configure the priority
	*ipr &= ~(0xFF << pos);				//clear the pos
	*ipr |=  (priority_value << pos);	//configure

}

int main(void)
{
	//1. Lets configure the priority for the peripherals
	 configure_priority_for_irqs(IRQNO_TIMER2,0x80);
	 configure_priority_for_irqs(IRQNO_I2C1,0x80); //Increase the priority of I2C1

	//2. Set the interrupt pending bit in the NVIC PR
	 *pNVIC_ISPRBase |= ( 1 << IRQNO_TIMER2); //Interrupt for timer2 will be triggered

	//3. Enable the IRQs in NVIC ISER
	 *pNVIC_ISERBase |= ( 1 << IRQNO_I2C1);
	 *pNVIC_ISERBase |= ( 1 << IRQNO_TIMER2);


}

//isrs: can be found in startup file

void TIM2_IRQHandler(void)
{
  printf("[TIM2_IRQHandler]\n");
  /*
   * Here, we are pending I2C interrupt request manually, but the control will not go to  I2C1_EV_IRQHandler because the priority levels for
   * TIMER2 and I@C1 are same 0x80. Code will be hanged in while loop. If we increase the priority of I2C1 to 0x70, then code execution goes
   * to I2C1_EV_IRQHandler. This is called Interrupt Nesting. After executing I2C1_EV_IRQHandler, code execution goes back to TIM2_IRQHandler.
   */
  *pNVIC_ISPRBase |= ( 1 << IRQNO_I2C1);
  while(1);

}


void I2C1_EV_IRQHandler(void)
{
  printf("[I2C1_EV_IRQHandler]\n");
}
