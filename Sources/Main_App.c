/*
 * Main_App.c
 *
 *  Created on: Nov 1, 2013
 *      Author: Justin Vaio
 */


/******************************************************************************
*                            Strohl Medical
*
* Name: Main_App.c
*
* Description: Main application routines
*
* MCU: Kinetis (K53)
*
* Version for Codewarrior 10.5
*******************************************************************************/

/******************************************************************************
*                                  Includes
******************************************************************************/
#include "Main_App.h"
#include "Timers.h"
#include "SensorMeasurement.h"
#include "NirsConfig.h"




/******************************************************************************
*                                 Definitions
******************************************************************************/


/******************************************************************************
*                                   Structs
******************************************************************************/


/******************************************************************************
*                                   Locals
******************************************************************************/
/* Virtual COM Application start Init Flag */
static volatile boolean start_app = FALSE;
/* Virtual COM Application Carrier Activate Flag */
static volatile boolean start_transactions = FALSE;
/* Receive Buffer */
static uint_8 g_curr_recv_buf[DATA_BUFF_SIZE];
/* Send Buffer */
static uint_8 g_curr_send_buf[DATA_BUFF_SIZE];
/* Receive Data Size */
static uint_8 g_recv_size;
/* Send Data Size */
static uint_8 g_send_size;

			

UINT8 configDataFlag;
UINT8 configDataLength = 0;
UINT8 configBuffer[32];


UINT8 InBuffer[32];	//From the PC to the MCU
UINT8 OutBuffer[128];	//From the MCU to the PC
UINT8 OutSize;
UINT8 InSize;

UINT16 IdNumber = 0;
UINT16 pwmRedValue;
UINT16 pwmIrValue;

UINT8 MeasurementActualState = MEASUREMENT_STATE_IDLE;


UINT8 MeasurementActualEvent = MEASUREMENT_EVENT_NONE;

static UINT16 MeasurementPacketId = 0;
/*****************************************************************************
*                             Function definitions
******************************************************************************/

static void USB_App_Callback(uint_8 controller_ID,
                        uint_8 event_type, void* val);
static void USB_Notify_Callback(uint_8 controller_ID,
                        uint_8 event_type, void* val);



UINT8 ConfigurationActualState = CONFIGURATION_STATE_IDLE;

UINT16 pwmIrValue;
UINT16 pwmRedValue;
void PDB0_Init(void);

/* Applications*/
extern void TestApp_Init(void);
extern void TestApp_Task(void);


void NewMeasurementDataEvent(void);
void NoMeasurementEvent(void);
void MeasurementCompleteEvent(void);
void MeasurementErrorEvent(void);
void MeasurementTestComplete(void);


void CalibrationCompleteOkInd(void);
void CalibrationErrorInd(void);



/** Array of pointers to functions to execute Configuration events */
const pFunc_t Configuration_Events[] = 
{
	NULL,						//CALIBRATION_EVENT_NONE,
	CalibrationCompleteOkInd, 	//CALIBRATION_EVENT_COMPLETE_OK,
	CalibrationErrorInd		//CALIBRATION_EVENT_ERROR,
};


/** Array of pointers to functions to execute Measurement events */
const pFunc_t Measurement_Events[] = 
{
		NoMeasurementEvent,
		MeasurementCompleteEvent,
		MeasurementErrorEvent,
		NewMeasurementDataEvent
};

/* NIRsMeasurement */
void StartMeasurementReq(void);
void AbortMeasurementReq(void);

/* Configuration */
void SetConfigurationReq(void);
void StartCalibrationReq(void);


/* Serial comm */
void SerialComm_PeriodicTask(void);
void SerialComm_SendData(void);


