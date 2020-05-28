/*****************************************************************************/
/* Author : Hammam mazen */
/* Date : 4 Feb 2020     */
/* Version : v01         */
/* Component : EXTI      */
/* Layer : MCAL          */
/*****************************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8_INT0                0
#define EXTI_u8_INT1                1
#define EXTI_u8_INT2                2

#define EXTI_u8_LOW_LEVEL           0
#define EXTI_u8_ON_CHANGE           1
#define EXTI_u8_FALLING_EDGE        2
#define EXTI_u8_RISING_EDGE         3


/* Description : Function used to initialize the external Interrupt INT0,INT1,INT2 According
 *  to the Precompiled Configuration
 * Inputs  : void
 * Outputs : void
 */
void EXTI_voidInit(void);

/* Description : Function used to enable the peripheral enable of external Interrupt INT0,INT1,INT2 
 *
 * Inputs  : Interrupt index , Ranges are :
			1- EXTI_u8_INT0
			2- EXTI_u8_INT1
			3- EXTI_u8_INT2
			
 * Outputs : Error Status
 */
ErrorStatus EXTI_errEnable(u8 Copy_u8IntIdx);

/* Description : Function used to Disable the peripheral enable of xternal Interrupt INT0,INT1,INT2
 *
 * Inputs  : Interrupt index , Ranges are :
			1- EXTI_u8_INT0
			2- EXTI_u8_INT1
			3- EXTI_u8_INT2
			
 * Outputs : Error Status
 */
ErrorStatus EXTI_errDisable(u8 Copy_u8IntIdx);

/* Description : Function used to set the required sense llevel of INT0,INT1,INT2 
 *
 * Inputs  :
		1-Interrupt index , Ranges are :
			1- EXTI_u8_INT0
			2- EXTI_u8_INT1
			3- EXTI_u8_INT2
		2- sense level :
			1- EXTI_u8_LOW_LEVEL   
			2- EXTI_u8_ON_CHANGE   
			3- EXTI_u8_FALLING EDGE
			4- EXTI_u8_RISING_EDGE 
			
 * Outputs : Error Status
 */

ErrorStatus EXTI_errSetSense(u8 Copy_u8IntIdx, u8 Copy_u8SenseLevel);


/* Description : Function used to set the call back function of INT0,INT1,INT2 According
 *  to the Precompiled Configuration
 * Inputs  :
		1-Interrupt index , Ranges are :
			1- EXTI_u8_INT0
			2- EXTI_u8_INT1
			3- EXTI_u8_INT2
		2- callback function to the required address of application ISR Function
		
 * Outputs : Error Status
 */
ErrorStatus EXTI_errSetCallBack(u8 Copy_u8Idx, void (*Copy_pvCallBack)(void));



#endif
