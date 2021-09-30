# PES_Assignment_3
Code for Assignment 3 for PES, ECEN-5813, Fall 2021 - Due Date >> 9/27/2021 @ 9:00 AM MDT

# Author: TAHER UJJAINWALA </br>

Assignment3_Blinkenlights.c - The main script which executes the start-up pattern and communicates between the slider and the LEDs on FRDM KL25Z  </br>
led.h - In this header file all functions developed in led.c are defined  </br>
led.c - This files contains all the functions required to run LED  </br>
delay.h - In this header file function of delay.c are defined for busy wait delay approximation  </br>
delay.c - This files runs the hard loop for delay using NOP (No operation) and approximates the requires delay  </br>
TSI.h -  In this header file all the functions developed in TSI.c are defined  </br>
TSI.c - File containing definitions for clock gating and accessing the Capacitive Sensor  </br>

# Project Comments
This projects implements the following routine :

At program startup, Blinkenlights will “test” the LED by blinking in the following pattern:

RED for 500 msec, OFF for 100 msec,
GREEN for 500 msec, OFF for 100 msec,
BLUE for 500 msec, OFF for 100 msec
WHITE (that is, RED, GREEN, and BLUE all on) for 100 msec, OFF for 100 msec
WHITE for 100 msec, OFF for 100 MSEC
Blinkenlights will then enter an infinite loop where the LED will be flashed using the following pattern:

ON for 500 msec, OFF for 500 msec,
ON for 1000 msec, OFF for 500 msec,
ON for 2000 msec, OFF for 500 msec,
ON for 3000 msec, OFF for 500 msec
Go back to the top (e.g., ON for 500 msec...)
During the infinite loop, the color when the LED is ON will initially be white. If the user touches the capacitive touch slider, the color will change as follows:

User touches Color
Left side of slider Red
Center of slider Green
Right side of slider Blue
(There is no way to get back to white after touching the slider.)

The Blinkenlights code polls the touch slider once every 100 msec. If the LED is on when a touch is detected, the light color should change immediately.


# Developement Details
Software used Developed using MCUExpresso IDE 7.2.0 on Windows 10.
DEBUG Mode - Prints DEBUG Messages to UART terminal at Baud Rate of 115200 and 8N1.
RUN/Release Mode - RUN Mode, no debug messages are printed on UART Terminal
To see the console messages change to SemiHost in quick settings and see the Debug messages 
To see the console messages in UART mode change to UART in quick settings and open a new Terminal with 115200 Baud Rate and 8N1 settings 

# Extra Credit Answers - Disassembly 

What is the address of your main() function? 
The address of main() function is 000031d8 g     F .text	0000002e main






