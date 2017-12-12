/*
 * Timers.c
 *
 *  Created on: Dec 3, 2013
 *      Author: Justin Vaio
 */


/****************************************************************************
*                           FTM Driver for Kinetis
*****************************************************************************
* @file: Kinetis_FTM.c
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


#include "Timers.h"

/*****************************************************************************
*                                Definitions
*****************************************************************************/

 


#define FTM1_MOD_VALUE  15     //10uS per count  

#define FTM2_PWMCH1_PORT      PORTA_PCR11 //PWM Output on PTA11
#define FTM2_PWMCH1_PIN       11
#define FTM2_PWMCH1_PINDDR    GPIOA_PDDR
#define FTM2_PWMCH1_PINCLR    GPIOA_PCOR

/*****************************************************************************
*                                  Globals
*****************************************************************************/
extern UINT32 sampleTime;


/*****************************************************************************
*                                  Locals
*****************************************************************************/

unsigned long ElapsedTimeIn_us=0;

/*****************************************************************************
*                                 Functions  
*****************************************************************************/



/* FTM0 sets the sample time.  When ISR triggers the test has completed */
void FTM0_Init (void)
{ 
  SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK; 								//Gives clock to FTM0
  Led_Select_ClrVal();
  FTM0_MOD=sampleTime;
  FTM0_SC = (FTM_SC_CLKS(2) | FTM_SC_TOIE_MASK | FTM_SC_PS(7));   	//Sets Clock Source to MCGFFCLK(fixed frequency clock = 24.414kHz) | Enables Timer Over Flow Interrupt | Sets prescaler to 128  
  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	// 24.414kHz/128 = 190.734375 Hz  ==> Period of 5.24mS 
  
  NVICICPR1|=(1<<30);                     //Clear any pending interrupts on FTM0
  NVICISER1|=(1<<30);                     //Enable interrupts from FTM0 module  
}


void FTM0_ISR(void)
{
 FTM0_SC &= ~FTM_SC_TOF_MASK;
 
 FTM0_MOD=sampleTime;			// Period of 5.24mS * 1097 = 10 Seconds

 testComplete = 1; 
}


void FTM0_Deinit(void)
{
 FTM0_SC = 0;
 FTM0_CNT = 0;
}



















/*****************************************************************************/
/* FTM1 is used for Software trigger */
void FTM1_Init(void)
{
  SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK; //Gives clock to FTM1
  
  FTM1_MOD = FTM1_MOD_VALUE;
  FTM1_SC = (FTM_SC_CLKS(1) | FTM_SC_TOIE_MASK | FTM_SC_PS(5));   //Runs FTM System Clock Prescaler = 32
  
  NVICICPR1|=(UINT32)(1<<31);                     //Clear any pending interrupts on FTM1
  NVICISER1|=(UINT32)(1<<31);                     //Enable interrupts from FTM1 module  
}

/*****************************************************************************/

void FTM1_Deinit (void)
{
 FTM1_SC = 0;
 FTM1_CNT = 0;
}


/*****************************************************************************/

void FTM1_ISR (void)
{
 FTM1_SC &= ~FTM_SC_TOF_MASK;
 
 FTM1_MOD=FTM1_MOD_VALUE;
 ElapsedTimeIn_us += FTM1_OVF_PERIOD_us;
 
}
















/*****************************************************************************/
/* FTM2 is used for PWM */
void FTM2_Init(void)
{
	
	SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK; //Gives clock to FTM2 
	
	/*  Enables the generation of the trigger when the FTM counter is equal to the CNTIN register */ 
	FTM2_EXTTRIG |= FTM_EXTTRIG_INITTRIGEN_MASK;	
	FTM2_MODE |= FTM_MODE_INIT_MASK;
	
	/* Default ADC trigger source is PDB. In case you need ADC triggered directly from FTM add 
	next two lines. ADC0ALTTRGEN = 1 - alternate trigger for ADC, ADC1TRGSEL = 0x8 - FTM0 
	trigger*/ 
	//SIM_SOPT7 |= SIM_SOPT7_ADC0TRGSEL (0x8) | SIM_SOPT7_ADC0ALTTRGEN_MASK; /*FTM0 triggers ADC0*/
	//SIM_SOPT7 |= SIM_SOPT7_ADC1TRGSEL (0x8) | SIM_SOPT7_ADC1ALTTRGEN_MASK; /*FTM0 triggers ADC0*/
	/* SWSYNC = 1 - set PWM value update. This bit is cleared automatically */
	
	
	FTM0_SYNC |= FTM_SYNC_SWSYNC_MASK;
	FTM2_SC = FTM2_SC_CONFIG;
	FTM2_MOD = FTM2_MODULO;
	FTM2_CH1_Init();
}

/*****************************************************************************/

void FTM2_CH1_Init (void)
{
	/* Disable the write protection of some registers before they can be updated */
	FTM2_MODE |= FTM_MODE_WPDIS_MASK;			
	/* Channel Trigger is enabled and Sets the Trigger Flag when the FTM2_CNT 
	 * value (current count) equals the FTM2_C1V which holds the duty cycle setting(ON TIME) */
	//FTM2_EXTTRIG = FTM_EXTTRIG_INITTRIGEN_MASK;  
	/* Enable the internal FlexTimer counter to run in the debug mode */
	FTM2_CONF |= FTM_CONF_BDMMODE(3);

    FTM2_C1SC = (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK); //High True Pulses Edge Aligned PWM
    FTM2_C1V = (unsigned long)(FTM2_MODULO/2); //50% PW 
    FTM2_PWMCH1_PORT = PORT_PCR_MUX(3); //Go to PWM mode
}

/*****************************************************************************/

void FTM2_CH1_PWM_Start(UINT16 u16DutyCycle)
{
	//FTM2_EXTTRIG = FTM_EXTTRIG_CH1TRIG_MASK; 		/*  Clear the Trigger Flag in case it was already set */
	FTM2_PWMLOAD = FTM_PWMLOAD_LDOK_MASK;
	
	FTM2_C1V = u16DutyCycle;
	
	FTM2_PWMCH1_PORT = PORT_PCR_MUX(3); //Enables PWM Output
	FTM2_SC |= FTM_SC_CLKS(1); //System clock on FTM2, start generating PWM
}

/*****************************************************************************/

void FTM2_CH1_PWM_Stop (void)
{
	//FTM2_EXTTRIG = FTM_EXTTRIG_CH1TRIG_MASK; 		/*  Clear the Trigger Flag in case it was already set */
	FTM2_PWMCH1_PORT = PORT_PCR_MUX(1); //Set as GPIO
	FTM2_PWMCH1_PINDDR |= (1<<FTM2_PWMCH1_PIN); //Set as Output so the LED can be turned off when inactive
	FTM2_PWMCH1_PINCLR |= (1<<FTM2_PWMCH1_PIN); //Clear the output
	FTM2_SC &= ~FTM_SC_CLKS_MASK; // No clock selected, FTM2 Stops

	FTM2_CNT = 0; //Resets Counter
}
