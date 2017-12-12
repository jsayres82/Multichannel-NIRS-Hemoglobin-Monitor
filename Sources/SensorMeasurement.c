/*
 * SensorMeasurement.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Justin Vaio
 */

#include "SensorMeasurement.h"


UINT8  ad2MeasurementComplete;
UINT16 ad2Values[AD2_CHANNEL_COUNT];
UINT8 testComplete;
UINT16 pwmRedValue = 1195;
UINT16 pwmIrValue = 1195;



LDD_TDeviceData* timerData;
bool irWaveLength;

/** Array of pointers to functions to execute Measurement events */
static const pFunc_t Measurement_Events[];


UINT8 measurementResults[];
static UINT8 bufferPtr = 0;

UINT16 *timerHandle;
                               

/* Private functions */

//states
static void MeasurementStateIdle(void);
static void MeasurementStateMeasuring(void);


void FTM0_Init (void);
void FTM0_ISR (void);
void FTM0_Deinit(void);


/* Measurement state machine */
const pFunc_t MeasurementStateMachine[] =
{
	MeasurementStateIdle,
	MeasurementStateMeasuring
};



void Measurement_PeriodicTask(void)
{
	// State machine handler 
	MeasurementStateMachine[MeasurementActualState]();

	// Event handler 
	if (MeasurementActualEvent != MEASUREMENT_EVENT_NONE)
	{
		if (Measurement_Events[MeasurementActualEvent] != NULL)
		{
			Measurement_Events[MeasurementActualEvent]();	//execute registered event
			MeasurementActualEvent = MEASUREMENT_EVENT_NONE;
		}
	}
	
}






/******************************************************************************
*                                 State Idle
******************************************************************************/

static void MeasurementStateIdle(void)
{
	//do nothing
}






/******************************************************************************
*                              State Measuring
******************************************************************************/

static void MeasurementStateMeasuring(void)
{
	int counter;
	static int sampleCount = 0;
	
	if(!testComplete)
	{
		if(ad2MeasurementComplete)
		{
			sampleCount++;
			for(counter = 0; counter < 10; counter++)
			{
				//ad2Values[counter] = ad2Values[counter] - 23829;
				measurementResults[bufferPtr++] = (UINT8)(ad2Values[counter] >> 8);//(0xFF00 & ad2Values[counter])>>8;
				measurementResults[bufferPtr++] = (UINT8)((ad2Values[counter] & 0x00FF));//(0x00FF & ad2Values[counter]);	
			}
			if(sampleCount == 3 )
			{
				bufferPtr = 0;
				sampleCount = 0;
				MeasurementActualEvent = MEASUREMENT_EVENT_NEW_DATA_READY;			
			}
				
			ad2MeasurementComplete = 0;
		}
	}
	else
	{
		testComplete = 0;
		Measurement_AbortMeasurement();
		MeasurementActualEvent = MEASUREMENT_EVENT_MEASUREMENT_COMPLETE_OK;
	}
		
}







UINT8 Measurement_StartMeasurement(void)
{

	UINT8 status = FALSE;

	if (MeasurementActualState == MEASUREMENT_STATE_IDLE)
	{
		
		 // DO INITIALIZATION AND CALIBRATION 

		// Set Measurement State Machine to Measuring State 
		MeasurementActualState = MEASUREMENT_STATE_MEASURING;
		
		// TO DO:  Clean Arrays and relative registers 

		Led_Select_SetVal();
		
		
		FTM2_CH1_PWM_Start(pwmIrValue);
		
		PDB0_SC |= PDB_SC_SWTRIG_MASK;  
		FTM0_Init();


		status = TRUE;			
	}
	else
	{
		status = FALSE;
	}

	return status;	
}



void Measurement_AbortMeasurement(void)
{
	/* Turn off ADC's and PWM's */	
	FTM2_CH1_PWM_Stop();
	Led_Select_SetVal();
	irWaveLength = FALSE;
	MeasurementActualState = MEASUREMENT_STATE_IDLE;
	FTM0_Deinit();


	
}




void PDB0_ISR(void)
{
	PDB0_SC &= (~PDB_SC_PDBIF_MASK);
	

	AD2_Start();
}
