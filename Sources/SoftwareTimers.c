/*
 * SoftwareTimers.c
 *
 *  Created on: Dec 3, 2013
 *      Author: Justin Vaio
 */

 /**
 \file
 \brief 	This file handles an array of software timers and trigger the timer event when
 		the timer has elapsed.
 		It uses only one hardware timer (TPM module) from the MCU.
 \author Samuel Quiroz
 \date 2009-09-11
 */

 #include "SoftwareTimers.h"

 #define INACTIVE_TIMER          0xFFFF		/**< Thism number is used to tell that the timer is inactive */
 #define INVALID_TIMER_ID		0xFF		/**< This Id is returned when the timer was not created */


 SwCounter_t  SwCounterObjArray[MAX_COUNTER_OBJECTS];	/**< Stores the counter objects */
 SwTimerObj_t SwTimerObjArray[MAX_TIMER_OBJECTS];		/**< Stores the timer objects */
 UINT8 AssignedTimersIndex = 0;		/**< Will count the timers that are created on the application */
 UINT8 AssignedCountersIndex = 0;	/**< Will count the counters that are created on the application */


 void SwTimer_Init(void)
 {
 	UINT8 i;
 	for (i=0; i<MAX_TIMER_OBJECTS; i++)
 	{
 		SwTimerObjArray[i].timerCount = INACTIVE_TIMER;	/* Set all timers inactive */
 	}	
 	
 	for (i=0; i<MAX_COUNTER_OBJECTS; i++)
 	{
 		SwCounterObjArray[i].timerCount = INACTIVE_TIMER;	/* Set all timers inactive */
 	}
 	
 	AssignedTimersIndex = 0;
 	AssignedCountersIndex = 0;



         FTM0_Init();



 }


 void SwTimer_PeriodicTask(void)
 {
 	UINT8 i;
 	UINT8 decrementValue = HW_TIMER_DECREMENT_VALUE;		//this variable is created to avoid data-race with the TPM or RTC Isr

 	if (decrementValue>0)
 	{

 		for (i=0; i<AssignedTimersIndex; i++)
 		{
 			if (SwTimerObjArray[i].timerCount != INACTIVE_TIMER)	/* only decrement active timers */
 			{				
 				if(SwTimerObjArray[i].timerCount >= decrementValue)
 				{
 					SwTimerObjArray[i].timerCount -= decrementValue;
 				}
 				else
 				{
 					SwTimerObjArray[i].timerCount = 0;
 				}				
 				
 				if(SwTimerObjArray[i].timerCount == 0)	/* if timer has elapsed */
 				{
 					SwTimerObjArray[i].timerCount = INACTIVE_TIMER;	/* disable timer */
 					
 					if (SwTimerObjArray[i].timerEvent != NULL)
 					{
 						SwTimerObjArray[i].timerEvent();		/* execute timer callback function */	
 					}					
 				}
 			}
 		}

 		
 		for (i=0; i<AssignedCountersIndex; i++)
 		{
 			if (SwCounterObjArray[i].timerCount != INACTIVE_TIMER)
 			{
 				SwCounterObjArray[i].timerCount += decrementValue;
 			}
 		}
 		
 		HW_TIMER_DECREMENT_VALUE = 0;
 	}	
 }




 UINT8 SwTimer_CreateTimer(pFunc_t callBackFunc)
 {
 	UINT8 timerId;
 	
 	if (AssignedTimersIndex < MAX_TIMER_OBJECTS)
 	{
 		SwTimerObjArray[AssignedTimersIndex].timerEvent = callBackFunc;	
 		timerId = AssignedTimersIndex++;
 	}
 	else
 	{
 		timerId = INVALID_TIMER_ID;
 	}
 	
 	return timerId;
 }


 void SwTimer_StartTimer(UINT8 timerId, UINT16 tickPeriod_ms)
 {
 	SwTimerObjArray[timerId].timerCount = tickPeriod_ms;
 }


 void SwTimer_StopTimer(UINT8 timerId)
 {
 	SwTimerObjArray[timerId].timerCount = INACTIVE_TIMER;
 }



 UINT8 SwTimer_CreateCounter(void)
 {
 	UINT8 counterId;
 	
 	if (AssignedCountersIndex < MAX_COUNTER_OBJECTS)
 	{
 		counterId = AssignedCountersIndex++;
 	}
 	else
 	{
 		counterId = INVALID_TIMER_ID;
 	}
 	
 	return counterId;
 }


 void SwTimer_StartCounter(UINT8 counterId)
 {
 	SwCounterObjArray[counterId].timerCount = 0;
 }

 void SwTimer_StopCounter(UINT8 counterId)
 {
 	SwCounterObjArray[counterId].timerCount = INACTIVE_TIMER;
 }

 UINT16 SwTimer_ReadCounter(UINT8 counterId)
 {
 	return (SwCounterObjArray[counterId].timerCount);
 }


