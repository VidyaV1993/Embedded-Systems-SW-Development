/*
	Effect of using different pointer data types on pointer operations
*/


#include<stdio.h>
#include<stdint.h>

long long int  g_data = 0xFFFEABCD11112345; //data value

int main(void)
{

	 int *pAddress = (int*)&g_data;


	printf("value of pAddress %p\n",pAddress); //address is printed
	printf("Value at address %p is %x\n", pAddress, *pAddress); //value is printed as 45 (1 byte for char)

	pAddress = pAddress + 1; //incremented by 1 byte since char (if it is short, +1 will increment 2 bytes)

	printf("value of pAddress %p\n",pAddress); //address is incremented by 1
	printf("Value at address %p is %x", pAddress, *pAddress); //value is printed as 23 (1 byte for char), since pointer is incremented by one

	return 0;

}
