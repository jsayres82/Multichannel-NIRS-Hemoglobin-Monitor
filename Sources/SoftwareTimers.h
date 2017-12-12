/*
 * SoftwareTimers.h
 *
 *  Created on: Dec 3, 2013
 *      Author: Justin Vaio
 */

#ifndef SOFTWARETIMERS_H_
#define SOFTWARETIMERS_H_

/**
\file
\brief 	This file handles an array of software timers and trigger the timer event when
		the timer has elapsed.
		It also handles Counters to allow the user to start counting time periods.
		It uses only one hardware timer (TPM module or RTC) from the MCU.
\author Samuel Quiroz
\date 2009-04-03
*/

#ifndef __SWTIMER
#define __SWTIMER



#include "derivative.h"
#include "PublicTypes.h"
#include "Timers.h"
        



#define HW_TIMER_DECREMENT_VALUE        FTM_DecrementValue 
#define MAX_TIMER_OBJECTS		20			/**< This is the max number of timers that the application will have */
#define MAX_COUNTER_OBJECTS		3


typedef struct
{
	UINT16 timerCount;
	pFunc_t timerEvent;
} SwTimerObj_t;


typedef struct
{
	UINT16 timerCount;
} SwCounter_t;

typedef byte SwTimerId_t;

/** Initializes SwTimer module. Disables all timers. */
void SwTimer_Init(void);

/** This function must be called periodically in the main loop */
void SwTimer_PeriodicTask(void);

/** Starts a timer with a given period 
	\param timerId Number of the timer to start
	\param tickPeriod_ms Timer period in ms
*/
void SwTimer_StartTimer(UINT8 timerId, UINT16 tickPeriod_ms);

/** Stops a timer 
	\param timerId Number of the timer to stop
*/
void SwTimer_StopTimer(UINT8 timerId);

/**
	Creates a timer and assigns it call-back function.
	\param callBackFunc Function to be executed when timer has elapsed
	\return timerId The ID of the timer that was created. It returns INVALID_TIMER_ID (0xFF)
	if the timer was not created (because MAX_TIMER_OBJECTS was reached)
*/
UINT8 SwTimer_CreateTimer(pFunc_t callBackFunc);

/**
	Creates a counter.
	\return The counter ID. This ID will be used to start, stop and read the counter.
			Returns INVALID_TIMER_ID (0xFF= if the counter was not created due to 
			memory limitations (because MAX_TIMER_OBJECTS was reached)
*/
UINT8 SwTimer_CreateCounter(void);

/**
	Starts a counter.
	\param counterId Id of the counter to start.
*/
void SwTimer_StartCounter(UINT8 counterId);

/**
	Stops a counter.
	\param counterId Id of the counter to stop.
*/
void SwTimer_StopCounter(UINT8 counterId);


/**
	Reads a counter.
	\param counterId Id of the counter to read.
*/
UINT16 SwTimer_ReadCounter(UINT8 counterId);

#endif      //SWTIMER


#endif /* SOFTWARETIMERS_H_ */
