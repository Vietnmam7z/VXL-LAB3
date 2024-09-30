/*
 * global.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "input_reading.h"
#include "timer.h"

#define INITX 1
#define AUTO_REDX 2
#define AUTO_GREENX 3
#define AUTO_YELLOWX 4
#define INITY 5
#define AUTO_REDY 6
#define AUTO_GREENY 7
#define AUTO_YELLOWY 8
#define MAN_RED 9
#define MAN_GREEN 10
#define MAN_YELLOW 11
#define NORMAL_MODE 12
#define MAN_RED_SET 13
#define MAN_GREEN_SET 14
#define MAN_YELLOW_SET 15

extern int statusx;
extern int statusy;
extern int statusMode;
#endif /* INC_GLOBAL_H_ */
