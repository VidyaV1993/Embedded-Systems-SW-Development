
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vidya Viswanathan
 * @brief          : SVC demo
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
Write a program to execute an SVC instruction from thread mode,
implement the svc handler to print the SVC number used.
Also,  increment the SVC number by 4 and return it to the thread mode code and print it.
Hints :
1)Write a main() function where you should execute the SVC instruction with an argument.
let's say SVC #0x5
2)Implement the SVC handler
3)In the SVC handler extract the SVC number and print it using printf
4) Increment the SVC number by 4 and return it to the thread mode
*/

#include<stdio.h>
#include<stdint.h>
int main(void)
{
	__asm volatile ("SVC #25");

	//register uint32_t data __asm("r0"); //this creates a variable data in the processor register R0. This will fail if the register is not free and hence this is not recommended.

	uint32_t data;

	__asm volatile ("MOV %0,R0": "=r"(data) ::); //Move the contents of R0 to variable data

	printf(" data = %ld\n",data);

	for(;;);
}


__attribute__ ((naked)) void SVC_Handler(void)
{
	//1 . get the value of the MSP
	__asm("MRS R0,MSP"); //Extract MSP using inline assembly. //If we implement this in C function itself, prologue and epilogue instructions are generated and it will corrupt MSP.
	__asm("B SVC_Handler_c"); //Go to the C function SVC_Handler_c
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
	printf("in SVC handler\n");

	uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];//Get the PC which has the return address

	//2. decrement the return address by 2 to point to
	//opcode of the SVC instruction in the program memory
	pReturn_addr-=2;


	//3. extract the SVC number (LSByte of the opcode)
    uint8_t svc_number = *pReturn_addr;

    printf("Svc number is : %d\n",svc_number);

    svc_number+=4; //if we want to send this to thread mode, we want to store this in the stack register say R0.

    pBaseOfStackFrame[0] = svc_number; //store in R0

}
