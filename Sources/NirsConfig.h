
/*
 * NirsConfig.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Justin Vaio
 */

#ifndef NIRSCONFIG_H_
#define NIRSCONFIG_H_



#include "Main_App.h"
#include "PublicTypes.h"
#include "Types.h"
#include "Timers.h"
#include "PDB_PDD.h"
extern UINT16 pwmRedValue;
extern UINT16 pwmIrValue;
extern UINT8 ConfigurationActualState;
static UINT8 ConfigurationEvent;


#define SECONDS_30	5722
#define SECONDS_60  11444
#define SECONDS_90	17166
#define SECONDS_120 22888
#define SECONDS_150 28610
#define SECONDS_180 34332
#define SECONDS_210 40054
#define SECONDS_240 45776
#define SECONDS_270 51498
#define SECONDS_300	57220
#define SECONDS_330 63942


									/*	SET UP HAS PDB0 MULT = X20 AND PRESCALER = 32		*/	
#define SAMPLE_RATE_1KHZ	37     // Is actually 493.3uS but is the closest possible value
#define SAMPLE_RATE_500HZ	75	
#define SAMPLE_RATE_250HZ	150	
#define SAMPLE_RATE_100HZ	375		
#define SAMPLE_RATE_50HZ	750	
#define SAMPLE_RATE_25HZ	1500		
#define SAMPLE_RATE_10HZ	3750		
#define SAMPLE_RATE_5HZ		7500		
#define SAMPLE_RATE_2_5HZ	15000		
#define SAMPLE_RATE_1HZ		37500		


extern UINT8 configDataFlag;
extern UINT8 configBuffer[32];
/** Array of pointers to functions to execute Measurement events */
extern const pFunc_t Configuration_Events[];	

void Configuration_PeriodicTask(void);

void CalibrationCompleteOkInd(void);

void PDB0_ReInit(void);


UINT16 IrCalibration(byte Channel);

UINT16 RedCalibration(byte Channel);
/** These are the possible events that the Measurement can generate */
typedef enum
{
	CONFIGURATION_EVENT_NONE,
	CONFIGURATION_EVENT_CALIBRATION_COMPLETE_OK,
	MEASUREMENT_EVENT_CALIBRATION_ERROR,
	MEASUREMENT_EVENT_CALIBRATION_DATA_READY,
} Calibration_Event_e;


/** Main Measurement state machine states */
typedef enum
{
	CONFIGURATION_STATE_IDLE,
	CONFIGURATION_STATE_CALIBRATING,
	CONFIGURATION_STATE_SETUP
} CalibrationStates_e;




#endif /* NIRSCONFIG_H_ */
