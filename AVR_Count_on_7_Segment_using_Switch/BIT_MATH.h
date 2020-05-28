#define SET_BIT(VAR,BIT_NO) (VAR|=(1 <<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR &= ~ (1 <<BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR^= (1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)
#define RIGHT_CIRCULAR_SHIFT(VAR,SHIFT_VALUE) (VAR = (VAR >> SHIFT_VALUE ) | (VAR << ((sizeof(VAR)*8)-SHIFT_VALUE)))
#define LEFT_CIRCULAR_SHIFT(VAR,SHIFT_VALUE) (VAR = (VAR << SHIFT_VALUE ) | (VAR >> ((sizeof(VAR)*8)-SHIFT_VALUE)))
