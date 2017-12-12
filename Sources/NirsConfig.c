/*
 * NirsConfig.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Justin Vaio
 */


#include "NirsConfig.h"




bool  ad1MeasurementComplete;
UINT16 ad1Values[AD1_CHANNEL_COUNT];
bool irWaveLength;

extern  UINT16 measuredValue;


#define ADC_RESOLUTION			65535
#define REF_VOLTAGE_mV			3300	//mV

#define _1000mV		(UINT32)(((UINT32)1000*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)	// 19859
#define _500mV		(UINT32)(((UINT32)500*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)	// 9929
#define _100mV		(UINT32)(((UINT32)100*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)	// 1985
#define _50mV		(UINT32)(((UINT32)50*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)	// 992
#define _10mV		(UINT32)(((UINT32)10*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)	// 198
#define _5mV		(UINT32)(((UINT32)5*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)		// 99

#define BASELINE_SETPOINT						(_1000mV+_100mV+_100mV)		// 23829
#define BASELINE_SETPOINT_UPPER_LIMIT_MAX		(BASELINE_SETPOINT +_500mV+_100mV)// 35743
#define BASELINE_SETPOINT_UPPER_LIMIT_MID		(BASELINE_SETPOINT +_100mV+_100mV+_100mV)//29784
#define BASELINE_SETPOINT_UPPER_LIMIT_MIN		(BASELINE_SETPOINT +_100mV)//25814
#define BASELINE_SETPOINT_LOWER_LIMIT_MAX		(BASELINE_SETPOINT -_500mV-_100mV)//11915
#define BASELINE_SETPOINT_LOWER_LIMIT_MID		(BASELINE_SETPOINT -_100mV-_100mV-_100mV)//17874
#define BASELINE_SETPOINT_LOWER_LIMIT_MIN		(BASELINE_SETPOINT -_100mV)//21844


#define GRAPH_OFFSET _1000mV+_100mV+_100mV		// 23829
#define TOLERANCE    _100mV						// 1985

#define PWM_MAX_VALUE	FTM2_MOD


#define PWM_LARGE_STEP	100//_100mV//PWM_MAX_VALUE/10		// 1985
#define PWM_MID_STEP	50//_10mV// PWM_MAX_VALUE/50		// 198
#define PWM_SHORT_STEP	5// _5mV// PWM_MAX_VALUE/100		// 99


static UINT8 configParameter = 0;
UINT16 sampleRate = SAMPLE_RATE_1KHZ;
UINT16 sampleRateArray[10]=
{
	SAMPLE_RATE_1HZ,
	SAMPLE_RATE_2_5HZ,
	SAMPLE_RATE_5HZ,
	SAMPLE_RATE_10HZ,
	SAMPLE_RATE_25HZ,
	SAMPLE_RATE_50HZ,
	SAMPLE_RATE_100HZ,
	SAMPLE_RATE_250HZ,
	SAMPLE_RATE_500HZ,
	SAMPLE_RATE_1KHZ
	
};


UINT32 testDuration[16] = 
{
		SECONDS_30,
		SECONDS_60,
		SECONDS_90,
		SECONDS_120,
		SECONDS_150,
		SECONDS_180,
		SECONDS_210,
		SECONDS_240,
		SECONDS_270,
		SECONDS_300,
		SECONDS_330,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL
};

static volatile UINT16 pwmIrValues[AD1_CHANNEL_COUNT];
static volatile UINT16 pwmRedValues[AD1_CHANNEL_COUNT];



static UINT8 ConfigurationEvent = CONFIGURATION_EVENT_NONE;


/** Task that must be called periodically in tha main loop */
//void Configuration_PeriodicTask(void);


static UINT8 configDataLength = 0;


static UINT16 sensorDisableSelect = 0;		/* Default is No Channels Disabled */

extern UINT32 sampleTime = 1907;		/* Units are in clock ticks at Period = 0.00524288 seconds and
											Frequency = 190.73486328125 
											1907 * Period = 10 Seconds */

void ConfigurationStateIdle(void);
void ConfigurationStateSetup(void);
void ConfigurationStateCalibrating(void);


UINT16 IrCalibration(byte Channel);
UINT16 RedCalibration(byte Channel);
/* Configuration state machine */
const pFunc_t ConfigurationStateMachine[] =
{
	ConfigurationStateIdle,
	ConfigurationStateCalibrating,
	ConfigurationStateSetup
};



void Configuration_PeriodicTask(void)
{
	// State machine handler 
	ConfigurationStateMachine[ConfigurationActualState]();

	// Event handler 
	if (ConfigurationEvent != CONFIGURATION_EVENT_NONE)
	{
		if (Configuration_Events[ConfigurationEvent] != NULL)
		{
			Configuration_Events[ConfigurationEvent]();	//execute registered event
			ConfigurationEvent = CONFIGURATION_EVENT_NONE;
		}
	}
	
}

