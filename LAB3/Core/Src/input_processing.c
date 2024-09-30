/*
 * input_processing.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */
#include "main.h"
#include "led_display.h"
#include "input_reading.h"
#include "global.h"
enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;
enum ButtonState buttonState3 = BUTTON_RELEASED;
int counterMode = 0;
int counterTimeSet = 0;
int Mode3_flag = 0;
void fsm_for_input_processing1(void){
	switch(buttonState1){
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState1 = BUTTON_PRESSED ;
				if(ProcessButton1() == 1){
					  counterMode++;
					  if(counterMode > 4){
						  counterMode = 1;
					  }
				}
				  Display7Seg1(counterMode);
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(0)){
				buttonState1 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(0) == 1){
					buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;

				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(0)){
				buttonState1 = BUTTON_RELEASED;
			}
		break;
		}
	}
void fsm_for_input_processing2(void){
	switch(buttonState2){
		case BUTTON_RELEASED:
			if(is_button_pressed(1)){
				buttonState2 = BUTTON_PRESSED ;
				if(ProcessButton2() == 1){
					  counterTimeSet++;
					  if(counterTimeSet > 9){
						  counterTimeSet = 0;
					  }
				}
				  Display7Seg3(counterTimeSet);
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(1)){
				buttonState2 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(1) == 1){
					buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND;

				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(1)){
				buttonState2 = BUTTON_RELEASED;
			}
		break;
		}
	}
void fsm_for_input_processing3(void){
	switch(buttonState3){
		case BUTTON_RELEASED:
			if(is_button_pressed(2)){
				buttonState3 = BUTTON_PRESSED ;
				if(ProcessButton3() == 1){
					HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
				}
			}
		break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(2)){
				buttonState3 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(2) == 1){
					buttonState3 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
		break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(2)){
				buttonState3 = BUTTON_RELEASED;
			}
		break;
		}
	}
