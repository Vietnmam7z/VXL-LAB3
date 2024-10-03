/*
 * fsm_automatic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Genki
 */

#include "fsm_automatic.h"
#include "input_processing.h"
#include "main.h"
int DisplayCounter = 0;
int mode2_flag = 0;
int mode3_flag = 0;
int mode4_flag = 0;
int save_counterTimeSet = 0;
void SetMode(void){
	if(ProcessButton3() == 1 && counterMode == 2){
		mode2_flag = 1;
		mode3_flag = 0;
		mode4_flag = 0;
		save_counterTimeSet = counterTimeSet;
		if(statusx == AUTO_REDX && statusy == AUTO_GREENY){
			setTimer(1, counterTimeSet*1000 - 2000);
		}
		else if(statusx == AUTO_REDX && statusy == AUTO_YELLOWY){
			setTimer(1, counterTimeSet*1000);
		}
		if(statusy == AUTO_REDY && statusx == AUTO_GREENX){
			setTimer(0, counterTimeSet*1000 - 2000);
		}
		else if(statusy == AUTO_REDY && statusx == AUTO_YELLOWX){
			setTimer(0, counterTimeSet*1000);
		}
	}
	else if(ProcessButton3() == 1 && counterMode == 3){
		mode2_flag = 0;
		mode3_flag = 1;
		mode4_flag = 0;
		save_counterTimeSet = counterTimeSet;
		if(statusx == AUTO_GREENX){
			setTimer(1, counterTimeSet*1000 + 2000);
		}
		if(statusy == AUTO_GREENY){
			setTimer(0, counterTimeSet*1000 + 2000);
		}
	}
	else if(ProcessButton3() == 1 && counterMode == 4){
		mode2_flag = 0;
		mode3_flag = 0;
		mode4_flag = 1;
		save_counterTimeSet = counterTimeSet;
		if(statusx == AUTO_YELLOWX){
			setTimer(1, counterTimeSet*1000);
		}
		if(statusy == AUTO_YELLOWY){
			setTimer(0, counterTimeSet*1000);
		}
	}
}
void ChangeMode(void){
	if(counterMode == 1){
		mode4_flag = 0;
	}
	if(counterMode == 3){
		mode2_flag = 0;
	}
	if(counterMode == 4){
		mode3_flag = 0;
	}
}
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
	if(DisplayCounter == 0){
		Display7Seg(number_clock1%10);
	}
	else if(DisplayCounter == 1){
		Display7Seg(number_clock1/10);
	}
	else if(DisplayCounter == 2){
		Display7Seg(number_clock2%10);
	}
	else if(DisplayCounter == 3){
		Display7Seg(number_clock2/10);
	}
	else if(DisplayCounter == 4){
		Display7Seg(counterMode);
	}
	else if(DisplayCounter == 5){
		Display7Seg(counterTimeSet%10);
	}
	else if(DisplayCounter == 6){
		Display7Seg(counterTimeSet/10);
	}
	if(timer_flag[6] == 1){
		Display(DisplayCounter);
		DisplayCounter++;
		if(DisplayCounter > 6){
			DisplayCounter = 0;
		}
		setTimer(6, 50);
	}
}
void fsm_automatic_runx(){
	switch(statusx){
	case INITX:
		statusx = AUTO_REDX;
		setTimer(0,5000);
		setTimer(2,100);
		number_clock1 = timer_counter[0]/100;
		break;
	case AUTO_REDX:
		if(counterMode != 2){
			DisplayREDX();
		}
		else{
			if(timer_flag[4] == 1){
				DisplayMAN_REDX();
				setTimer(4, 500);
			}
		}
		SetMode();
		ChangeMode();
		if(mode2_flag == 1){
			statusx = MAN_RED;
			setTimer(0, save_counterTimeSet*1000);
			number_clock1 = timer_counter[0]/100;
		}
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_GREENX;
			setTimer(0,3000);
		}
		break;
	case AUTO_GREENX:
		if(counterMode != 3){
			DisplayGREENX();
		}
		else{
			if(timer_flag[4] == 1){
				setTimer(4, 500);
				DisplayMAN_GREENX();
			}
		}
		SetMode();
		ChangeMode();
		if(mode3_flag == 1){
			statusx = MAN_GREEN;
			setTimer(0, save_counterTimeSet*1000);
			number_clock1 = timer_counter[0]/100;
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
		else{
			if(timer_flag[4] == 1){
				setTimer(4, 500);
				DisplayMAN_YELLOWX();
			}
		}
		SetMode();
		ChangeMode();
		if(mode4_flag == 1){
			statusx = MAN_YELLOW;
			setTimer(0, save_counterTimeSet*1000);
			number_clock1 = timer_counter[0]/100;
		}
		if(timer_flag[0] == 1){
			InitLED();
			statusx = AUTO_REDX;
			if(mode3_flag == 1){
				setTimer(0,save_counterTimeSet*1000 + 2000);
			}
			else{
				setTimer(0,5000);
			}
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
		setTimer(3,100);
		number_clock2 = timer_counter[1]/100;
		break;
	case AUTO_REDY:
		if(counterMode != 2){
			DisplayREDY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_REDY();
				setTimer(5, 500);
			}
		}
		SetMode();
		ChangeMode();
		if(mode2_flag == 1){
			statusy = MAN_RED;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_GREENY;
			setTimer(1,3000);
		}
		break;
	case AUTO_GREENY:
		if(counterMode != 3){
			DisplayGREENY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_GREENY();
				setTimer(5, 500);
			}
		}
		SetMode();
		ChangeMode();
		if(mode3_flag == 1){
			statusy = MAN_GREEN;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_YELLOWY;
			setTimer(1,2000);
		}
		break;
	case AUTO_YELLOWY:
		if(counterMode != 4){
			DisplayYELLOWY();
		}
		else{
			if(timer_flag[5] == 1){
				DisplayMAN_YELLOWY();
				setTimer(5, 500);
			}
		}
		SetMode();
		ChangeMode();
		if(mode4_flag == 1){
			statusy = MAN_YELLOW;
			setTimer(1, save_counterTimeSet*1000);
			number_clock2 = timer_counter[1]/100;
		}
		if(timer_flag[1] == 1){
			InitLED();
			statusy = AUTO_REDY;
			if(mode3_flag == 1){
				setTimer(1,save_counterTimeSet*1000 + 2000);
			}
			else{
				setTimer(1,5000);
			}
		}
		break;
	default:
		break;
	}
}

