/*****************************************************************************/
/* Author : Hammam mazen */
/* Date : 4 Feb 2020     */
/* Version : v01         */
/* Component : EXTI      */
/* Layer : MCAL          */
/*****************************************************************************/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
 * optIions : 1- ENABLED
 *           2- DISABLED
 */
 
#define EXTI_u8_INT0_CONTROL    DISABLED


/*
 * optIions : 1- ENABLED
 *           2- DISABLED
 */
 
 #define EXTI_u8_INT1_CONTROL    DISABLED
 
 /*
 * optIions : 1- ENABLED
 *           2- DISABLED
 */
 
 #define EXTI_u8_INT2_CONTROL    DISABLED
 
 /*
 * optIions : 1- LOW_LEVEL
 *            2- ON_CHANGE
              3- FALLING_EDGE
              4-RISING_EDGE
 */
 
 #define EXTI_u8_INT0_SENSE      FALLING_EDGE
 
 /*
 * optIions : 1- LOW_LEVEL
 *            2- ON_CHANGE
              3- FALLING_EDGE
              4-RISING_EDGE
 */
 
 #define EXTI_u8_INT1_SENSE      FALLING_EDGE
 
 /*
 * optIions : 1- LOW_LEVEL
 *            2- ON_CHANGE
              3- FALLING_EDGE
              4-RISING_EDGE
 */
 
 #define EXTI_u8_INT2_SENSE      FALLING_EDGE

#endif
