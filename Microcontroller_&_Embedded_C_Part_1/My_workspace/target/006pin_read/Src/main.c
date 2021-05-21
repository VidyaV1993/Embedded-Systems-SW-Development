/**
  ******************************************************************************
  * @file    main.c
  * @brief   Pin Read exercise
  ******************************************************************************
*/

#include<stdint.h>

int main(void)
{
	//RCC base addr = 0x40023800
	uint32_t  volatile *const pClkCtrlReg =   (uint32_t*)0x40023830; //offset for RCCAHB1ENR = 0x30

	//portD base addr = 0x40020C00
	uint32_t  volatile *const pPortDModeReg = (uint32_t*)0x40020C00; //offset = 0x00
	uint32_t  volatile *const pPortDOutReg =  (uint32_t*)0x40020C14; //offset = 0x14

	//portA base addr = 0x40020000
	uint32_t volatile *const pPortAModeReg = (uint32_t*)0x40020000; //offset = 0x00
	uint32_t const volatile *const pPortAInReg =   (uint32_t*)0x40020010; //offset = 0x10


	//enable the clock for GPOID , GPIOA peripherals in the RCCAHB1ENR
	*pClkCtrlReg |= ( 1 << 3); //GPOID
	*pClkCtrlReg |= ( 1 << 0); //GPOIA

    //configuring PD12 as output
	*pPortDModeReg &= ~( 3 << 24); //clear 24th and 25th bits
	//make 24th bit position as 1 (SET)
	*pPortDModeReg |= ( 1 << 24); //Set 24th bit to 1

	//Configure PA0 as input mode (GPIOA MODE REGISTER)
	*pPortAModeReg &= ~(3 << 0); //clear 0th and 1st bits

	while(1)
	{
		//read the pin status of the pin PA0 (GPIOA INPUT DATA REGISTER)
		uint8_t  pinStatus = (uint8_t)(*pPortAInReg & 0x1); //zero out all other bits except bit 0, we just need bit 0

		if(pinStatus){
			//turn on the LED
			*pPortDOutReg |= ( 1 << 12);
		}else{
			//turn off the LED
			*pPortDOutReg &= ~( 1 << 12);
		}
	}
}
