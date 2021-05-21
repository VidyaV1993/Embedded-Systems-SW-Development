/**
  ******************************************************************************
  * @file    main.c
  * @brief   volatile keyword use
  ******************************************************************************
*/

/**
  ****************************************************************************************************************************************
  * volatile keyword enforces the compiler not to do any optimization on variable operations even on higher optimization levels.
  * If you see the disassembly for this program, you can see instructions are generated for the unused variables data1 and data2
  * even on higher optimization levels up to O3. If you eliminate the keyword volatile and look at the disassembly, instructions are only
  * generated for the for loop and nothing else since the variables are unused.

  ****************************************************************************************************************************************
*/
#include<stdint.h>

int main(void)
{
	uint8_t volatile data1;
	uint8_t volatile data2;

	data1 = 50;

	data2 = data1;

	data2 = data1;

	for(;;);
}
