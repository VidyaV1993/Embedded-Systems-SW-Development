/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vidya Viswanathan
 * @brief          : Hello World
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>

int main(void)
{
	printf("Hello World!\n");
	for(;;);
}
