/*
 * HLED_program.c
 *
 *  Created on: Mar 31, 2020
 *      Author: Bishoy Nabil
 */
#include "RCC_interface.h"
#include "GPIO.h"
#include "SCHEDULAR_interface.h"

void HLED_Runnable(void);
static PinParam_t GPIOStr = {
		PORTC,
		PIN13,
		OUTPUT_2MHZ_PUSH_PULL
};
extern TaskInterface_t HLED_Task = {
		HLED_Runnable,
		500
};

void HLED_Runnable(void)
{
	u8 Local_u8State = 0;
	u8 Local_u8InitFlag = 0;
	switch(Local_u8State)
	{
	case 0:
	{
		if(Local_u8InitFlag == 0)
		{
			RCC_EnableAPB2Peripheral(IOPC);
			DIO_Init(&GPIOStr);
			GPIOStr.Pin = SET_PIN13;
			DIO_SetPinValue(&GPIOStr , 1);
			Local_u8InitFlag = 1;
		}
		//LED OFF
		DIO_SetPinValue(&GPIOStr , 1);
		Local_u8State = 1;
	}break;
	case 1:
	{
		//LED ON
		DIO_SetPinValue(&GPIOStr , 0);
		Local_u8State = 0;
	}break;
	}
}
