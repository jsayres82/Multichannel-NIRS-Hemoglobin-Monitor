/*
 * Main_App.h
 *
 *  Created on: Nov 1, 2013
 *      Author: Justin Vaio
 */

#ifndef MAIN_APP_H_
#define MAIN_APP_H_

/******************************************************************************
*                            Freescale Semiconductor
*
* Name: Main_App.h
*
* Description: Main application routines
*
* MCU: Kinetis (K5x)
*
* Version for IAR 6.1
*******************************************************************************/

#include "derivative.h"
#include "types.h"          /* Contains User Defined Data Types */
#include "PublicTypes.h"
#include "SerialCommands.h"
#include "Led_Select.h"
#include "usb_cdc.h"        /* USB CDC Class Header File */
#include "NirsConfig.h"
#include "SensorMeasurement.h"
#include "Timers.h"


/*****************************************************************************
*                                Definitions
*******************************************************************************/

#define  CONTROLLER_ID      (0)   /* ID to identify USB CONTROLLER */ 

#define  DATA_BUFF_SIZE     (96)

#define  KBI_STAT_MASK      (0x0F)

#define EnableInterrupts asm ("CPSIE  i")
  /*!< Macro to enable all interrupts. */

#define DisableInterrupts asm ("CPSID  i")
  /*!< Macro to disable all interrupts. */
/*****************************************************************************
*                            Function Definition
*****************************************************************************/

/* Applications*/
extern void TestApp_Init(void);
extern void TestApp_Task(void);



void Measurement_PeriodicTask(void);

void Configuration_PeriodicTask(void);

#endif /* MAIN_APP_H_ */
