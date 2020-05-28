/*
 * SHEDULAR_config.c
 *
 *  Created on: Mar 28, 2020
 *      Author: Bishoy Nabil
 */

#define MAX                                                100

#include "SCHEDULAR_interface.h"

typedef struct
{
	const TaskInterface_t *const AppTask;
	      u32                    FirstDelayTicks;
}TaskInfo_t;

/* Structures of type TaskInterface_t created by users */
extern TaskInterface_t HLED_Task;
//extern TaskInterface_t AppTask_02;
//extern TaskInterface_t AppTask_03;
//extern TaskInterface_t AppTask_04;
//extern TaskInterface_t AppTask_05;

extern const TaskInfo_t TasksInfo[MAX] = {
		{&HLED_Task,0}
};






