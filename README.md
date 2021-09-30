# PES_Assignment_3
Code for Assignment 3 for PES, ECEN-5813, Fall 2021 - Due Date >> 9/27/2021 @ 9:00 AM MDT

# Author: TAHER UJJAINWALA </br>

Contact me if you are facing issue in execution of the code @ tauj5361@colorado.edu

Assignment3_Blinkenlights.c - The main script which executes the start-up pattern and communicates between the slider and the LEDs on FRDM KL25Z  </br>
led.h - In this header file all functions developed in led.c are defined  </br>
led.c - This files contains all the functions required to run LED  </br>
delay.h - In this header file function of delay.c are defined for busy wait delay approximation  </br>
delay.c - This files runs the hard loop for delay using NOP (No operation) and approximates the requires delay  </br>
TSI.h -  In this header file all the functions developed in TSI.c are defined  </br>
TSI.c - This files Initialized the touch sensor and reads the data on user input </br>

# Project Comments
This projects implements the following routine : </br>

At program startup, Blinkenlights will “test” the LED by blinking in the following pattern: </br>

RED for 500 msec, OFF for 100 msec, </br>
GREEN for 500 msec, OFF for 100 msec, </br>
BLUE for 500 msec, OFF for 100 msec </br>
WHITE (that is, RED, GREEN, and BLUE all on) for 100 msec, OFF for 100 msec </br>
WHITE for 100 msec, OFF for 100 MSEC </br>
Blinkenlights will then enter an infinite loop where the LED will be flashed using the following pattern: </br>

ON for 500 msec, OFF for 500 msec, </br>
ON for 1000 msec, OFF for 500 msec, </br>
ON for 2000 msec, OFF for 500 msec, </br>
ON for 3000 msec, OFF for 500 msec </br>
Go back to the top (e.g., ON for 500 msec...) </br>
During the infinite loop, the color when the LED is ON will initially be white. If the user touches the capacitive touch slider, the color will change as follows: </br>

User touches Color </br>
Left side of slider Red </br>
Center of slider Green </br>
Right side of slider Blue </br>
(There is no way to get back to white after touching the slider.) </br>

The Blinkenlights code polls the touch slider once every 100 msec. If the LED is on when a touch is detected, the light color should change immediately. </br>


# Developement Details </br>
Software used Developed using MCUExpresso IDE 7.2.0 on Windows 10. </br>
DEBUG Mode - Prints DEBUG Messages to UART terminal at Baud Rate of 115200 and 8N1. </br>
RUN/Release Mode - RUN Mode, no debug messages are printed on UART Terminal </br>
To see the console messages change to SemiHost in quick settings and see the Debug messages  </br>
To see the console messages in UART mode change to UART in quick settings and open a new Terminal with 115200 Baud Rate and 8N1 settings </br>

# Extra Credit Answers - Disassembly </br>

What is the address of your main() function? </br>
The address of main() function is 000031d8 g     F .text	0000002e main </br>

The size of delay() 00003206 g     F .text	00000030 delay </br>

Disassembly of the delay function is explained as follow </br>

The values of registers are stored in stack using Push instruction


00003206 <delay>:
  # Push Link register and R7 to stack 
  
    3206:	b580      	push	{r7, lr}
  
  # Subtrack the stack by 8 - To increase the value of the stack 
  
    3208:	b082      	sub	sp, #8
  
  # Add content of SP with #0 and store it in R7 --> R7 = SP + 0
  
    320a:	af00      	add	r7, sp, #0
  
 # Store R0 to memory starting from R7 + #4
  
    320c:	6078      	str	r0, [r7, #4]
  
 # Load R2 with contents of R7 + #4
  
    320e:	687a      	ldr	r2, [r7, #4]
  
 # Move --> R3 = R2
  
    3210:	0013      	movs	r3, r2
  
 # Logical Shift Left by updating the conditional flags  --> R3 = R3 << 2
  
    3212:	009b      	lsls	r3, r3, #2
  
  # Add --> R3 = R3 + R2
  
    3214:	189b      	adds	r3, r3, r2
  
  # Logical Shift Left by updating the conditional flags  --> R2 = R3 << 6
  
    3216:	019a      	lsls	r2, r3, #6
  
  # Add --> R3 = R3 + R2
  
    3218:	189b      	adds	r3, r3, r2
  
  # Logical Shift Left by updating the conditional flags  --> R3 = R3 << 4
  
    321a:	011b      	lsls	r3, r3, #4
  
  # Store R3 to memory starting from R7 + #4
  
    321c:	607b      	str	r3, [r7, #4]
  
  # Check the condition if not equal continue 
  
    321e:	e000      	b.n	3222 <delay+0x1c>
  
  #  Move --> R8 = R8 No operation 
  
    3220:	46c0      	nop			; (mov r8, r8)
  
  # Load R3 with contents of R7 + #4
  
    3222:	687b      	ldr	r3, [r7, #4]
  
  # Subtract by updating conditional flags --> R2 = R3 -1
  
    3224:	1e5a      	subs	r2, r3, #1
  
  # Store R2 to memory starting from R7 + #4
  
    3226:	607a      	str	r2, [r7, #4]
  
  # Compare R3 equal to zero Z flag will be set else cleared 
  
    3228:	2b00      	cmp	r3, #0
  
  # Branch if not equal to and run the loop 
  
    322a:	d1f9      	bne.n	3220 <delay+0x1a>
  
  #  Move --> R8 = R8 No operation 
  
    322c:	46c0      	nop			; (mov r8, r8)
  
  #  Move --> R8 = R8 No operation 
  
    322e:	46c0      	nop			; (mov r8, r8)
  
  # Store back the contents of R7 to stack pointer 
  
    3230:	46bd      	mov	sp, r7
  
  # Add the stack which was used at start 
  
    3232:	b002      	add	sp, #8
  
  # Pop the values back to Program counter for execution
  
    3234:	bd80      	pop	{r7, pc}






