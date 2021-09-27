/*************************
 *
 *
 *
 *    File name   : main.c
 *    Description : Assignment 3 Blinkenlights - Bare Metal coding for FRDM-KL25Z development board
 *
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *    References: Dean Chapter 2 and 3 - INPUT, OUTPUT and FSM
 *    Class notes and slides - Howdy Pierce
 *	  IDE setup and board running help - Nimish Bhide and Mukta Darekar (SA's)
 *    Help for Finite State Machine -  Gaurang Rane
 *    Date  : 09/26/2021
 *
 *
 **************************/
/**
 * @file    Assignment3_Blinkenlights.c
 * @brief   Application entry point.
 */
//Including the Header files
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
//Defining user developed header files
#include "led.h"
#include "TSI.h"
#include "log.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
//volatile uint32_t g_touch_val = 0;
/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

#ifdef DEBUG
    PRINTF("HELLO WORLD");
#endif
    //Enabling the Port B clock
    PORTB_CLK();
    //Enabling the Port D clock
    PORTD_CLK();
    //Initializing the MUX port and Data direction port
    INIT_LED();
    //Blinking the RGB and White Led's as per STEP 1 sequence
    INIT_TEST();

    //Initializing the touch slider interface
    Touch_Init();

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
    	//Polling for Slider event function
        TSI_slider_read_FSM();
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
