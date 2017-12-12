/*
 * SensorMeasurement.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Justin Vaio
 */

#ifndef SENSORMEASUREMENT_H_
#define SENSORMEASUREMENT_H_


#include "Main_App.h"
#include "PublicTypes.h"
//#include "AD2.h"
#include "Timers.h"
#include "Events.h"
#include "NirsConfig.h"
#include "PDB_PDD.h"




#define BUFFER_SIZE 60		// gives us 3 measurement for 10 channels

extern UINT8 measurementResults[BUFFER_SIZE];
extern UINT8 MeasurementActualState;

extern UINT16 ad2Values[AD2_CHANNEL_COUNT];
extern UINT8  testComplete;


extern UINT8 MeasurementActualEvent;

/** Task that must be called periodically in tha main loop */
void  Measurement_PeriodicTask(void);

/** Starts a Measurement measurement 
	\returns TRUE if success, FALSE if already running */
UINT8 Measurement_StartMeasurement(void);

/** Stops a Measurement measurement */
void  Measurement_AbortMeasurement(void);




extern UINT8 MeasurementGraph[];


/** These are the possible events that the Measurement can generate */
typedef enum
{
	MEASUREMENT_EVENT_NONE,
	MEASUREMENT_EVENT_MEASUREMENT_COMPLETE_OK,
	MEASUREMENT_EVENT_MEASUREMENT_ERROR,
	MEASUREMENT_EVENT_NEW_DATA_READY,
} Measurement_Events_e;


/** Main Measurement state machine states */
typedef enum
{
	MEASUREMENT_STATE_IDLE,
	MEASUREMENT_STATE_MEASURING	
} MeasurementStates_e;


#endif /* SENSORMEASUREMENT_H_ */
