/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : VREF.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : Init_VREF
**     Version     : Component 01.004, Driver 01.04, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-10, 20:24, # CodeGen: 264
**     Abstract    :
**          This file implements the VREF (VREF) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : VREF
**          Device                                         : VREF
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Mode                                         : Low drive
**            Regulator                                    : Disabled
**          Pins                                           : 
**            VREFO Pin                                    : Disabled
**          Initialization                                 : 
**            Enable VREF                                  : yes
**            Call Init method                             : yes
**     Contents    :
**         Init - void VREF_Init(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file VREF.c
** @version 01.04
** @brief
**          This file implements the VREF (VREF) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup VREF_module VREF module documentation
**  @{
*/         

/* MODULE VREF. */

#include "VREF.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  VREF_Init (component Init_VREF)
**     Description :
**         This method initializes registers of the VREF module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void VREF_Init(void)
{
  /* SIM_SCGC4: VREF=1 */
  SIM_SCGC4 |= SIM_SCGC4_VREF_MASK;                                   
  /* VREF_SC: VREFEN=1,REGEN=0,??=0,??=0,??=0,VREFST=0,MODE_LV=1 */
  VREF_SC = (VREF_SC_VREFEN_MASK | VREF_SC_MODE_LV(0x01));                                   
}


/* END VREF. */
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