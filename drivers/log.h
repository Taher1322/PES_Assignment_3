/*
 * log.h
 *
 *  Created on: Sep 26, 2021
 *  Author: TAHER UJJAINWALA
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#ifdef DEBUG
#define LOG printf
#else
#define LOG(...)
#endif

#endif /* LOG_H_ */
