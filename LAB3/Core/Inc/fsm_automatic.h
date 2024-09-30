/*
 * fsm_automatic.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "led_display.h"
#include "timer.h"
extern int number_clock1 ;
extern int number_clock2;
void fsm_automatic_runx();
void fsm_automatic_runy();
void fsm_clock(void);
#endif /* INC_FSM_AUTOMATIC_H_ */
