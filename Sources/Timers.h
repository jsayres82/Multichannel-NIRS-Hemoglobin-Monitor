/*
 * Timers.h
 *
 *  Created on: Dec 3, 2013
 *      Author: Justin Vaio
 */

#ifndef TIMERS_H_
#define TIMERS_H_


/****************************************************************************
*                           FTM Driver for Kinetis
*****************************************************************************
* @file: Kinetis_FTM.h
* 
* @author : Santiago Lopez [SL]  Freescale Americas
*
* @version: 1.0 for IAR
*
* @date: 13/01/11
*
* @description: Drivers for Kinetis Flex Timer
*******************************************************************************
* @changes:
*
*    Date       Author         Version               Description of Change
*
*  13/01/11       SL             1.0                    Initial Version
******************************************************************************/

#ifndef _KINETIS_FTM_H_
#define _KINETIS_FTM_H_

#include "derivative.h"
#include "PublicTypes.h"
#include "SensorMeasurement.h"
#include "NirsConfig.h"

/*****************************************************************************
*                                  Globals
*****************************************************************************/

extern unsigned char FTM_DecrementValue;     //Value for SWTimer

#define FTM1_OVF_PERIOD_us     10

#define FTM2_SC_CONFIG         (FTM_SC_PS(1)); //Frec divided by 2 = 48MHz/2 = 24MHz
#define FTM2_MODULO            1200 //For 1/24MHz = 41.66nS     41.66nS * 1200 = period of 50uS ==>  20Khz on PWM
#define FTM2_CH1_PWM_MAX_VAL    FTM2_MODULO

extern unsigned char FTM_DecrementValue;


extern unsigned long ElapsedTimeIn_us;

/*****************************************************************************
*                          Function Definitions  
*****************************************************************************/
extern void FTM0_Init (void);
extern void FTM1_Init(void);
extern void FTM2_Init(void);


void FTM0_ISR (void);
void FTM1_ISR (void);

void FTM2_CH1_Init (void);
extern void FTM2_CH1_PWM_Start(UINT16 u16DutyCycle);
extern void FTM2_CH1_PWM_Stop (void);


void FTM0_Deinit(void);
extern void FTM1_Deinit (void);
#endif
#endif /* TIMERS_H_ */