void ConfigurationStateIdle(void)
{
	// Do Nothing
}



void ConfigurationStateSetup(void)
{
	UINT8 byte = 0;

	if(configDataFlag)
	{
		
		byte++;
		configParameter = configBuffer[byte++];
		configDataFlag = 0;
		
		switch (configParameter)
		{
		case 0:
			//copyActiveSensors = sensorDisableSelect;		// copy to easily see if we changed anything
			sensorDisableSelect = configBuffer[byte++] << 8;
			sensorDisableSelect |= configBuffer[byte++];
			/*	static UINT8 totalSensor = 10;	total number of sensors we start with
			 * for(count = 1;  count < 0x0000010000000000; count = count << 1 )
			 * {
			 * 	 copyActiveSensors = sensorDisableSelect;
			 * 	 totalSensor++;		increase a counter variable so we can easily tell what sensor we are on
			 * 	 if(sensorDisableSelect & count);  // Bitwise test of first bit: if it is one we include channel 1
			 * 	 	else
			 * 	 	{
			 * 	 		totalSensors = totalSensors - 1;
			 * 	 		set the sensor array value array[deleted sensor] = NULL;
			 * 	 	}
			 * 	}
			 * 	
			 * 	loop through the array and swap the array[deleted sensor] NULL with [deleted sensor + 1]
			 * 	do until all NULLs are at the end of the list.
			 * 	
			 * 	then for the rest of the code we can use the 10 byte array but only cycle through totalSensor array values.
			 * 	 		
			 */
			
			
			break;
		case 1:
			
			byte++;
			byte++;
			byte++;
			sampleRate = sampleRateArray[(UINT8)(configBuffer[byte])];
			
			PDB0_ReInit();

			
			break;
			
		case 2:
			
			sampleTime = 0;
			byte++;
			byte++;
			sampleTime = testDuration[(UINT8)(configBuffer[byte])];
			
			break;
			
		}
		
		for (byte = 0; byte <= configDataLength; byte++)
		{
			configBuffer[byte] = 0;
		}
		
		ConfigurationActualState = CONFIGURATION_STATE_IDLE;
	} // end if recieved 
}



