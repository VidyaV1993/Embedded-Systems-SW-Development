/*
	Significance of pointer data type
*/

#include<stdio.h>

long long int  g_data = 0xFFFEABCD11112345;

int main(void)
{

 char *pAddress1;
 pAddress1 = (char*)&g_data;
 printf("Value at address %p is : %x\n",pAddress1,*pAddress1); //Prints 45 - 1 byte (char)


 int *pAddress2;
 pAddress2 = (int*)&g_data;
 printf("Value at address %p is : %x\n",pAddress2,*pAddress2);//Prints 11112345 - 4 bytes (int)


 short *pAddress3;
 pAddress3 = (short*)&g_data;
 printf("Value at address %p is : %x\n",pAddress3,*pAddress3);//Prints 2345 - 2 bytes (short)

 long long *pAddress4;
 pAddress4 = (long long*)&g_data;
 printf("Value at address %p is : %I64x\n",pAddress4,*pAddress4);//Prints FFFEABCD11112345 - 8 bytes (long long)

 return 0;
}
