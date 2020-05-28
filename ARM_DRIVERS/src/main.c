#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "SCHEDULAR_interface.h"
#include "GPIO.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"

/*
u32 Cov = 0;
PinParam_t GPIOStr;
STK_t      STKStr;
NVIC_t     NVICStr;
*/

//void LED(void);
void main(void)
{
	SCHEDULAR_Init();
	SCHEDULAR_Start();
	/*
	RCC_EnableAPB2Peripheral(IOPC);
	GPIOStr.Port = PORTC;
	GPIOStr.Pin = PIN13;
	GPIOStr.Mode = OUTPUT_2MHZ_PUSH_PULL;
	DIO_Init(&GPIOStr);

	STKStr.TimeUS = 500000;
	STKStr.CallBackPtr = &LED;
	STKStr.InterruptControl = INTERRUPT_ENABLED;
	STKStr.Prescaler = AHB_DIVIDED_BY_EIGHT;
	STKStr.Cov = &Cov;

	STK_Init(&STKStr);
	STK_SetCallBack(&STKStr);
	STK_SetTime(&STKStr);
	STK_Start();
	GPIOStr.Pin = SET_PIN13;
	DIO_SetPinValue(&GPIOStr , 1);
	*/
	while(1);
}

/*
void LED(void)
{
	static u8 i = 0;
	static u8 counter = 0;

	counter ++;

	if(counter < Cov)
	{
		STK_SetMaxPreload();
		STK_Start();
	}
	else
	{
		if(i == 0)
		{
			DIO_SetPinValue(&GPIOStr , 1);
			i=1;
		}
		else if(i == 1)
		{
			DIO_SetPinValue(&GPIOStr , 0);
			i=0;
		}
		STKStr.TimeUS = 500000;
		STK_SetTime(&STKStr);
		counter = 0;
		STK_Start();
	}
}
*/
