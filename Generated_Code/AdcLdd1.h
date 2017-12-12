/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AdcLdd1.h
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : ADC_LDD
**     Version     : Component 01.182, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-11, 15:02, # CodeGen: 272
**     Abstract    :
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : AdcLdd1
**          A/D converter                                  : ADC0
**          Discontinuous mode                             : no
**          Interrupt service/event                        : Disabled
**          DMA                                            : Disabled
**          A/D channel list                               : 10
**            Channel 0                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTA8/FTM1_CH0/FB_AD17/FTM1_QD_PHA/TRACE_D2/ADC0_SE11
**                  A/D channel (pin) signal               : 
**            Channel 1                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTB2/I2C0_SCL/UART0_RTS_b/ENET0_1588_TMR0/FTM0_FLT3/LCD_P2/ADC0_SE12/TSI0_CH7
**                  A/D channel (pin) signal               : 
**            Channel 2                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTB3/I2C0_SDA/UART0_CTS_b/ENET0_1588_TMR1/FTM0_FLT0/LCD_P3/ADC0_SE13/TSI0_CH8
**                  A/D channel (pin) signal               : 
**            Channel 3                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTA7/FTM0_CH4/FB_AD18/TRACE_D3/ADC0_SE10
**                  A/D channel (pin) signal               : 
**            Channel 4                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTC1/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/LCD_P21/ADC0_SE15/TSI0_CH14
**                  A/D channel (pin) signal               : 
**            Channel 5                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTB1/I2C0_SDA/FTM1_CH1/RMII0_MDC/MII0_MDC/FTM1_QD_PHB/LCD_P1/ADC0_SE9/ADC1_SE9/TSI0_CH6
**                  A/D channel (pin) signal               : 
**            Channel 6                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/LCD_P22/ADC0_SE4b/CMP1_IN0/TSI0_CH15
**                  A/D channel (pin) signal               : 
**            Channel 7                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTD1/SPI0_SCK/UART2_CTS_b/LCD_P41/ADC0_SE5b
**                  A/D channel (pin) signal               : 
**            Channel 8                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTD5/SPI0_PCS2/UART0_CTS_b/FTM0_CH5/EWM_OUT_b/LCD_P45/ADC0_SE6b
**                  A/D channel (pin) signal               : 
**            Channel 9                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTD6/SPI0_PCS3/UART0_RX/FTM0_CH6/FTM0_FLT0/LCD_P46/ADC0_SE7b
**                  A/D channel (pin) signal               : 
**          Static sample groups                           : Enabled
**            Sample group list                            : 1
**              Group 0                                    : 
**                Sample list                              : 1
**                  Sample 0                               : Enabled
**                    Channel index                        : 0
**          A/D resolution                                 : Autoselect
**          Low-power mode                                 : Disabled
**          High-speed conversion mode                     : Enabled
**          Asynchro clock output                          : Disabled
**          Sample time                                    : 24 clock periods
**          Number of conversions                          : 1
**          Conversion time                                : 15.666667 �s
**          ADC clock                                      : 3 MHz (333.333 ns)
**          Single conversion time - Single-ended          : 16.77 us
**          Single conversion time - Differential          : 19.77 us
**          Additional conversion time - Single-ended      : 15.666 us
**          Additional conversion time - Differential      : 18.666 us
**          Result type                                    : unsigned 16 bits, right justified
**          Trigger                                        : Disabled
**          Voltage reference                              : 
**            High voltage reference                       : 
**              Volt. ref. pin                             : VREFH
**              Volt. ref pin signal                       : 
**            Low voltage reference                        : 
**              Volt. ref. pin                             : VREFL
**              Volt. ref pin signal                       : 
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMeasurementComplete                      : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                         - LDD_TDeviceData* AdcLdd1_Init(LDD_TUserData *UserDataPtr);
**         Enable                       - LDD_TError AdcLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable                      - LDD_TError AdcLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         StartSingleMeasurement       - LDD_TError AdcLdd1_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         CancelMeasurement            - LDD_TError AdcLdd1_CancelMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         GetMeasuredValues            - LDD_TError AdcLdd1_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr,...
**         CreateSampleGroup            - LDD_TError AdcLdd1_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr,...
**         GetMeasurementCompleteStatus - bool AdcLdd1_GetMeasurementCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
**         StartCalibration             - LDD_TError AdcLdd1_StartCalibration(LDD_TDeviceData *DeviceDataPtr);
**         GetCalibrationResultStatus   - LDD_TError AdcLdd1_GetCalibrationResultStatus(LDD_TDeviceData *DeviceDataPtr);
**         ConnectPin                   - LDD_TError AdcLdd1_ConnectPin(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file AdcLdd1.h
** @version 01.08
** @brief
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
*/         
/*!
**  @addtogroup AdcLdd1_module AdcLdd1 module documentation
**  @{
*/         

#ifndef __AdcLdd1_H
#define __AdcLdd1_H

/* MODULE AdcLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "IO_Map.h"
#include "Cpu.h"

#include "ADC_PDD.h"

#ifdef __cplusplus
extern "C" { 
#endif


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define AdcLdd1_PRPH_BASE_ADDRESS  0x4003B000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define AdcLdd1_Init_METHOD_ENABLED    /*!< Init method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_Enable_METHOD_ENABLED  /*!< Enable method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_Disable_METHOD_ENABLED /*!< Disable method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_StartSingleMeasurement_METHOD_ENABLED /*!< StartSingleMeasurement method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_CancelMeasurement_METHOD_ENABLED /*!< CancelMeasurement method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_GetMeasuredValues_METHOD_ENABLED /*!< GetMeasuredValues method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_CreateSampleGroup_METHOD_ENABLED /*!< CreateSampleGroup method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_GetMeasurementCompleteStatus_METHOD_ENABLED /*!< GetMeasurementCompleteStatus method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_StartCalibration_METHOD_ENABLED /*!< StartCalibration method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_GetCalibrationResultStatus_METHOD_ENABLED /*!< GetCalibrationResultStatus method of the component AdcLdd1 is enabled (generated) */
#define AdcLdd1_ConnectPin_METHOD_ENABLED /*!< ConnectPin method of the component AdcLdd1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */


/* Component specific public constants */

/* Driver mode */

/* A/D resolution of the component (the count of bits) */
#define AdcLdd1_ADC_RESOLUTION          16

/* Name of AD channel. If the "A/D channel (pin) signal" property in the channel
   pin group is not empty the constant "ComponentName_Signal" with the value of the channel
   index is generated, where the ComponentName = value of the "Component name" property
   and "Signal" is the value of the " A/D channel (pin) signal" property. This constant
   can be used in the method CreateSampleGroup() to specify required channel.
   (See ComponentName_TSample struct) */

/* This constant contains the number of channels in the "A/D channel list"
   group */
#define AdcLdd1_CHANNEL_COUNT           10u

/* This constant can be used in the sample array to create a gap in sample group.
   It is intended to disable a measurement of a sample */
#define AdcLdd1_NO_CHANNEL              0x1FU

/* This constant contains the number of static sample groups */
#define AdcLdd1_STATIC_GROUP_COUNT      1U

/* These constants contain the number of samples in each static sample group. */
#define AdcLdd1_STATIC_GROUP_0_SAMPLE_COUNT 1U

/* This constant contains the maximal size through all static sample groups */
#define AdcLdd1_MAX_STATIC_GROUP_SAMPLE_COUNT 1U

/* HW specific public constants */

/* Maximal number of samples in one sample group. This constant is HW specific.
   The CreateSampleGroup() method returns ERR_PARAM_SAMPLE_COUNT if the SampleCount parameter
   is greater then this constant. The value of this constant depends on the number
   of samples the HW is capable to measure in one measurement cycle. */
#define AdcLdd1_MAX_HW_SAMPLE_COUNT     1U

/* This constant informs about the actual width of results. */
#define AdcLdd1_RESULT_WIDTH            16U

/* This constant informs about the native size of result in bytes */
#define AdcLdd1_RESULT_WIDTH_BYTES      2U

/* This parameter informs about the type of results. */
#define AdcLdd1_RESULT_TYPE_UNSIGNED

/* Measurement result data type. Definition of the type depends
   on "Result type" property value. */
typedef uint16_t AdcLdd1_TResultData;


/*
** ===================================================================
**     Method      :  AdcLdd1_Init (component ADC_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* AdcLdd1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_Enable (component ADC_LDD)
*/
/*!
**     @brief
**         Enables ADC device. If possible, this method switches on A/D
**         converter device, voltage reference, etc. This method is
**         intended to be used together with [Disable()] method to
**         temporary switch On/Off the device after the device is
**         initialized. This method is required if the [Enabled in init.
**         code] property is set to "no" value.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
*/
/* ===================================================================*/
LDD_TError AdcLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_Disable (component ADC_LDD)
*/
/*!
**     @brief
**         Disables the ADC device. If possible, this method switches
**         off A/D converter device, voltage reference, etc. (for
**         example to avoid power consumption and possible interference).
**         When the device is disabled, some component methods should
**         not be called. If so, error ERR_DISABLED is reported. This
**         method is intended to be used together with [Enable()]
**         method to temporary switch On/Off the device after the
**         device is initialized. This method is not required. The
**         [Deinit()] method can be used to switch off and uninstall
**         the device.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
*/
/* ===================================================================*/
LDD_TError AdcLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_StartSingleMeasurement (component ADC_LDD)
*/
/*!
**     @brief
**         This method starts one measurement of the selected group of
**         samples and exits immediately. This is ADC SW trigger method.
**         The group of samples for measurement is specified by
**         preceding call to [SelectSampleGroup()] or
**         [CreateSampleGroup] method. 
**         DMA disabled: The [OnMeasurementComplete() ] event is
**         invoked after the measurement is done and if the event is
**         enabled. Results of the measurement can be read by the
**         [GetMeasuredValues()] method. 
**         DMA enabled: DMA request from configured ADC is enabled
**         automatically. The [OnMeasurementComplete() ] event is
**         invoked after the requested number of results are
**         transferred to destination buffer by DMA and if the event is
**         enabled. [GetMeasuredValues()] method is not available if
**         DMA mode is enabled. If the DMA transfer was completed
**         before and DMA is not recofingured, DMA error can occur. See
**         also [SetBuffer()] method. 
**         The state of the measurement can be also polled by the
**         [GetMeasurementCompleteStatus()] method. The [Discontinuous
**         mode] doesn't support this method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A measurement is in progress 
*/
/* ===================================================================*/
LDD_TError AdcLdd1_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_CancelMeasurement (component ADC_LDD)
*/
/*!
**     @brief
**         This method cancels the measurement in progress. Typically
**         the OnMeasurementComplete() event is not invoked for
**         cancelled measurement. If DMA mode is enabled, DMA request
**         from ADC is disabled and DMA transfer is cancelled. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
*/
/* ===================================================================*/
LDD_TError AdcLdd1_CancelMeasurement(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_CreateSampleGroup (component ADC_LDD)
*/
/*!
**     @brief
**         This method prepares HW for next measurement according to
**         array of samples defined during run-time. The array of
**         samples should be prepared prior to calling this method.
**         Pointer to the array is passed into this method in parameter
**         SampleGroupPtr. The number of samples is defined by
**         parameter SampleCount. Once any group is prepared, the
**         measurement can be started multiple times. Note: This method
**         works only with the sample groups defined during run-time.
**         For design-time defined groups use [SelectSampleGroup()]
**         method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         SampleGroupPtr  - Pointer to the
**                           sample definition array. This array can be
**                           released as soon as the method ends.
**     @param
**         SampleCount     - Number of items in the
**                           sample definition array. Must be less than
**                           or equal to
**                           ComponentName_MAX_HW_SAMPLE_COUNT.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_INDEX - Channel index in
**                           SampleGroup structure is out of range
**                           ERR_PARAM_SAMPLE_COUNT - SampleCount
**                           variable value is out of range
**                           ERR_BUSY - Measurement is in progress 
*/
/* ===================================================================*/
LDD_TError AdcLdd1_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr, LDD_ADC_TSample *SampleGroupPtr, uint8_t SampleCount);

/*
** ===================================================================
**     Method      :  AdcLdd1_GetMeasuredValues (component ADC_LDD)
*/
/*!
**     @brief
**         This method copies results of the last measurement to the
**         user supplied buffer. Data size depends on the size of
**         measured sample group (see [SelectSampleGroup()] or
**         [CreateSampleGroup()] method). Data representation is
**         defined by the [Result type] property. Typically this method
**         is called from [OnMeasurementComplete] event to get results
**         of the last measurement. This method is not available if DMA
**         is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to the start of the
**                           buffer for new results. Count of stored
**                           measured values equals to the count of the
**                           samples in the active sample group. It is
**                           in the user responsibility to provide
**                           buffer with appropriate size.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
*/
/* ===================================================================*/
LDD_TError AdcLdd1_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_GetMeasurementCompleteStatus (component ADC_LDD)
*/
/*!
**     @brief
**         Returns whether the measurement is done and the results can
**         be read by the user. It can be used to poll the state of
**         measurement if [Interrupt service/event] is disabled or if
**         [OnMeasurementComplete] event is disabled by the
**         [SetEventMask()] methods.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code
**                           true - Measurement is done
**                           false - Measurement is in progress
*/
/* ===================================================================*/
bool AdcLdd1_GetMeasurementCompleteStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_StartCalibration (component ADC_LDD)
*/
/*!
**     @brief
**         This method starts self calibration process. Calibration is
**         typically used to remove the effects of the gain and offset
**         from a specific reading.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A conversion is already running 
*/
/* ===================================================================*/
LDD_TError AdcLdd1_StartCalibration(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_GetCalibrationResultStatus (component ADC_LDD)
*/
/*!
**     @brief
**         This method should be used for check the last calibration
**         result. If calibration completed normally the method finish
**         calibration process by writing gain calibration values.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code
**                           ERR_OK - OK 
**                           ERR_FAILED - Last calibration hasn't been
**                           finished correctly
*/
/* ===================================================================*/
LDD_TError AdcLdd1_GetCalibrationResultStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AdcLdd1_ConnectPin (component ADC_LDD)
*/
/*!
**     @brief
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is
**         available only for CPU derivatives and peripherals that
**         support the runtime pin sharing with other internal on-chip
**         peripherals.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         PinMaskPtr      - Pointer to the [structure of
**                           bit masks] for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this structure.
**                           Possible parameters:
**                           LDD_ADC_CHANNEL_X_PIN - Channel X pin (pair
**                           in differential mode) from the A/D channels
**                           list
**                           LDD_ADC_TRIGGER_X_PIN - External trigger
**                           pin
**                           LDD_ADC_HIGH_VOLT_REF_PIN - High voltage
**                           reference pin (for converter A on 56800
**                           family)
**                           LDD_ADC_LOW_VOLT_REF_PIN - Low voltage
**                           reference pin (for converter A on 56800
**                           family)
**                           
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_PARAM_MASK - A pin mask in the pin mask
**                           structure is not valid (requested event is
**                           not defined by this component or event is
**                           generated)
*/
/* ===================================================================*/
LDD_TError AdcLdd1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_ADC_TPinMask *PinMaskPtr);

/* END AdcLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __AdcLdd1_H */
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
