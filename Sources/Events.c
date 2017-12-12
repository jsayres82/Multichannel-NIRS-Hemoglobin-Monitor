/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-11-01, 22:15, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "PublicTypes.h"
#include "SensorMeasurement.h"
#include "NirsConfig.h"

UINT16 ad1Values[AD1_CHANNEL_COUNT];
UINT16 ad2Values[AD2_CHANNEL_COUNT];
extern volatile  bool  ad2MeasurementComplete;
extern volatile  bool  ad1MeasurementComplete;
UINT8  testComplete;
extern volatile bool irWaveLength;
UINT16 measuredValue;



byte AD2_GetValue(void* Values);

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK53N512LQ100]
*/
/*!PDBinterrupt
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}


/*
** ===================================================================
**     Event       :  AD2_OnEnd (module Events)
**
**     Component   :  AD2 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD2_OnEnd(void)
{
  /* Write your code here ... */
	FTM2_CH1_PWM_Stop();
	
	AD2_GetValue(&ad2Values[0]);		/* Get the measured values */
		
		if(irWaveLength)
		{
			Led_Select_PutVal(TRUE);				// Just Measured IR so switch to Red LED  
			//TO DO:  Set appropriate IR LED intensity
			// PWM1_SetRatio16(Ratio)		Ratio is a 16 bit number representing Duty Cycle
			FTM2_CH1_PWM_Start(pwmIrValue);
			
		}
		else
		{
			Led_Select_PutVal(FALSE);		//Just Measured Red so switch to IR LED  
			 //TO DO:  Set appropriate IR LED intensity
			// PWM1_SetRatio16(Ratio)		Ratio is a 16 bit number representing Duty Cycle 
			FTM2_CH1_PWM_Start(pwmRedValue);
		}
		irWaveLength = ~irWaveLength;		// Toggle the Value of irWavelength
		ad2MeasurementComplete = TRUE;		// Set Measurement Complete Flag
		AD2_Stop();
}

/*
** ===================================================================
**     Event       :  AD2_OnCalibrationEnd (module Events)
**
**     Component   :  AD2 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD2_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
	AD1_GetChanValue(0, &measuredValue);		/* Get the measured values */
	FTM2_CH1_PWM_Stop();
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
