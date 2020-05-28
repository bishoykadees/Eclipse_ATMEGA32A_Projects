
/*****************************************************************************/
/* Author : Hammam mazen */
/* Date : 4 Feb 2020     */
/* Version : v01         */
/* Component : EXTI      */
/* Layer : MCAL          */
/*****************************************************************************/


#ifndef EXTI_REG_H_
#define EXTI_REG_H_


#define MCUCR               *((volatile u8*)0x55)
#define MCUCR_ISC00         0                        /*INT0 Sense control bit0*/
#define MCUCR_ISC01         1                        /*INT0 Sense control bit1*/
#define MCUCR_ISC10         2                        /*INT1 Sense control bit0*/
#define MCUCR_ISC11         3                        /*INT1 Sense control bit1*/


#define MCUCSR              *((volatile u8*)0x54)
#define MCUCSR_ISC2         6                        /*INT2 Sense control bit */

#define GICR                *((volatile u8*)0x5B)
#define GICR_INT1           7                        /*    INT1 Enable bit    */
#define GICR_INT0           6                        /*    INT0 Enable bit    */
#define GICR_INT2           5                        /*    INT2 Enable bit    */

#define GIFR                *((volatile u8*)0x5A)


#define SREG                *((volatile u8*)0x5F)

#endif