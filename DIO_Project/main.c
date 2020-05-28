/*
 * main.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"

void main(void)
{
	/*task 01*/
	/*
	u32 counter;
	setPinDir('A',0,1);
	while(1)
	{
		setPinValue('A',0,0);
		for(counter=0;counter<216216;counter++)
		{}
		setPinValue('A',0,1);
		for(counter=0;counter<216216;counter++)
		{}
	}
	*/

	/*task 02*/
	/*
	u32 counter;
	u8 pin;
	for(pin=0;pin<8;pin++)
	{
		setPinDir('A',pin,1);
	}
	while(1)
	{
		for(pin=0;pin<8;pin++)
		{
			setPinValue('A',pin,1);
		}
		for(counter=0;counter<216216;counter++)
		{}
		for(pin=0;pin<8;pin++)
		{
			setPinValue('A',pin,0);
		}
		for(counter=0;counter<216216;counter++)
		{}
	}
	*/

	/*task 03*/
	u32 counter;
	u8 pin;
	for(pin=0;pin<5;pin++)
	{
		setPinDir('A',pin,1);
	}
	while(1)
	{
		//1
		setPinValue('A',0,1);
		delay
		setPinValue('A',0,0);
		//2
		setPinValue('A',1,1);
		setPinValue('A',2,1);
		setPinValue('A',3,1);
		setPinValue('A',4,1);
		delay
		setPinValue('A',1,0);
		setPinValue('A',2,0);
		setPinValue('A',3,0);
		setPinValue('A',4,0);
		//3
		setPinValue('A',0,1);
		setPinValue('A',1,1);
		delay
		setPinValue('A',0,0);
		setPinValue('A',1,0);
		//4
		setPinValue('A',4,1);
		setPinValue('A',3,1);
		setPinValue('A',2,1);
		delay
		setPinValue('A',4,0);
		setPinValue('A',3,0);
		setPinValue('A',2,0);
		//5
		setPinValue('A',1,1);
		setPinValue('A',0,1);
		setPinValue('A',2,1);
		delay
		setPinValue('A',1,0);
		setPinValue('A',0,0);
		setPinValue('A',2,0);
		//6
		setPinValue('A',3,1);
		setPinValue('A',4,1);
		delay
		setPinValue('A',3,0);
		setPinValue('A',4,0);
		//7
		setPinValue('A',2,1);
		setPinValue('A',3,1);
		setPinValue('A',0,1);
		setPinValue('A',1,1);
		delay
		setPinValue('A',2,0);
		setPinValue('A',3,0);
		setPinValue('A',0,0);
		setPinValue('A',1,0);
		//8
		setPinValue('A',4,1);
		delay
		setPinValue('A',4,0);
	}

}
