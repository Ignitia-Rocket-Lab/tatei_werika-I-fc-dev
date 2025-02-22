/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stm32f411xe.h"

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
#define BUILTIN_BLUE_LED_Pin GPIO_PIN_13
#define BUILTIN_BLUE_LED_GPIO_Port GPIOC
#define TPU_MOSI_Pin GPIO_PIN_3
#define TPU_MOSI_GPIO_Port GPIOC
#define BATTERY_VOLT_Pin GPIO_PIN_1
#define BATTERY_VOLT_GPIO_Port GPIOA
#define DEBUG_TX_Pin GPIO_PIN_2
#define DEBUG_TX_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_3
#define DEBUG_RX_GPIO_Port GPIOA
#define BUILTIN_GREEN_LED_Pin GPIO_PIN_5
#define BUILTIN_GREEN_LED_GPIO_Port GPIOA
#define TPU_SCK_Pin GPIO_PIN_10
#define TPU_SCK_GPIO_Port GPIOB
#define BAR_SCK_Pin GPIO_PIN_12
#define BAR_SCK_GPIO_Port GPIOB
#define BAR_CS_Pin GPIO_PIN_13
#define BAR_CS_GPIO_Port GPIOB
#define PYRO1_Pin GPIO_PIN_8
#define PYRO1_GPIO_Port GPIOC
#define PYRO0_Pin GPIO_PIN_9
#define PYRO0_GPIO_Port GPIOC
#define EXT_LED0_Pin GPIO_PIN_9
#define EXT_LED0_GPIO_Port GPIOA
#define EXT_LED1_Pin GPIO_PIN_10
#define EXT_LED1_GPIO_Port GPIOA
#define EXT_LED2_Pin GPIO_PIN_11
#define EXT_LED2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define TEST_TX_Pin GPIO_PIN_15
#define TEST_TX_GPIO_Port GPIOA
#define BAR_MISO_Pin GPIO_PIN_11
#define BAR_MISO_GPIO_Port GPIOC
#define BAR_MOSI_Pin GPIO_PIN_12
#define BAR_MOSI_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define IMU_RST_Pin GPIO_PIN_5
#define IMU_RST_GPIO_Port GPIOB
#define IMU_SCL_Pin GPIO_PIN_6
#define IMU_SCL_GPIO_Port GPIOB
#define TEST_RX_Pin GPIO_PIN_7
#define TEST_RX_GPIO_Port GPIOB
#define IMU_SDA_Pin GPIO_PIN_9
#define IMU_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
