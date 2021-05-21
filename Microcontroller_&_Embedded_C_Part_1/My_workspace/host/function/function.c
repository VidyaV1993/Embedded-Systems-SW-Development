/*
	Program to write a function to do a task
*/

#include <stdio.h>

void function_add_numbers(int  , int  , int  );

int main()
{
	//int retValue;

	function_add_numbers(12,13,0);
	function_add_numbers(-12,12,2);
	function_add_numbers(12,12,12);

	//printf("Sum = %d\n",retValue);


    return 0;
}

// This is function definition
void function_add_numbers(int a , int b , int c )
{
	 int sum ;
	 sum = a+b+c;
	 printf("Sum = %d\n",sum);

	 //return sum;
}
