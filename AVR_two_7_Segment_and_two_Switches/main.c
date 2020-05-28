/*
 * main.c
 *
 *  Created on: Dec 26, 2019
 *      Author: Lenovo
 */

#define F_CPU 8000000UL

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SWITCH_interface.h"
#include "SevenSegment_interface.h"

#include <util/delay.h>

int main(void)
{
	/* counter for any "for" loop */
	u32 i;

	/* flag of switch 1 is pressed or not
	 * pressed=1
	 * not_pressed=0 */
	u8 Switch_One_Status=0;

	/* flag of switch 2 is pressed or not
	 * Pressed=1
	 * Not_Pressed=0 */
	u8 Switch_Two_Status=0;

	/* flag for the two switches are pressed or not
	 * Pressed=1
	 * Not_Pressed=0 */
	u8 Both_Switches_are_preesed=0;

	/* counter of the first 7 segment */
	u8 counter1=0;

	/* counter of the second 7 segment */
	u8 counter2=0;

	/* configuration of each Port */
	portInit();

	while(1)
	{
		while(1)
		{
			/* enable the first 7 segment */
			SEVENSEG_Enable(0);
			/* printing the counter of the first 7 segment */
			SEVENSEG_setNumber(counter1);
			/* disable the first 7 segment */
			SEVENSEG_Disable(0);

			/* enable the second 7 segment */
			SEVENSEG_Enable(1);
			/* printing the counter of the second 7 segment */
			SEVENSEG_setNumber(counter2);
			/* disable the second 7 segment */
			SEVENSEG_Disable(1);

			/* checking if the first switch is pressed */
			if(getSwitchState(0)==0x01)
			{
				/* loop to hold time to detect if the user pressed on the 2 switches at the same time */
				for(i=0;i<1000;i++)
				{
					/* checking if the second switch is pressed while the first is already pressed */
					if(getSwitchState(1)==0x01)
					{
						/* enable the flag that the two switches are pressed at the same time */
						Both_Switches_are_preesed=1;
						break;
					}
				}
				/* checking if the 2 switches are not pressed at the same time */
				if(Both_Switches_are_preesed==0)
				{
					/* enable the flag that indicates that the first switch is pressed */
					Switch_One_Status=1;
				}
				break;
			}
			/* checking if the second switch is pressed */
			else if(getSwitchState(1)==0x01)
			{
				/* loop to hold time to detect if the user pressed on the 2 switches at the same time */
				for(i=0;i<1000;i++)
				{
					/* checking if the second switch is pressed while the first is already pressed */
					if(getSwitchState(0)==0x01)
					{
						/* enable the flag that the two switches are pressed at the same time */
						Both_Switches_are_preesed=1;
						break;
					}
				}
				/* checking if the 2 switches are not pressed at the same time */
				if(Both_Switches_are_preesed==0)
				{
					/* enable the flag that indicates that the first switch is pressed */
					Switch_Two_Status=1;
				}
				break;
			}
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/* checking if the first switch is pressed */
		if(Switch_One_Status==1)
		{
			/* incrementing the counter of the first 7 segment */
			counter1++;
			/* resetting the counter of the first switch */
			if(counter1==10)
			{
				counter1=0;
			}
			/* holding the time to know if the user pressed the first switch for a long time  */
			for(i=0;getSwitchState(0)==0x01;i++)
			{
				if(i>20000)
				{
					counter1++;
					if(counter1==10)
					{
						counter1=0;
					}

					SEVENSEG_Enable(0);
					SEVENSEG_setNumber(counter1);
					_delay_us(50000);
					SEVENSEG_Disable(0);

					SEVENSEG_Enable(1);
					SEVENSEG_setNumber(counter2);
					_delay_us(10000);
					SEVENSEG_Disable(1);
				}
			}
			Switch_One_Status=0;
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(Switch_Two_Status==1)
		{
			counter2++;
			if(counter2==10)
			{
				counter2=0;
			}
			for(i=0;getSwitchState(1)==0x01;i++)
			{
				if(i>20000)
				{
					counter2++;

					if(counter2==10)
					{
						counter2=0;
					}

					SEVENSEG_Enable(0);
					SEVENSEG_setNumber(counter1);
					_delay_us(10000);
					SEVENSEG_Disable(0);

					SEVENSEG_Enable(1);
					SEVENSEG_setNumber(counter2);
					_delay_us(50000);
					SEVENSEG_Disable(1);
				}
			}
			Switch_Two_Status=0;
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(Both_Switches_are_preesed==1)
		{
			if(counter1==0)
			{
				counter1=9;
			}
			else
			{
				counter1--;
			}
			if(counter2==0)
			{
				counter2=9;
			}
			else
			{
				counter2--;
			}

			for(i=0;(getSwitchState(0)==0x01)&&(getSwitchState(1)==0x01);i++)
			{
				if(i>20000)
				{
					if(counter1==0)
					{
						counter1=9;
					}
					else
					{
						counter1--;
					}
					if(counter2==0)
					{
						counter2=9;
					}
					else
					{
						counter2--;
					}

					SEVENSEG_Enable(0);
					SEVENSEG_setNumber(counter1);
					_delay_us(50000);
					SEVENSEG_Disable(0);

					SEVENSEG_Enable(1);
					SEVENSEG_setNumber(counter2);
					_delay_us(50000);
					SEVENSEG_Disable(1);
				}
			}
			Both_Switches_are_preesed=0;
		}

		while((getSwitchState(0)==0x01)||(getSwitchState(1)==0x01));
	}
	return 0;
}
