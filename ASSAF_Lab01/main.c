/*
 * main.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Lenovo
 */
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <util/delay.h>

void main(void)
{
	u8 i,j;


	for(i=0;i<8;i++)
		{
			setPinDir('A',i,1);
		}

	while(1)
	{
		for(i=8,j=0;i>=1&&j<8;)
		{
			i--;
			j++;
			setPinValue('A',i,1);
			setPinValue('A',j,1);
			_delay_ms(250);
			setPinValue('A',i,0);
			setPinValue('A',j,0);
		}

	}

	/*
	while(1)
	{
		for(i=0;i<8;i++)
		{
			setPinValue('A',i,1);
			_delay_ms(150);
			setPinValue('A',i,0);
		}
		for(i=7;i>=2;i--)
		{
			setPinValue('A',i-1,1);
			_delay_ms(150);
			setPinValue('A',i-1,0);
		}
	}
	*/


}
