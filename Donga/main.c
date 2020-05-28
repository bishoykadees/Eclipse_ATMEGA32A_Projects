/*
 * main.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Lenovo
 */
#include <stdio.h>

int func(int arr[],int size)
{
	int temp=0;
	unsigned int i;
	for(i=0;i<size;i++)
	{
		temp=temp^arr[i];
	}
	return temp;
}


void main(void)
{
	int x;
	int arr[5]={1,4,6,1,4};
	x=func(arr,5);
	printf("the number repeated odd times is %d",x);
}

