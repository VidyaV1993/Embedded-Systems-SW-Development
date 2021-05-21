/*
	Program to demonstrate structure pointers
*/

#include<stdint.h>
#include<stdio.h>

struct DataSet
{
	char data1;
	int  data2;
	char data3;
	short data4;
};


void displayMemberElements(struct DataSet data);
void displayMemberElements1(struct DataSet *pData);


int main(void)
{

	struct DataSet data = {0, 0, 0, 0};

	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	printf("Before:\n");
	displayMemberElements(data); //pass by value

	struct DataSet *pData;
	pData = &data;
	pData->data1 = 0x55;

	printf("After:\n");
	displayMemberElements1(&data);//pass by reference


	getchar();

	return 0;

}


void displayMemberElements(struct DataSet data)//pass by value
{
	printf("data1 = %X\n",data.data1);
	printf("data2 = %X\n",data.data2);
	printf("data3 = %X\n",data.data3);
	printf("data4 = %X\n",data.data4);

}

void displayMemberElements1(struct DataSet *pData) //pass by reference
{
	printf("data1 = %X\n",pData->data1);
	printf("data2 = %X\n",pData->data2);
	printf("data3 = %X\n",pData->data3);
	printf("data4 = %X\n",pData->data4);

}












