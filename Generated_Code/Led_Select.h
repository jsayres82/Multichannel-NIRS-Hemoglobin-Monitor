/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Led_Select.h
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-03, 09:22, # CodeGen: 142
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       120           |  PTC11/I2C1_SDA/I2S0_RXD/LCD_P31/ADC1_SE7b
**             ----------------------------------------------------
**
**         Port name                   : PTC
**
**         Bit number (in port)        : 11
**         Bit mask of the port        : 0x0800
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : GPIOC_PDOR [0x400FF080]
**         Port control register       : GPIOC_PDDR [0x400FF094]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool Led_Select_GetVal(void);
**         PutVal - void Led_Select_PutVal(bool Val);
**         ClrVal - void Led_Select_ClrVal(void);
**         SetVal - void Led_Select_SetVal(void);
**         NegVal - void Led_Select_NegVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Led_Select.h
** @version 01.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup Led_Select_module Led_Select module documentation
**  @{
*/         

#ifndef __Led_Select_H
#define __Led_Select_H

/* MODULE Led_Select. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "BitIoLdd1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  Led_Select_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Led_Select_GetVal() (BitIoLdd1_GetVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  Led_Select_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
#define Led_Select_PutVal(Val) (BitIoLdd1_PutVal(BitIoLdd1_DeviceData, (Val)))

/*
** ===================================================================
**     Method      :  Led_Select_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Led_Select_ClrVal() (BitIoLdd1_ClrVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  Led_Select_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Led_Select_SetVal() (BitIoLdd1_SetVal(BitIoLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  Led_Select_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Led_Select_NegVal() (BitIoLdd1_NegVal(BitIoLdd1_DeviceData))

/* END Led_Select. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Led_Select_H */
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