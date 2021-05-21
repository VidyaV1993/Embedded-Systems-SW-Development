/*
	Program to demonstrate const type qualifier
*/



#include <stdio.h>
#include <stdint.h>

//uint8_t const data = 10; //Program crashes. Compiler has kept this in read only memory.

int main(void)
{
	uint8_t const data = 10; //Program executes, value changes

	printf("Value = %u\n",data);

	uint8_t *ptr = (uint8_t*)&data; //uint8_t const *

	*ptr = 50;

	printf("Value = %u\n",data);

	getchar();
}
