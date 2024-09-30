/*
 * fsm_manual.c
 *
 *  Created on: 29 Sep 2024
 *      Author: Genki
 */

#include "fsm_manual.h"
#include "led_display.h"
#include "input_processing.h"
#include "fsm_automatic.h"
void fsm_manual_run(void){
	switch(statusMode){
	case NORMAL_MODE:
		if(counterMode == 2){
			statusMode = MAN_RED;
			setTimer(4, 500);
		}
		break;
	case MAN_RED:
		if(timer_flag[4] == 1){
			DisplayMAN_RED();
			setTimer(4, 500);
		}
		if(counterMode == 3){
			statusMode = MAN_GREEN;
			setTimer(4, 500);
		}
		break;
	case MAN_GREEN:
		if(timer_flag[4] == 1){
			setTimer(4, 500);
			DisplayMAN_GREEN();
		}
		if(counterMode == 4){
			statusMode = MAN_YELLOW;
			setTimer(4, 500);
		}
		break;
	case MAN_YELLOW:
		if(timer_flag[4] == 1){
			setTimer(4, 500);
			DisplayMAN_YELLOW();
		}
		if(counterMode == 1){
			statusMode = NORMAL_MODE;
		}
		break;
	default:
		break;
	}
}