void ConfigurationStateCalibrating(void)
{
	byte sensor = 0;	
	byte Channel = 0;
	UINT16 pwmIrSumValue = 0;
	UINT16 pwmRedSumValue = 0;

	AD2_Calibrate(TRUE);
	AD1_Calibrate();
	
	//for(sensor = 0; sensor < AD1_CHANNEL_COUNT; sensor++)
	for(sensor = 0; sensor < 10; sensor++)
	{
		Channel = 0;
		pwmIrValues[sensor] = IrCalibration(Channel);
		pwmRedValues[sensor] = RedCalibration(Channel);	
	}
	

	
	for(sensor = 0; sensor < 10; sensor++)
	{
		pwmIrSumValue += pwmIrValues[sensor];
		pwmRedSumValue += pwmRedValues[sensor];
	}
	
	pwmIrValue = pwmIrSumValue/10;
	pwmRedValue = pwmRedSumValue/10;
	
	
	CalibrationCompleteOkInd();
	ConfigurationActualState = CONFIGURATION_STATE_IDLE;
}

	UINT16 IrCalibration(byte Channel)
	{
		UINT16 pwmIrTempValue= 0;	
		UINT16 measuredValue;
		bool irCalibrationComplete = FALSE;
		
		Led_Select_PutVal(TRUE);
		
		while(!irCalibrationComplete)
		{
			FTM2_CH1_PWM_Stop();
			FTM2_CH1_PWM_Start(pwmIrTempValue);
			
			AD1_MeasureChan(TRUE, Channel);
			AD1_GetChanValue(0, &measuredValue);
			
			
			//if signal is larger than setpoint

			if (measuredValue> BASELINE_SETPOINT_UPPER_LIMIT_MAX)
			{
				if (pwmIrTempValue > PWM_LARGE_STEP)
				{
					//decrease offset by large steps
					pwmIrTempValue -= PWM_LARGE_STEP;			
				}
				else if (pwmIrTempValue > PWM_MID_STEP)
				{
					//decrease offset by medium steps
					pwmIrTempValue -= PWM_MID_STEP;			
				}
				else if (pwmIrTempValue > PWM_SHORT_STEP)
				{
					//decrease offset by small steps
					pwmIrTempValue -= PWM_SHORT_STEP;			
				}
				//else PwmIRValue = PWM_MAX_VALUE;
			}			
			else if (measuredValue > BASELINE_SETPOINT_UPPER_LIMIT_MID)
			{
				//decrease offset by midium steps
				if (pwmIrTempValue > PWM_MID_STEP)
				{
					//decrease offset by large steps
					pwmIrTempValue -= PWM_MID_STEP;			
				}
				else if (pwmIrTempValue > PWM_SHORT_STEP)
				{
					//decrease offset by large steps
					pwmIrTempValue -= PWM_SHORT_STEP;			
				}		
			}
			else if (measuredValue > BASELINE_SETPOINT_UPPER_LIMIT_MIN)
			{
				//decrease offset by short steps		
				if (pwmIrTempValue > PWM_SHORT_STEP)
				{
					//decrease offset by large steps
					pwmIrTempValue -= PWM_SHORT_STEP;			
				}
			}
	
	
			//if signal is lower than setpoint	
			
			else if (measuredValue < BASELINE_SETPOINT_LOWER_LIMIT_MAX)
			{
				//increase offset by large steps
				if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_LARGE_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_LARGE_STEP;
				}
				else if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_MID_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_MID_STEP;
				}
				else if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_SHORT_STEP;
				}
				//else PwmIRValue = 0;
			}
			else if (measuredValue< BASELINE_SETPOINT_LOWER_LIMIT_MID)
			{
				//increase offset by medium steps
				if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_MID_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_MID_STEP;
				}
				else if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_SHORT_STEP;
				}	
			}
			else if (measuredValue < BASELINE_SETPOINT_LOWER_LIMIT_MIN)
			{
				//increase offset by short steps		
				if (pwmIrTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
				{
					//decrease offset by large steps
					pwmIrTempValue += PWM_SHORT_STEP;
				}
			}
			else 
			{
				irCalibrationComplete = TRUE;

			}
		}

		return pwmIrTempValue;
	}

	
	
	
	UINT16 RedCalibration(byte Channel)
	{
			UINT16 pwmRedTempValue = 0;
			UINT16 measuredValue;
			
			bool redCalibrationComplete = FALSE;
			Led_Select_PutVal(FALSE);
			
			while(!redCalibrationComplete)
			{
				FTM2_CH1_PWM_Stop();
				FTM2_CH1_PWM_Start(pwmRedTempValue);
				
				AD1_MeasureChan(TRUE, Channel);
				AD1_GetChanValue(0, &measuredValue);
				//if signal is larger than setpointgi
				if (measuredValue> BASELINE_SETPOINT_UPPER_LIMIT_MAX)
				{
					if (pwmRedTempValue > PWM_LARGE_STEP)
					{
						//decrease offset by large steps
						pwmRedTempValue -= PWM_LARGE_STEP;			
					}
					else if (pwmRedTempValue > PWM_MID_STEP)
					{
						//decrease offset by medium steps
						pwmRedTempValue -= PWM_MID_STEP;			
					}
					else if (pwmRedTempValue > PWM_SHORT_STEP)
					{
						//decrease offset by small steps
						pwmRedTempValue -= PWM_SHORT_STEP;			
					}
					//else PwmIRValue = PWM_MAX_VALUE;
				}			
				else if (measuredValue > BASELINE_SETPOINT_UPPER_LIMIT_MID)
				{
					//decrease offset by midium steps
					if (pwmRedTempValue > PWM_MID_STEP)
					{
						//decrease offset by large steps
						pwmRedTempValue -= PWM_MID_STEP;			
					}
					else if (pwmRedTempValue > PWM_SHORT_STEP)
					{
						//decrease offset by large steps
						pwmRedTempValue -= PWM_SHORT_STEP;			
					}		
				}
				else if (measuredValue > BASELINE_SETPOINT_UPPER_LIMIT_MIN)
				{
					//decrease offset by short steps		
					if (pwmRedTempValue > PWM_SHORT_STEP)
					{
						//decrease offset by large steps
						pwmRedTempValue -= PWM_SHORT_STEP;			
					}
				}
		
		
				//if signal is lower than setpoint	
				
				else if (measuredValue < BASELINE_SETPOINT_LOWER_LIMIT_MAX)
				{
					//increase offset by large steps
					if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_LARGE_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_LARGE_STEP;
					}
					else if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_MID_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_MID_STEP;
					}
					else if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_SHORT_STEP;
					}
					//else PwmIRValue = 0;
				}
				else if (measuredValue< BASELINE_SETPOINT_LOWER_LIMIT_MID)
				{
					//increase offset by medium steps
					if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_MID_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_MID_STEP;
					}
					else if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_SHORT_STEP;
					}	
				}
				else if (measuredValue < BASELINE_SETPOINT_LOWER_LIMIT_MIN)
				{
					//increase offset by short steps		
					if (pwmRedTempValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
					{
						//decrease offset by large steps
						pwmRedTempValue += PWM_SHORT_STEP;
					}
				}
				else 
				{
					redCalibrationComplete = TRUE;
				}
			}
			return pwmRedTempValue;
		}
	
	
	
	
	void PDB0_ReInit(void)
	{
	  /* SIM_SCGC6: PDB=1 */
	  SIM_SCGC6 |= SIM_SCGC6_PDB_MASK;                                   
	  /* PDB0_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,LDMOD=3,PDBEIE=0,SWTRIG=0,DMAEN=0,PRESCALER=5,TRGSEL=0x0F,PDBEN=0,PDBIF=0,PDBIE=1,??=0,MULT=2,CONT=1,LDOK=0 */
	  PDB0_SC = PDB_SC_LDMOD(0x00) |
	            PDB_SC_PRESCALER(0x05) |
	            PDB_SC_TRGSEL(0x0F) |
	            PDB_SC_PDBIE_MASK |
	            PDB_SC_MULT(0x02) |
	            PDB_SC_CONT_MASK;       
	  /* PDB0_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0x25 */
	  PDB0_MOD = PDB_MOD_MOD(sampleRate);                                   
	  /* PDB0_IDLY: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,IDLY=0 */
	  PDB0_IDLY = PDB_IDLY_IDLY(0x00);                                   
	  /* PDB0_CH0C1: BB&=~3,TOS&=~3,EN&=~3 */
	  PDB0_CH0C1 &= (uint32_t)~(uint32_t)(
	                 PDB_C1_BB(0x03) |
	                 PDB_C1_TOS(0x03) |
	                 PDB_C1_EN(0x03)
	                );                                   
	  /* PDB0_CH0S: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CF=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ERR=0xFF */
	  PDB0_CH0S = (PDB_S_CF(0x00) | PDB_S_ERR(0xFF));                                   
	  /* PDB0_CH0DLY0: DLY=0 */
	  PDB0_CH0DLY0 &= (uint32_t)~(uint32_t)(PDB_DLY_DLY(0xFFFF));                                   
	  /* PDB0_CH0DLY1: DLY=0 */
	  PDB0_CH0DLY1 &= (uint32_t)~(uint32_t)(PDB_DLY_DLY(0xFFFF));                                   
	  /* PDB0_CH1C1: BB&=~3,TOS&=~2,TOS|=1,EN&=~2,EN|=1 */
	  PDB0_CH1C1 = (uint32_t)((PDB0_CH1C1 & (uint32_t)~(uint32_t)(
	                PDB_C1_BB(0x03) |
	                PDB_C1_TOS(0x02) |
	                PDB_C1_EN(0x02)
	               )) | (uint32_t)(
	                PDB_C1_TOS(0x01) |
	                PDB_C1_EN(0x01)
	               ));                                  
	  /* PDB0_CH1S: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CF=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ERR=0xFF */
	  PDB0_CH1S = (PDB_S_CF(0x00) | PDB_S_ERR(0xFF));                                   
	  /* PDB0_CH1DLY0: DLY=0 */
	  PDB0_CH1DLY0 &= (uint32_t)~(uint32_t)(PDB_DLY_DLY(0xFFFF));                                   
	  /* PDB0_CH1DLY1: DLY=0 */
	  PDB0_CH1DLY1 &= (uint32_t)~(uint32_t)(PDB_DLY_DLY(0xFFFF));                                   
	  /* PDB0_DACINT0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INT=0 */
	  PDB0_DACINT0 = PDB_INT_INT(0x00);                                   
	  /* PDB0_DACINT1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INT=0 */
	  PDB0_DACINT1 = PDB_INT_INT(0x00);                                   
	  /* PDB0_DACINTC0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,EXT=0,TOE=0 */
	  PDB0_DACINTC0 = 0x00U;                                   
	  /* PDB0_DACINTC1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,EXT=0,TOE=0 */
	  PDB0_DACINTC1 = 0x00U;                                   
	  /* PDB0_PO0DLY: DLY1=0,DLY2=0 */
	  PDB0_PO0DLY = (PDB_PODLY_DLY1(0x00) | PDB_PODLY_DLY2(0x00));                                   
	  /* PDB0_POEN: POEN&=~1 */
	  PDB0_POEN &= (uint32_t)~(uint32_t)(PDB_POEN_POEN(0x01));                                   
	  /* PDB0_SC: PDBEN=1,LDOK=1 */
	  PDB0_SC |= (PDB_SC_PDBEN_MASK | PDB_SC_LDOK_MASK);                                   
	}