const  pFunc_t ExecuteCommandReq[21] =
{
	NULL,						// 0x00
	StartMeasurementReq,		// 0x01
	AbortMeasurementReq,		// 0x02  
	StartCalibrationReq,		// 0x03
	SetConfigurationReq,		// 0x04
	NULL,	        			// 0x05
	NULL,						// 0x06
	NULL,	        			// 0x07
	NULL,						// 0x08
	NULL,						// 0x09
	NULL,						// 0x0A
	NULL,						// 0x0B
	NULL,						// 0x0C
	NULL,						// 0x0D
	NULL,						// 0x0E
	NULL,						// 0x0F
	NULL, 						// 0x10
	NULL,						// 0x11
	NULL,						// 0x12
	NULL,						// 0x13
	NULL						// 0x14
};

/*******************************************************************************
*                                Functions
********************************************************************************/


/*
** ===================================================================
**     Method      :  TestApp_Init 
**
**     Description :
**         This function runs initializes the necessary settings for
**         USB communication, menu control, and measurements.
** ===================================================================
*/
void TestApp_Init(void) 
{       
    uint_8   error; 

    /*******************************/
    
    g_recv_size = 0;
    g_send_size= 0;
    DisableInterrupts;		
   
    /* Initialize the USB interface */
    error = USB_Class_CDC_Init(CONTROLLER_ID,USB_App_Callback,
                                NULL,USB_Notify_Callback);
    if(error != USB_OK)
    {
        /* Error initializing USB-CDC Class */
        return;
    }
    FTM2_Init();
  
    EnableInterrupts;  
    
	

}

/*
** ===================================================================
**     Method      :  TestApp_Task 
**
**     Description :
**         This function runs the main application processes including
**         USB communication, menu control, and measurements.
** ===================================================================
*/
void TestApp_Task(void)
{
	
	SerialComm_PeriodicTask();
	

	Configuration_PeriodicTask();
	
	Measurement_PeriodicTask();
}





/*
** ===================================================================
**     Method      :  SerialComm_PeriodicTask 
**
**     Description :
**         This function checks for recieved data from the host computer
**         parses the data, checks for validity and executes commands as necessary.
** ===================================================================
*/
void SerialComm_PeriodicTask(void)
{	
	
  UINT8 bufferCounter;
  
  //if there is data, read it
	  if(g_recv_size)
	  {
		  for (bufferCounter=0; bufferCounter < g_recv_size; bufferCounter++)
		  {
			  InBuffer[bufferCounter] = g_curr_recv_buf[bufferCounter];
		  }
		  
		  InSize = g_recv_size;
		  
		  g_recv_size=0;
		  
	
		  if (InBuffer[PACKET_TYPE] == REQ)
		  {
			  if (ExecuteCommandReq[InBuffer[COMMAND_OPCODE]] != NULL)
			  {
				  //check if OPCCODE is in a valid range
				  if ((InBuffer[COMMAND_OPCODE] <= LAST_COMMAND))
				  {
					  
					 // PwmLdd1_Enable(NULL);
					  ExecuteCommandReq[InBuffer[COMMAND_OPCODE]]();						  
				  }
			  }
		  }
		  else if(InBuffer[PACKET_TYPE] == IND)
		  {
			  int x = 0;
			  /*packet type is not a request*/
			  for(bufferCounter = 0; bufferCounter <= InSize; bufferCounter++)
			  {
				  configBuffer[bufferCounter] = InBuffer[bufferCounter];
			  }
			  //configDataLength = InBuffer[DATA_LENGTH];
			  configDataFlag = 1;
		  }
		  
		  InSize = 0;
	  }
  }



/*
** ===================================================================
**     Method      :  SerialComm_SendData 
**
**     Description :
**         This function loads the g_curr_send_buf with the data to be sent 
**         to the host computer, then calls the class driver to set up the 
**         USB controller.
** ===================================================================
*/
void SerialComm_SendData(void)
{
	UINT8 i=0;
	static UINT8 status;
	
	if (OutSize>0)			
	{
		g_send_size = OutSize;
		
		for(i=0;i<OutSize;i++)
		{
			g_curr_send_buf[i]=OutBuffer[i]; 
		}
		
		status = USB_Class_CDC_Interface_DIC_Send_Data(CONTROLLER_ID, &g_curr_send_buf[0],g_send_size);
		
		OutSize = 0;
		
	}
}




