/*
 * main.c
 *
 *  Created on: Dec 26, 2019
 *      Author: Lenovo
 */



#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SevenSegment_interface.h"

#include <util/delay.h>

int main(void)
{
	portInit();
	while(1)
	{
		SEVENSEG_Enable(0);
		SEVENSEG_setNumber(5);
		_delay_us(3000);
		SEVENSEG_Disable(0);
		SEVENSEG_Enable(1);
		SEVENSEG_setNumber(7);
		_delay_us(3000);
		SEVENSEG_Disable(1);
	}
	return 0;
}
