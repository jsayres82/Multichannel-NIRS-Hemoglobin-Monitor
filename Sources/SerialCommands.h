/*
 * SerialCommands.h
 *
 *  Created on: Nov 1, 2013
 *      Author: Justin Vaio
 */

#ifndef SERIALCOMMANDS_H_
#define SERIALCOMMANDS_H_



#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"


#define REQ		0x52
#define CFM		0x43
#define IND		0x69


typedef enum
{
	UNUSED1,        		 		// 0x00
	START_MEASUREMENT,        		// 0x01       
	ABORT_MEASUREMENT,				// 0x02    
	SENSOR_CALIBRATION,		    	// 0x03
	SET_CONFIGURATION,				// 0x04
	UNUSED2,  						// 0x05
	NEW_DATA_READY,  				// 0x06
		
	UNUSED3,			// 0x07 	
	UNUSED4,			// 0x08 
	UNUSED5,						// 0x09
	UNUSED6,          			// 0x0A,
	UNUSED7, 			// 0x0B,
	UNUSED8,                   				// 0x0C,
	UNUSED9,									// 0x0D
	UNUSED10,								    // 0x0E
	UNUSED11,									// 0x0F
	UNUSED12,									// 0x10
	UNUSED13,									// 0x11
	UNUSED14,									// 0x12
	UNUSED15,									// 0x13
	UNUSED16									// 0x14
} CommandsOpCode_e;


#define FIRST_COMMAND		0
#define LAST_COMMAND		0x14


typedef enum
{
	ERROR_OK,               // 0x00
	ERROR_BUSY,             // 0x01
	ERROR_INVALID_OPCODE    // 0x02
} ErrorCodes_e;



#define PACKET_TYPE		0
#define COMMAND_OPCODE	1
#define DATA_LENGTH		2
#define DATA_PACKET		3
#define DATA_ONE		4

#endif /* SERIALCOMMANDS_H_ */
