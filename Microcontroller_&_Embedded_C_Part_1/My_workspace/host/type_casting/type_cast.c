/*
	Program to demonstrate type casting
*/

#include<stdio.h>

int main(void)
{

   unsigned char data1 = (unsigned char) 0x1FFFFFFFA0B0 + 0x1245; // Info loss happens here
   unsigned char data2 = 0x01 + 0x89; // No info loss

   float  result1 = (float) 80 / 3 ;//type casting done
   float  result2 =  80 / 3 ;// No type casting, decimal part is omitted

   printf("Data1 : %u  Data2 : %u  result1 : %f  result2 : %f\n",data1 ,data2, result1, result2);

   return 0;

}
