/*************************
 *
 *
 *
 *    File name   : TSI.h
 *    Description : This file defines the functions which are used in TSI.c to initialize and read the slider value
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *    References: Dean Chapter 2 and 3 - INPUT, OUTPUT, FSM
 *    Class notes and slides - Howdy Pierce
 *	  IDE setup and board running help - Nimish Bhide and Mukta Darekar (SA's)
 *    Help for Finite State Machine -  Gaurang Rane
 *    Date  : 09/26/2021
 *
 *
 */

#ifndef TSI_H_
#define TSI_H_

/*************************************************************************************************************
 *
 * Name :		  	void Touch_Init()
 *
 *
 *
 * Description :	This function initializes the slider in BUSY wait loop
 * It defines all the internal register bit as required - oscillator, scanning, electrode voltage
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void Touch_Init();

/*************************************************************************************************************
 *
 * Name :		  	void Touch_Scan_LH()
 *
 *
 *
 * Description :	This function reads the slider values on user touch
 * Channel 10 is programmed and masked to get the touch input data
 *
 * Inputs: NONE
 *
 * Return: Touch sensor data
 *************************************************************************************************************/
int Touch_Scan_LH(void);

#endif /* TSI_H_ */
