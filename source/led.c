/*************************
 *
 *
 *
 *    File name   : led.c
 *    Description : This file is responsible for all LED control on Start up and Infinite Loop execution
 *    Finite state machine algorithm is used to manage the continuous polling of slider event and based on that led blinking is controlled
 *    The delay is an merely approximation of the actual values that is 100ms, 500ms, 1000ms, 2000ms and 3000ms
 *    The delay function is a counter loop which runs giving appropriate delay of value as passed
 *
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
//Including the Header files required for operation
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
//Defining user developed header files
#include "led.h"
#include "delay.h"
#include "TSI.h"

//Global declaration of LED pins on board
#define RED_LED_PIN (18)
#define GREEN_LED_PIN (19)
#define BLUE_LED_PIN (1)

//Global declaration of variables for Finite State Machine - Polling of Slider and controlling the LED's
volatile uint32_t g_touch_val = 0;   //Variable to read the Slider values
uint8_t g_touch_event = 0;			 //Detecting touch event variable
uint8_t g_led_color = 0;			 //LED color status variable
uint8_t g_on_count_delay = 5;		 //Variable to manage delays
uint8_t g_off_count_delay = 5;		 //Variable to manage delays
uint8_t g_on_initial_count[] = {5, 10, 20, 30};   //Number of times loop will run based on index variable - delay management
uint8_t g_on_initial_index = 1;                   //Index to change delays i.e 500m, 1000ms, 2000ms and 3000ms



void PORTB_CLK(){
	//Enabling Clock for PORT B - LED PIN 18 and 19
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
}

void PORTD_CLK(){
	//Enabling Clock for PORT D - LED PIN 1
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
}

void INIT_LED(){

	//Initializing all LED (RED, GREEN and BLUE) in this function

	//Enabling MUX Port for RED LED
	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(1);

	//Enabling MUX Port for GREEN LED
	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(1);

	//Enabling MUX Port for BLUE LED
	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |= PORT_PCR_MUX(1);

	//Defining the Data direction register for RED LED
	GPIOB->PDDR |= (1 << RED_LED_PIN);

	//Defining the Data direction register for GREEN LED
	GPIOB->PDDR |= (1 << GREEN_LED_PIN);

	//Defining the Data direction register for BLUE LED
	GPIOD->PDDR |= (1 << BLUE_LED_PIN);
}

//Function to Turn RED LED on - Works on Active LOW Logic - Hence clearing the bit will Turn the LED on
void RED_ON(){
	GPIOB->PCOR |= (1 << RED_LED_PIN);
}

//Function to Turn RED LED off - Works on Active LOW Logic - Hence setting the bit will Turn the LED off
void RED_OFF(){
	GPIOB->PSOR |= (1 << RED_LED_PIN);
}

//Function to Turn GREEN LED on - Works on Active LOW Logic - Hence clearing the bit will Turn the LED on
void GREEN_ON(){
	GPIOB->PCOR |= (1 << GREEN_LED_PIN);
}

//Function to Turn GREEN LED off - Works on Active LOW Logic - Hence setting the bit will Turn the LED off
void GREEN_OFF(){
	GPIOB->PSOR |= (1 << GREEN_LED_PIN);
}

//Function to Turn BLUE LED on - Works on Active LOW Logic - Hence clearing the bit will Turn the LED on
void BLUE_ON(){
	GPIOD->PCOR |= (1 << BLUE_LED_PIN);
}

//Function to Turn BLUE LED off - Works on Active LOW Logic - Hence setting the bit will Turn the LED off
void BLUE_OFF(){
	GPIOD->PSOR |= (1 << BLUE_LED_PIN);
}

//Function to Turn WHITE LED on - Works on Active LOW Logic - Hence clearing the bit will Turn the LED on
void WHITE_ON(){
	GPIOB->PCOR |= (1<< RED_LED_PIN);
	GPIOB->PCOR |= (1<< GREEN_LED_PIN);
	GPIOD->PCOR |= (1<< BLUE_LED_PIN);
}

//Function to Turn WHITE LED off - Works on Active LOW Logic - Hence setting the bit will Turn the LED off
void WHITE_OFF(){
	GPIOB->PSOR |= (1<< RED_LED_PIN);
	GPIOB->PSOR |= (1<< GREEN_LED_PIN);
	GPIOD->PSOR |= (1<< BLUE_LED_PIN);
}

//Function to turn all LED Turn off - Default Function
void DEFAULT_LED_STATE(){
	RED_OFF();
	GREEN_OFF();
	BLUE_OFF();

}

//Running this function on start-up as mentioned in STEP 1
void INIT_TEST(){

	//Making all the state to OFF
	DEFAULT_LED_STATE();
	//RED Led pattern 500ms ON and 100ms OFF
	RED_ON();
    delay(500);		//Delay for 500ms
    RED_OFF();
    delay(100);		//Delay for 100ms

    //GREEN Led pattern 500ms ON and 100ms OFF
    GREEN_ON();
    delay(500);		//Delay for 500ms
    GREEN_OFF();
    delay(100);		//Delay for 100ms

    //BLUE Led pattern 500ms ON and 100ms OFF
    BLUE_ON();
    delay(500);		//Delay for 500ms
    BLUE_OFF();
    delay(100);		//Delay for 100ms

    //WHITE Led pattern 100ms ON and 100ms OFF
    WHITE_ON();
    delay(100);		//Delay for 100ms
    WHITE_OFF();
    delay(100);		//Delay for 100ms
}

//Function for internal testing purpose - Not used anywhere in the program execution(can be ignored in grading)
void WHITE_PAT(){

	//White On for 500ms and Off for 500ms
	WHITE_ON();
	delay(500);
	WHITE_OFF();
	delay(500);

	//White On for 1000ms and Off for 500ms
	WHITE_ON();
	delay(1000);
	WHITE_OFF();
	delay(500);

	//White On for 2000ms and Off for 500ms
	WHITE_ON();
	delay(2000);
	WHITE_OFF();
	delay(500);

	//White On for 3000ms and Off for 500ms
	WHITE_ON();
	delay(3000);
	WHITE_OFF();
	delay(500);
}

//Function to read the slider values and update led color based on the range
//This function is developed using Finite State Machine algorithm which changes the color of the Led's based on touch event of slider
void TSI_slider_read_FSM(){
	//Defining all states of execution
	static enum  {read, run, off} next_state;

	//Cases to switch based on next_state
	switch (next_state)
	{
	case read:
		//Reading the slider value
		g_touch_val = Touch_Scan_LH();
#ifdef DEBUG
		PRINTF("Slider value %d\n\r", g_touch_val);
#endif

		//Checking if slider event is generated and then based on values - LED status variable value is changed
		if ((g_touch_val < 70) && (g_touch_event == 0))
		{
			g_led_color = 0;					//No touch occurred

		}
		if ((g_touch_val > 70) && (g_touch_val < 500))
		{
			g_led_color = 1;					//Left side slider was touched - RED LED state to be executed
			g_touch_event = 1;
			//Debug mode print statements
			#ifdef DEBUG
				PRINTF("Left side of slider touched - Red light to blink %d\n\r", g_touch_val);
			#endif
		}
		if ((g_touch_val > 500) && (g_touch_val < 800))
		{
			g_led_color = 2;					//Center side slider was touched - GREEN LED state to be executed
			g_touch_event = 1;
			//Debug mode print statements
			#ifdef DEBUG
				PRINTF("Center side of slider touched - Green light to blink %d\n\r", g_touch_val);
			#endif
		}
		if ((g_touch_val > 800))
		{
			g_led_color = 3;					//Right side slider was touched - BLUE LED state to be executed
			g_touch_event = 1;
			//Debug mode print statements
			#ifdef DEBUG
				PRINTF("Right side of slider touched - Blue light to blink %d\n\r", g_touch_val);
			#endif
		}
		if (g_on_count_delay == 0)
		{
			next_state = off;					//Checking delay variable to make the further pattern of blinking
			break;
		}

		next_state = run;						//Changing the next state to blink the leds based on the touch values
		break;

	case run:
		//Setting the LED as per the slider values
		//Case 1 - Touch was not pressed - Hence white should run as per the logic 500ms, 1000ms and so on
		if((g_led_color == 0) && (g_on_count_delay !=0))
		{
			WHITE_ON();
			delay(100);
			g_on_count_delay--;
		}

		//Case 1 - Left side of the touch was pressed - Hence Red should run as per the logic 500ms, 1000ms and so on
		if((g_led_color == 1) && (g_on_count_delay !=0))
		{
			GREEN_OFF();
			BLUE_OFF();
			RED_ON();
			delay(100);
			g_on_count_delay--;
		}

		//Case 1 - Center side of the touch was not pressed - Hence Green should run as per the logic 500ms, 1000ms and so on
		if((g_led_color == 2) && (g_on_count_delay !=0))
		{
			BLUE_OFF();
			RED_OFF();
			GREEN_ON();
			delay(100);
			g_on_count_delay--;
		}

		//Case 1 - Right side of the touch was not pressed - Hence Blue should run as per the logic 500ms, 1000ms and so on
		if((g_led_color == 3) && (g_on_count_delay !=0))
		{
			RED_OFF();
			GREEN_OFF();
			BLUE_ON();
			delay(100);
			g_on_count_delay--;
		}

		//Again testing for touch event
		next_state = read;
		break;

	case off:
		//Checking the run status of Led and changing the delay as per the Delay status
		//Checking if one set of execution with delay is completed for eg - 500ms ON and 500ms OFF
		if((g_on_count_delay == 0) && (g_off_count_delay !=0))
		{
			WHITE_OFF();
			delay(100);
			g_off_count_delay--;			//Decrementing to run the code that many times for appropriate delay
			if (g_off_count_delay ==0 )
			{
				//Moving to next index when the Delay count becomes 0
				g_on_count_delay = g_on_initial_count[g_on_initial_index];
				g_on_initial_index++;

				//Setting the Index back to 0 when all the delay loop are executed
				if (g_on_initial_index == 4)
				{
					g_on_initial_index = 0;
				}

				g_off_count_delay = 5;
			}
		}

		//Moving back to polling to slider values
		next_state = read;
		break;
	}
}






