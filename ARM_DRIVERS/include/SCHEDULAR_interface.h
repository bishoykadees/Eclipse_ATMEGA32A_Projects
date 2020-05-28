#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef void (*TaskRunnable_t)(void);

typedef struct
{
	TaskRunnable_t Runnable;
	u32            PeriodicTimeMS;
}TaskInterface_t;

extern ErrorStatus SCHEDULAR_Init(void);
extern ErrorStatus SCHEDULAR_Start(void);

#endif