/******************************************************************************
 *
 *    @name        StartMeasurementReq
 *
 *    @brief       This function starts measurements
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

void StartMeasurementReq(void)
{
	//execute command and send confirm
	OutBuffer[OutSize++] = CFM;
	OutBuffer[OutSize++] = START_MEASUREMENT;
	OutBuffer[OutSize++] = 1;	//data bytes
	if (Measurement_StartMeasurement())
	{
		OutBuffer[OutSize++] = ERROR_OK;	
		
	}
	else
	{
		OutBuffer[OutSize++] = ERROR_BUSY;
	}
	

	
	(void)SerialComm_SendData();
	

	
}




/******************************************************************************
 *
 *    @name        AbortMeasurementReq
 *
 *    @brief       This function stops measurements
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

void AbortMeasurementReq(void)
{
	OutBuffer[OutSize++] = CFM;
	OutBuffer[OutSize++] = ABORT_MEASUREMENT;
	OutBuffer[OutSize++] = 0;	//data bytes
	OutBuffer[OutSize++] = ERROR_OK;
	(void)SerialComm_SendData();
	
	Measurement_AbortMeasurement();


}

/******************************************************************************
 *
 *    @name        SetConfigurationReq
 *
 *    @brief       This function starts measurements
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

void SetConfigurationReq(void)
{
	//execute command and send confirm
	OutBuffer[OutSize++] = CFM;
	OutBuffer[OutSize++] = SET_CONFIGURATION;
	OutBuffer[OutSize++] = 1;	//data bytes
	if ((ConfigurationActualState == CONFIGURATION_STATE_IDLE))
	{
		OutBuffer[OutSize++] = ERROR_OK;	
		ConfigurationActualState = CONFIGURATION_STATE_SETUP;
		
	}
	else
	{
		OutBuffer[OutSize++] = ERROR_BUSY;
	}
	
	
	(void)SerialComm_SendData();

	
}


/******************************************************************************
 *
 *    @name        StartCalibrationReq
 *
 *    @brief       This function starts measurements
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

void StartCalibrationReq(void)
{
	//execute command and send confirm
	OutBuffer[OutSize++] = CFM;
	OutBuffer[OutSize++] = SENSOR_CALIBRATION;
	OutBuffer[OutSize++] = 1;	//data bytes
	if (ConfigurationActualState == CONFIGURATION_STATE_IDLE)
	{
		OutBuffer[OutSize++] = ERROR_OK;	
		ConfigurationActualState = CONFIGURATION_STATE_CALIBRATING;
	}
	else
	{
		OutBuffer[OutSize++] = ERROR_BUSY;
	}
	
	
	(void)SerialComm_SendData();
	
	
}

/******************************************************************************
 *
 *    @name        NewDataReadyInd
 *
 *    @brief       This function sets up the new packet of measurement results
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/
/**
	This IND is sent to the host when new data from the SPO2 graph is available.
	It sends the following:
		- 32 unsigned words containing the graph information
		- 1 byte containing current oxygen saturation value
		- 1 byte containing current heart rate value
*/
void NewMeasurementDataEvent(void)
{
	
	UINT8 i;
	//copy SpO2Buffer to OutBuffer and send data
	OutBuffer[OutSize++] = IND;
	OutBuffer[OutSize++] = MEASUREMENT_EVENT_NEW_DATA_READY;
//	OutBuffer[OutSize++] = BUFFER_SIZE+2;
	
	OutBuffer[OutSize++] = (UINT8) (MeasurementPacketId >> 8);
	OutBuffer[OutSize++] = (UINT8) (MeasurementPacketId & 0x00FF);
	
	MeasurementPacketId++;
	
	for (i=0; i < BUFFER_SIZE; i++)
	{
		OutBuffer[OutSize++] = measurementResults[i];
	}
	
	//OutBuffer[OutSize++] = 0xF0;   // filler bit
	//OutBuffer[OutSize++] = 0xF0;	// filler bit
	
	(void)SerialComm_SendData();
}



