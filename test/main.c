/*
 * main.c
 *
 *  Created on: Dec 27, 2019
 *      Author: Lenovo
 */
#include <avr/io.h>

int main(void)
{
	DDRA=0XFF;
	while(1)
	{
		PORTA=0XFF;
	}
	return 0;
}
