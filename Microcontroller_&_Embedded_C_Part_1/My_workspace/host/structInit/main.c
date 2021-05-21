/*
	Program to demonstrate Structures
*/


#include<stdint.h>
#include<stdio.h>

struct carModel1
{
	uint8_t carSpeed;
	uint32_t carPrice;
};

struct carModel2
{
	uint16_t carMaxSpeed;
	uint32_t carNumber;
	uint32_t carPrice;
	float carWeight;
};

int main(void)
{
	//Initialize structure
	struct carModel2  carBMW = {220, 2021, 15000, 1330}; //C89 method
	//struct carModel2  carFord = {.carMaxSpeed= 320, .carNumber= 2020, .carPrice= 16000, .carWeight= 1330.45}; //C99 method

	//Accessing structure variables
	printf("Details of carBMW:\n");
	printf("carNumber = %u\n", carBMW.carNumber);
	printf("carMaxSpeed = %u\n", carBMW.carMaxSpeed);
	printf("carPrice = %u\n", carBMW.carPrice);
	printf("carWeight = %f\n", carBMW.carWeight);

	printf("Sizeof of struct carModel2 is %u\n",sizeof(struct carModel2));

    getchar();

	return 0;
}









