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
void fsm_manual_run1(void){
	switch(statusx){
	case CONF_RED:
		if(timer_flag[4] == 1){
			DisplayMAN_REDX();
			setTimer(4, 500);
		}
		if(counterMode == 3){
			statusx = CONF_GREEN;
			InitLED();
		}
		fsm_mode();
		SetMode();
		if(mode2_flag == 1){
			statusx = MAN_RED;
			setTimer(0, save_counterTimeSet*1000);
			number_clock1 = timer_counter[0]/100;
			statusy = AUTO_GREENY;
			setTimer(1, save_counterTimeSet*1000 - 2000);
			number_clock2 = timer_counter[1]/100;
			InitLED();
		}
		break;
	case MAN_RED:
		if(counterMode != 2){
			DisplayREDX();
		}
		else{
			if(timer_flag[4] == 1){
				DisplayMAN_REDX();
				setTimer(4, 500);
			}
		}
		ChangeModeX();
		fsm_clock();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_GREENX;
			if(mode2_flag == 1){
				setTimer(0,save_counterTimeSet*1000 - 2000);
			}
			else{
				setTimer(0,3000);
			}
			setTimer(2, 10);
			number_clock1 = timer_counter[0]/100;
		}
		break;
	case CONF_GREEN:
		if(timer_flag[4] == 1){
			DisplayMAN_GREENX();
			setTimer(4, 500);
		}
		if(counterMode == 4){
			statusx = CONF_YELLOW;
			InitLED();
		}
		fsm_mode();
		SetMode();
		if(mode3_flag == 1){
			statusx = MAN_RED;
			setTimer(0, save_counterTimeSet*1000 + 2000);
			number_clock1 = timer_counter[0]/100;
			statusy = AUTO_GREENY;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
			InitLED();
		}
		break;
	case MAN_GREEN:
		if(counterMode != 3){
			DisplayGREENX();
		}
		else{
			if(timer_flag[4] == 1){
				setTimer(4, 500);
				DisplayMAN_GREENX();
			}
		}
		ChangeModeX();
		fsm_clock();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_YELLOWX;
			if(mode2_flag == 1){
				if(save_counterTimeSet < 2){
					setTimer(0,save_counterTimeSet*1000);
				}
			}
			else{
				setTimer(0,2000);
			}
			setTimer(2, 10);
			number_clock1 = timer_counter[0]/100;
		}
		break;
	case CONF_YELLOW:
		if(timer_flag[4] == 1){
			DisplayMAN_YELLOWX();
			setTimer(4, 500);
		}
		if(counterMode == 1){
			statusx = AUTO_REDX;
			setTimer(0,5000);
			setTimer(2,100);
			number_clock1 = timer_counter[0]/100;
			InitLED();
		}
		fsm_mode();
		SetMode();
		if(mode4_flag == 1){
			statusx = MAN_RED;
			setTimer(0, save_counterTimeSet*1000 + 3000);
			number_clock1 = timer_counter[0]/100;
			statusy = AUTO_GREENY;
			setTimer(1, 3000);
			number_clock2 = timer_counter[1]/100;
			InitLED();
		}
		break;
	case MAN_YELLOW:
		if(counterMode != 4){
			DisplayYELLOWX();
		}
		else{
			if(timer_flag[4] == 1){
				setTimer(4, 500);
				DisplayMAN_YELLOWX();
			}
		}
		ChangeModeX();
		fsm_clock();
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_REDX;
			if(mode3_flag == 1){
				setTimer(0,save_counterTimeSet*1000 + 2000);
			}
			else if(mode4_flag == 1){
				setTimer(0,save_counterTimeSet*1000 + 3000);
			}
			else{
				setTimer(0,5000);
			}
			setTimer(2, 10);
			number_clock1 = timer_counter[0]/100;
		}
		break;
	default:
		break;
	}
}
void fsm_manual_run2(void){
	switch(statusy){
	case CONF_RED:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_REDY();
			setTimer(5, 500);
		}
		if(counterMode == 3){
			statusy = CONF_GREEN;
			InitLED();
		}
		break;
	case MAN_RED:
		if(counterMode != 2){
			DisplayREDY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_REDY();
				setTimer(5, 500);
			}
		}
		ChangeModeY();
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_GREENY;
			if(mode2_flag == 1){
				setTimer(1,save_counterTimeSet*1000 - 2000);
			}
			else{
				setTimer(1,3000);
			}
			setTimer(3, 10);
			number_clock2 = timer_counter[1]/100;
		}
		break;
	case CONF_GREEN:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_GREENY();
			setTimer(5, 500);
		}
		if(counterMode == 4){
			statusy = CONF_YELLOW;
			InitLED();
		}
		break;
	case MAN_GREEN:
		if(counterMode != 3){
			DisplayGREENY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_GREENY();
				setTimer(5, 500);
			}
		}
		ChangeModeY();
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_YELLOWY;
			if(mode2_flag == 1){
				if(save_counterTimeSet < 2){
					setTimer(1,save_counterTimeSet*1000);
				}
			}
			else{
				setTimer(1,2000);
			}
			setTimer(3, 10);
			number_clock2 = timer_counter[1]/100;
		}
		break;
	case CONF_YELLOW:
		fsm_mode();
		if(timer_flag[5] == 1){
			DisplayMAN_YELLOWY();
			setTimer(5, 500);
		}
		if(counterMode == 1){
			InitLED();
			statusy = AUTO_GREENY;
			setTimer(1,3000);
		}
		break;
	case MAN_YELLOW:
		if(counterMode != 4){
			DisplayYELLOWY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_YELLOWY();
				setTimer(5, 500);
			}
		}
		ChangeModeY();
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_REDY;
			if(mode3_flag == 1){
				setTimer(1,save_counterTimeSet*1000 + 2000);
			}
			else if(mode4_flag == 1){
				setTimer(1,save_counterTimeSet*1000 + 3000);
			}
			else{
				setTimer(1,5000);
			}
			setTimer(3, 10);
			number_clock2 = timer_counter[1]/100;
		}
		break;
	default:
		break;
	}
}
