/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v01                   *
*Date: 26/02/2020               *
*********************************/
#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADMUX *((volatile u8*) 0x27) 
#define ADCSRA *((volatile u8*) 0x26) 
#define ADCH *((volatile u8*) 0x25) 
#define ADCL *((volatile u8*) 0x24) 
#define SFIOR *((volatile u8*) 0x50) 

#endif
