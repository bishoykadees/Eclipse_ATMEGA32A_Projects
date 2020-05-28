/*
 * main.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Lenovo
 */
#include <stdio.h>
//#include "Dunga.h"
int* func(int x,int y)
{
	printf("%d\n%d",x,y);
}
void main(void)
{
	/*
	char *ptr="Dunga";
	*ptr='c';
	printf("%c",*ptr);
	*/

	/*
	char c[]="Ahmed";
	func(c);
	*/

	/*
	char x='z';
	char y;
	char const *const ptr=(char*)&x;
	//*ptr='y';
	ptr=&y;
	*/

	/*
	char *ptr;
	//*ptr=100;
	printf("%d",*ptr);
	*/
	
	/*
	void *ptr;
	int x=5;
	float y=7;
	//(int*)ptr=(int*)&x;
	*(int*)ptr=8;
	//(float*)ptr=(float*)&y;
	printf("%d",*ptr);
	*/
	
	/*
	int x=5,y=6;
	int*(*ptr)(int x,int y)=(int*(*)(int x,int y))func;
	ptr(x,y);
	*/
	
	
	
}

