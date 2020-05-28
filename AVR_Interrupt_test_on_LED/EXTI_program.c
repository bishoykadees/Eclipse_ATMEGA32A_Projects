/*****************************************************************************/
/* Author : Hammam mazen */
/* Date : 4 Feb 2020     */
/* Version : v01         */
/* Component : EXTI      */
/* Layer : MCAL          */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_reg.h"

/*Global array of 3x pointers to function to hold the call back address function*/
static void (*EXTI_pvCallBack[3])(void)={NULL,NULL,NULL};

/*precompile function to init INTS*/

void EXTI_voidInit(void)
{
	#if EXTI_u8_INT0_CONTROL == ENABLED
		SET_BIT(GICR,GICR_INT0);
	#elif EXTI_u8_INT0_CONTROL == DISABLED
		CLR_BIT(GICR,GICR_INT0);
	#else
		#error "Wrong EXTI_u8_INT0_CONTROL Configuration"
	#endif
	
	#if EXTI_u8_INT1_CONTROL == ENABLED
		SET_BIT(GICR,GICR_INT1);
	#elif EXTI_u8_INT1_CONTROL == DISABLED
		CLR_BIT(GICR,GICR_INT1);
	#else
		#error "Wrong EXTI_u8_INT1_CONTROL Configuration"
	#endif
	
	#if EXTI_u8_INT2_CONTROL == ENABLED
		SET_BIT(GICR,GICR_INT2);
	#elif EXTI_u8_INT2_CONTROL == DISABLED
		CLR_BIT(GICR,GICR_INT2);
	#else
		#error "Wrong EXTI_u8_INT2_CONTROL Configuration"
	#endif
	
	#if EXTI_u8_INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#else 
		#error "Wrong EXTI_u8_INT0_SENSE Configuration"
	#endif
	
	
	#if EXTI_u8_INT1_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	#else 
		#error "Wrong EXTI_u8_INT1_SENSE Configuration"
	#endif
	
	
	#if EXTI_u8_INT1_SENSE == FALLING_EDGE
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#elif EXTI_u8_INT1_SENSE == RISING_EDGE
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	#else 
		#error "Wrong EXTI_u8_INT2_SENSE Configuration"
	#endif
	
}
/*Post Compile Function To enable Any INT in runtime*/
ErrorStatus EXTI_errEnable(u8 Copy_u8IntIdx)
{
	ErrorStatus LocalError = OK;
	switch(Copy_u8IntIdx)
	{
		case EXTI_u8_INT0 : SET_BIT(GICR,GICR_INT0);  break;
		case EXTI_u8_INT1 : SET_BIT(GICR,GICR_INT1);  break;
		case EXTI_u8_INT2 : SET_BIT(GICR,GICR_INT2);  break;
		default : LocalError = NOK;                   break;
	}
	return LocalError;
}

/*Post Compile Function To disable Any INT in runtime*/
ErrorStatus EXTI_errDisable(u8 Copy_u8IntIdx)
{
	ErrorStatus LocalError = OK;
	switch(Copy_u8IntIdx)
	{
		case EXTI_u8_INT0 : CLR_BIT(GICR,GICR_INT0);  break;
		case EXTI_u8_INT1 : CLR_BIT(GICR,GICR_INT1);  break;
		case EXTI_u8_INT2 : CLR_BIT(GICR,GICR_INT2);  break;
		default : LocalError = NOK;                   break;
	}
	return LocalError;
}
ErrorStatus EXTI_errSetSense(u8 Copy_u8IntIdx, u8 Copy_u8SenseLevel)
{
	ErrorStatus LocalError = OK;
	
	switch(Copy_u8IntIdx)
	{
		case EXTI_u8_INT0:
			if(Copy_u8SenseLevel == EXTI_u8_LOW_LEVEL)
			{
				CLR_BIT(MCUCR,MCUCR_ISC00);
				CLR_BIT(MCUCR,MCUCR_ISC01);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_ON_CHANGE)
			{
				SET_BIT(MCUCR,MCUCR_ISC00);
				CLR_BIT(MCUCR,MCUCR_ISC01);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_FALLING_EDGE)
			{
				CLR_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_RISING_EDGE)
			{
				SET_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
			}
			else
			{
				LocalError =NOK;
			}
			break;
			
			
		case EXTI_u8_INT1:
			if(Copy_u8SenseLevel == EXTI_u8_LOW_LEVEL)
			{
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_ON_CHANGE)
			{
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_FALLING_EDGE)
			{
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_RISING_EDGE)
			{
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
			}
			else
			{
				LocalError =NOK;
			}
			break;
		
		
		case EXTI_u8_INT2:
			
			if(Copy_u8SenseLevel == EXTI_u8_FALLING_EDGE)
			{
				CLR_BIT(MCUCR,MCUCSR_ISC2);
			}
			else if(Copy_u8SenseLevel == EXTI_u8_RISING_EDGE)
			{
				SET_BIT(MCUCR,MCUCSR_ISC2);
			}
			else
			{
				LocalError =NOK;
			}
			break;
			
		default : LocalError = NOK;
	}
	return LocalError;
}

ErrorStatus EXTI_errSetCallBack(u8 Copy_u8Idx, void (*Copy_pvCallBack)(void))
{
	ErrorStatus LocalError =OK;
	
	if(Copy_pvCallBack != NULL)
	{
		if(Copy_u8Idx <3)
		{
			EXTI_pvCallBack[Copy_u8Idx]= Copy_pvCallBack;
		}
		else
		{
			LocalError = NOK;
		}
		
	}
	else
	{
		LocalError = NULLPOINTER ;
	}
	
	return LocalError;
}

/*ISR Of INT0*/
void __vector_1 (void)
{
	if(EXTI_pvCallBack[0] != NULL)
	{
		EXTI_pvCallBack[0]();
	}
}

/*ISR Of INT1*/
void __vector_2 (void)
{
	if(EXTI_pvCallBack[1] != NULL)
	{
		EXTI_pvCallBack[1]();
	}
}

/*ISR Of INT2*/
void __vector_3 (void)
{
	if(EXTI_pvCallBack[2] != NULL)
	{
		EXTI_pvCallBack[2]();
	}
}



