/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

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

void ReadSensorValues(void);
void UpdateLCDValues(void);
void DrawLCD(void);

int GetRandomInt(int max);

//Buttons
void ButtonCruiseControll(void);
void ButtonReset(void);
void ButtonLCDMenuUp(void);
void ButtonLCDMenuDown(void);
void ButtonLCDMenuSelect(void);

//LED Toggle
void ToggleHazardLED();
void ToggleDRLLED();
void ToggleBlinkRightLED();
void ToggleBlinkLeftLED();
void ToggleBrakeLED();
void ToggleMCLED();
void ToggleSafeStateLED();
void ToggleForwardReverseLED();
void TogglePowerEcoLED();
void ToggleOnOffLED();

//LED Set
void SetDRLLED(GPIO_PinState pinState);
void SetMCLED(GPIO_PinState pinState);
void SetSafeStateLED(GPIO_PinState pinState);

void SwitchStateChanged(int8_t switchId, GPIO_PinState newState);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_POT1_Pin GPIO_PIN_0
#define ADC_POT1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define SwitchDRL_Pin GPIO_PIN_6
#define SwitchDRL_GPIO_Port GPIOA
#define SwitchBlinkLeft_Pin GPIO_PIN_7
#define SwitchBlinkLeft_GPIO_Port GPIOA
#define SwitchBlinkRight_Pin GPIO_PIN_4
#define SwitchBlinkRight_GPIO_Port GPIOC
#define SwitchHazardLights_Pin GPIO_PIN_5
#define SwitchHazardLights_GPIO_Port GPIOC
#define SwitchMC_Pin GPIO_PIN_0
#define SwitchMC_GPIO_Port GPIOB
#define SwitchSafeState_Pin GPIO_PIN_1
#define SwitchSafeState_GPIO_Port GPIOB
#define SwitchForwardReverse_Pin GPIO_PIN_2
#define SwitchForwardReverse_GPIO_Port GPIOB
#define SwitchPowerEco_Pin GPIO_PIN_10
#define SwitchPowerEco_GPIO_Port GPIOB
#define ButtonLCDMenuSelect_Pin GPIO_PIN_13
#define ButtonLCDMenuSelect_GPIO_Port GPIOB
#define ButtonLCDMenuSelect_EXTI_IRQn EXTI15_10_IRQn
#define ButtonLCDMenuDown_Pin GPIO_PIN_14
#define ButtonLCDMenuDown_GPIO_Port GPIOB
#define ButtonLCDMenuDown_EXTI_IRQn EXTI15_10_IRQn
#define ButtonLCDMenuUp_Pin GPIO_PIN_15
#define ButtonLCDMenuUp_GPIO_Port GPIOB
#define ButtonLCDMenuUp_EXTI_IRQn EXTI15_10_IRQn
#define ButtonCruiseControll_Pin GPIO_PIN_6
#define ButtonCruiseControll_GPIO_Port GPIOC
#define ButtonCruiseControll_EXTI_IRQn EXTI9_5_IRQn
#define SafeStateLED_Pin GPIO_PIN_7
#define SafeStateLED_GPIO_Port GPIOC
#define BrakeLED_Pin GPIO_PIN_8
#define BrakeLED_GPIO_Port GPIOC
#define BlinkLeftLED_Pin GPIO_PIN_9
#define BlinkLeftLED_GPIO_Port GPIOC
#define BlinkRightLED_Pin GPIO_PIN_8
#define BlinkRightLED_GPIO_Port GPIOA
#define DRLLED_Pin GPIO_PIN_9
#define DRLLED_GPIO_Port GPIOA
#define MCLED_Pin GPIO_PIN_10
#define MCLED_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
