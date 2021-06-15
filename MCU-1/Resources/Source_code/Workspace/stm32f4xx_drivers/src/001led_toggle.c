/*
 * 001led_toggle.c
 *
 *  Created on: Feb 1, 2019
 *      Author: admin
 */

#include "stm32f407xx.h"


void delay(void)
{
	for(uint32_t i = 0 ; i < 500000 ; i ++);
}


int main(void)
{

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD; //Open Drain
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	//Notes: LED does not toggle in OD config bcoz the pin cannot be pulled to GND in open drain.
	//If we use internal pull up resistor (very high value) GPIO_PIN_PU, LED toggles with very less intensity (since very less current flows through the LED) in OD config. Hence use external pull up resistor.
	//Hence LED toggles with correct intensity only in push pull configuration.

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();
	}
	return 0;
}
