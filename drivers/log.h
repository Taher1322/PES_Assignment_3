/*
 * log.h
 *
 *  Created on: Sep 26, 2021
 *  Author: TAHER UJJAINWALA
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
/*************************************************************************************************************
 *
 * Name :		  	DEBUG MESSAGES
 *
 *
 *
 * Description :	This generates messages when in DEBUG mode and not in RELEASE

 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

#ifdef DEBUG
#define LOG printf
#else
#define LOG(...)
#endif

#endif /* LOG_H_ */
