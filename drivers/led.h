/*************************
 *
 *
 *
 *    File name   : led.h
 *    Description : This file is responsible for all functions which are implemented in led.c for program execution

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
#ifndef LED_H_
#define LED_H_

void PORTB_CLK();
void PORTD_CLK();
void INIT_LED();
void DEFAULT_LED_STATE();
void INIT_TEST();
void WHITE_PAT();
void RED_ON();
void RED_OFF();
void GREEN_ON();
void GREEN_OFF();
void BLUE_ON();
void BLUE_OFF();
void WHITE_ON();
void WHITE_OFF();
void TSI_slider_read_FSM();

#endif /* LED_H_ */