void NoMeasurementEvent(void)
{
	// Do Nothing
}
void MeasurementCompleteEvent(void)
{

	
	OutBuffer[OutSize++] = IND;
	OutBuffer[OutSize++] = MEASUREMENT_EVENT_MEASUREMENT_COMPLETE_OK;    //1
	OutBuffer[OutSize++] = 1;
	OutBuffer[OutSize++] = 0;
	MeasurementPacketId = 0;

	
	(void)SerialComm_SendData();
}
void MeasurementErrorEvent(void)
{
	//  Send measurement error code to host
}



void CalibrationCompleteOkInd(void)
{
	
	OutBuffer[OutSize++] = IND;
	OutBuffer[OutSize++] = MEASUREMENT_EVENT_MEASUREMENT_COMPLETE_OK;    //1
	OutBuffer[OutSize++] = 4;
	OutBuffer[OutSize++] = (UINT8)(pwmRedValue >> 8);
	OutBuffer[OutSize++] = (UINT8)((pwmRedValue & 0x00FF));
	OutBuffer[OutSize++] = (UINT8)(pwmIrValue >> 8);
	OutBuffer[OutSize++] = (UINT8)((pwmIrValue & 0x00FF));

	
	(void)SerialComm_SendData();
}


void CalibrationErrorInd(void)
{
	// TO DO:  Send calibration results back to Host	
}









/******************************************************************************
 *
 *    @name        USB_Notify_Callback
 *
 *    @brief       This function handles PSTN Sub Class callbacks
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : PSTN Event Type
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function handles USB_APP_CDC_CARRIER_ACTIVATED and
 * USB_APP_CDC_CARRIER_DEACTIVATED PSTN Events
 *****************************************************************************/

static void USB_Notify_Callback (
    uint_8 controller_ID,   /* [IN] Controller ID */
    uint_8 event_type,      /* [IN] PSTN Event Type */
    void* val               /* [IN] gives the configuration value */
)
{
    UNUSED (controller_ID)
    UNUSED (val)
    if(start_app == TRUE)
    {
        if(event_type == USB_APP_CDC_CARRIER_ACTIVATED)
        {
            start_transactions = TRUE;
        }
        else if(event_type == USB_APP_CDC_CARRIER_DEACTIVATED)
        {
            start_transactions = FALSE;
        }
    }
    return;
}



/******************************************************************************
 *
 *    @name        USB_App_Callback
 *
 *    @brief       This function handles Class callback
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

static void USB_App_Callback (
    uint_8 controller_ID,   /* [IN] Controller ID */
    uint_8 event_type,      /* [IN] value of the event */
    void* val               /* [IN] gives the configuration value */
)
{
    UNUSED (controller_ID)
    UNUSED (val)
    if(event_type == USB_APP_BUS_RESET)
    {
        start_app=FALSE;
    }
    else if(event_type == USB_APP_ENUM_COMPLETE)
    {
        start_app=TRUE;
    }
    else if((event_type == USB_APP_DATA_RECEIVED))
    //&&            (start_transactions == TRUE))
    {
        /* Copy Received Data buffer to Application Buffer */
        USB_PACKET_SIZE BytesToBeCopied;
        APP_DATA_STRUCT* dp_rcv = (APP_DATA_STRUCT*)val;
        uint_8 index;
        
        
        BytesToBeCopied = (USB_PACKET_SIZE)((dp_rcv->data_size > DATA_BUFF_SIZE) ?
                                      DATA_BUFF_SIZE:dp_rcv->data_size);
        
        
        for(index = 0; index<BytesToBeCopied ; index++)
        {
            g_curr_recv_buf[index]= dp_rcv->data_ptr[index];           
        }
        
        g_recv_size = index;
        
        (void)USB_Class_CDC_Interface_DIC_Recv_Data(CONTROLLER_ID, NULL, 0);
    }
    else if((event_type == USB_APP_SEND_COMPLETE)&&(start_transactions == TRUE))
    {
        /* Previous Send is complete. Queue next receive */
        (void)USB_Class_CDC_Interface_DIC_Recv_Data(CONTROLLER_ID, NULL, 0);
    }

    return;
}
