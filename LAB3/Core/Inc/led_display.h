/*
 * led_display.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Genki
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void Display7Seg1(int x);
void Display7Seg2(int x);
void Display7Seg3(int x);
void DisplayClock(int x);
void DisplayREDX(void);
void DisplayYELLOWX(void);
void DisplayGREENX(void);
void DisplayREDY(void);
void DisplayYELLOWY(void);
void DisplayGREENY(void);
void DisplayMAN_RED(void);
void DisplayMAN_GREEN(void);
void DisplayMAN_YELLOW(void);
void InitLED(void);
#endif /* INC_LED_DISPLAY_H_ */
