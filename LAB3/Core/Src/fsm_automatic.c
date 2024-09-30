/*
 * fsm_automatic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#include "fsm_automatic.h"
#include "input_processing.h"
#include "main.h"
int ClockCounter = 0;
void fsm_clock(void){
	if(timer_flag[2] == 1){
		number_clock1--;
		if(number_clock1 <= 0){
			number_clock1 = timer_counter[0]/100 + 1;
		}
		setTimer(2, 1000);
	}
	if(timer_flag[3] == 1){
		number_clock2--;
		if(number_clock2 <= 0){
			number_clock2 = timer_counter[1]/100 + 1;
		}
		setTimer(3, 1000);
	}
	if(timer_flag[5] == 1){
		DisplayClock(ClockCounter);
		ClockCounter++;
		if(ClockCounter > 1){
			ClockCounter = 0;
		}
		setTimer(5, 100);
	}
	if(ClockCounter == 0){
		Display7Seg2(number_clock1);
	}
	else if(ClockCounter == 1){
		Display7Seg2(number_clock2);
	}
}

void fsm_automatic_runx(){
	switch(statusx){
	case INITX:
		statusx = AUTO_REDX;
		setTimer(0,5000);
		setTimer(2,10);
		number_clock1 = timer_counter[0]/100;
		break;
	case AUTO_REDX:
		if(counterMode != 2){
			DisplayREDX();
		}
		if(timer_flag[0] == 1){
			statusx = AUTO_GREENX;
			setTimer(0,3000);
		}
		if(ProcessButton3() == 1 && statusMode == MAN_RED){
			HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
			statusx = MAN_RED_SET;
			setTimer(0, counterTimeSet*1000);
			number_clock1 = timer_counter[0]/100;
		}
		break;
	case AUTO_GREENX:
		if(counterMode != 3){
			DisplayGREENX();
		}
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_YELLOWX;
			setTimer(0,2000);
		}
		break;
	case AUTO_YELLOWX:
		if(counterMode != 4){
			DisplayYELLOWX();
		}
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_REDX;
			setTimer(0,5000);
		}
		break;
		case MAN_RED_SET:
			if(timer_flag[0] == 1){
				statusx = AUTO_GREENX;
				setTimer(0,3000);
				number_clock1 = timer_counter[0]/100;
			}
			break;
		case MAN_GREEN_SET:
			if(timer_flag[0] == 1){
				statusx = AUTO_YELLOWX;
				setTimer(0,2000);
				setTimer(2, 10);
				number_clock1 = timer_counter[0]/100;
			}
			break;
		case MAN_YELLOW_SET:
			if(timer_flag[0] == 1){
				statusx = AUTO_REDX;
				setTimer(0,5000);
				setTimer(2, 10);
				number_clock1 = timer_counter[0]/100;
			}
			break;
	default:
		break;
	}
}
void fsm_automatic_runy(){
	switch(statusy){
	case INITY:
		DisplayGREENY();
		statusy = AUTO_GREENY;
		setTimer(1,3000);
		setTimer(3,10);
		number_clock2 = timer_counter[1]/100;
		break;
	case AUTO_REDY:
		DisplayREDY();
		if(timer_flag[1] == 1){
			statusy = AUTO_GREENY;
			setTimer(1,3000);
		}
		break;
	case AUTO_GREENY:
		DisplayGREENY();
		if(timer_flag[1] == 1){
			statusy = AUTO_YELLOWY;
			setTimer(1,2000);
		}
		break;
	case AUTO_YELLOWY:
		DisplayYELLOWY();
		if(timer_flag[1] == 1){
			statusy = AUTO_REDY;
			setTimer(1,5000);
		}
		break;
	default:
		break;
	}
}

