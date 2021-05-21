/**
  ******************************************************************************
  * @file    main.c
  * @brief   Keypad interfacing project
  ******************************************************************************
*/

#include<stdint.h>
#include<stdio.h>

void delay(void)
{
	for(uint32_t i =0 ; i < 300000 ; i++);

}

int main(void)
{
	//peripheral register addresses
	uint32_t volatile *const pGPIODModeReg  =  (uint32_t*)(0x40020C00);
	uint32_t volatile *const pInPutDataReg  =  (uint32_t*)(0x40020C00+0x10);
	uint32_t volatile *const pOutPutDataReg =  (uint32_t*)(0x40020C00+0x14);
	uint32_t volatile *const pClockCtrlReg  =  (uint32_t*)(0x40023800+0x30);
	uint32_t volatile *const pPullupDownReg =  (uint32_t*)(0x40020C00 + 0x0C);

     //1.Enable the peripheral clock of GPIOD peripheral (SET the 3rd bit position)
	*pClockCtrlReg |= ( 1 << 3);


    // 2.configure PD0,PD1,PD2,PD3 as output (rows)
	*pGPIODModeReg &= ~(0xFF); //clear 1st 8 bit positions
	*pGPIODModeReg |= 0x55;   //set 01 01 01 01 there


	// 3. configure PD8 , PD9, PD10, PD11 as input (columns)
    *pGPIODModeReg &= ~(0xFF << 16); //clear bit 16 to bit 24 - left shift by 16 input mode (00) hence cleared.

	// 4.Enable internal pull-up resistors for PD8 PD9 PD10 PD11
    *pPullupDownReg &= ~(0xFF << 16);
    *pPullupDownReg |=  (0x55 << 16);

 while(1)
 {
    //make all rows HIGH
    *pOutPutDataReg |= 0x0f;

    //make R1 LOW(PD0)
    *pOutPutDataReg &= ~( 1 << 0);

    //scan the columns
    //check C1(PD8) low or high. Pressed means input reg will be 0, that's why ! operator used
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("1\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("2\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("3\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("A\n");
    }


    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R2 LOW(PD1)
    *pOutPutDataReg &= ~( 1 << 1);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("4\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("5\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("6\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("B\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R3 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 2);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("7\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("8\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("9\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("C\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R4 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 3);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("*\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("0\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("#\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("D\n");
    }

 }//while end

}
