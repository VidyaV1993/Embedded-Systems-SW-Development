/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vidya Viswanathan
 * @brief          : bit banding
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include<stdint.h>

#define ALIAS_BASE   0x22000000U

#define BITBAND_BASE 0x20000000U

int main(void)
{
	uint8_t *ptr = (uint8_t*)0x20000200; //Given memory address

	*ptr = 0xff;

	//normal method
	//clearing 7th bit position
	*ptr &= ~( 1 << 7);

	//reset to 0xff
	*ptr = 0xff;

	//bit band method
	uint8_t *alias_addr = (uint8_t*) (ALIAS_BASE+(32 * (0x20000200-BITBAND_BASE))+ 7 * 4);

	//clearing 7th bit of address 0x20000200
	*alias_addr = 0;

	for(;;);
}
