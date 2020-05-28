/* Libraries First */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* My files*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

void setPinDirection(u8 Port, u8 Pin, u8 Dir)
{
  
  switch (Port)
  {
    case 'A':
              if (Dir == 0)
              {
                //DDRA = DDRA & ~ (1 <<Pin);
                CLR_BIT(DDRA,Pin);
              }
              else
              {
                //DDRA = DDRA | (1 <<Pin);
                SET_BIT(DDRA,Pin);
              }
              break;
              
    case 'B':
              if (Dir == 0)
              {
                //DDRB = DDRB & ~ (1 <<Pin);
                CLR_BIT(DDRB,Pin);
              }
              else
              {
                //DDRB = DDRB | (1 <<Pin);
                SET_BIT(DDRB,Pin);
              }
              break;  
    case 'C':
              if (Dir == 0)
              {
                //DDRC = DDRC & ~ (1 <<Pin);
                CLR_BIT(DDRC,Pin);
              }
              else
              {
                //DDRC = DDRC | (1 <<Pin);
                SET_BIT(DDRC,Pin);
              }
              break;
    case 'D':
              if (Dir == 0)
              {
                //DDRD = DDRD & ~ (1 <<Pin);
                CLR_BIT(DDRD,Pin);
              }
              else
              {
                //DDRD = DDRD | (1 <<Pin);
                SET_BIT(DDRD,Pin);
              }
  }
}


void setPinValue(u8 Port, u8 Pin, u8 Val)
{
  switch (Port)
  {
    case 'A':
              if (Val == 0)
              {
                CLR_BIT(PORTA,Pin);
              }
              else
              {
                SET_BIT(PORTA,Pin);
              }
              break;
              
    case 'B':
              if (Val == 0)
              {
                CLR_BIT(PORTB,Pin);
              }
              else
              {
                SET_BIT(PORTB,Pin);
              }
              break;  
    case 'C':
              if (Val == 0)
              {
                CLR_BIT(PORTC,Pin);
              }
              else
              {
                SET_BIT(PORTC,Pin);
              }
              break;
    case 'D':
              if (Val == 0)
              {
                CLR_BIT(PORTD,Pin);
              }
              else
              {
                SET_BIT(PORTD,Pin);
              }
  }
  
}



u8 getPinValue(u8 Port, u8 Pin)
{
  u8 result;
  switch (Port)
  {
    case 'A':
              result = GET_BIT(PINA,Pin);
              break;
              
    case 'B':
              result = GET_BIT(PINB,Pin);
              break;  
    case 'C':
              result = GET_BIT(PINC,Pin);
              break;
    case 'D':
              result = GET_BIT(PIND,Pin);
  }
  return result;
}