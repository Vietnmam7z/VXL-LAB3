/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SEG2_1_Pin GPIO_PIN_13
#define SEG2_1_GPIO_Port GPIOC
#define SEG2_2_Pin GPIO_PIN_14
#define SEG2_2_GPIO_Port GPIOC
#define SEG2_3_Pin GPIO_PIN_15
#define SEG2_3_GPIO_Port GPIOC
#define SEG1_1_Pin GPIO_PIN_0
#define SEG1_1_GPIO_Port GPIOA
#define SEG1_2_Pin GPIO_PIN_1
#define SEG1_2_GPIO_Port GPIOA
#define SEG1_3_Pin GPIO_PIN_2
#define SEG1_3_GPIO_Port GPIOA
#define SEG1_4_Pin GPIO_PIN_3
#define SEG1_4_GPIO_Port GPIOA
#define SEG1_5_Pin GPIO_PIN_4
#define SEG1_5_GPIO_Port GPIOA
#define SEG1_6_Pin GPIO_PIN_5
#define SEG1_6_GPIO_Port GPIOA
#define SEG1_7_Pin GPIO_PIN_6
#define SEG1_7_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOA
#define Button_Pin GPIO_PIN_0
#define Button_GPIO_Port GPIOB
#define Button1_Pin GPIO_PIN_1
#define Button1_GPIO_Port GPIOB
#define Button2_Pin GPIO_PIN_2
#define Button2_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_10
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOB
#define TEST_Pin GPIO_PIN_12
#define TEST_GPIO_Port GPIOB
#define SEG2_5_Pin GPIO_PIN_14
#define SEG2_5_GPIO_Port GPIOB
#define SEG2_4_Pin GPIO_PIN_15
#define SEG2_4_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_9
#define LED3_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_10
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_11
#define LED5_GPIO_Port GPIOA
#define LED6_Pin GPIO_PIN_12
#define LED6_GPIO_Port GPIOA
#define LED7_Pin GPIO_PIN_13
#define LED7_GPIO_Port GPIOA
#define SEG2_6_Pin GPIO_PIN_14
#define SEG2_6_GPIO_Port GPIOA
#define SEG2_7_Pin GPIO_PIN_15
#define SEG2_7_GPIO_Port GPIOA
#define LED_RED_X_Pin GPIO_PIN_3
#define LED_RED_X_GPIO_Port GPIOB
#define LED_YELLOW_X_Pin GPIO_PIN_4
#define LED_YELLOW_X_GPIO_Port GPIOB
#define LED_GREEN_X_Pin GPIO_PIN_5
#define LED_GREEN_X_GPIO_Port GPIOB
#define LED_RED_Y_Pin GPIO_PIN_6
#define LED_RED_Y_GPIO_Port GPIOB
#define LED_YELLOW_Y_Pin GPIO_PIN_7
#define LED_YELLOW_Y_GPIO_Port GPIOB
#define LED_GREEN_Y_Pin GPIO_PIN_8
#define LED_GREEN_Y_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_9
#define EN0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
