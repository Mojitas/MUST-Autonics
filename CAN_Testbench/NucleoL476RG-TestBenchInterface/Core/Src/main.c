/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "i2c-lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DEBUG_MODE 1 //When running in debug mode the nucleo sends some debug data on USART
#define SAMPLERATE 1

#define NUMBER_OF_SWITCHES 8

#define NO_SENSOR_MSG 0x100

#define VSCALER 3.0 / 3.3
#define TS_CAL1 *(uint16_t *)(0x1FFF75A8) * VSCALER
#define TS_CAL2 *(uint16_t *)(0x1FFF75CA) * VSCALER
//#define VREFINT *(uint16_t*)(0x1FFF75AA)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
uint16_t OwnID = 0x124;

uint16_t TEMP_1 = 0x101; //Sensor Description Here
uint16_t TEMP_2 = 0x102; //Sensor Description Here
uint16_t TEMP_3 = 0x103; //Sensor Description Here

//Switch State 1 or 0
GPIO_PinState SwitchStates[NUMBER_OF_SWITCHES]; //0:DRL 1:BlinkLeft 2:BlinkRight 3:Hazard 4:MC 5:SafeState 6:ForwardReverse 7:PowerEco
GPIO_PinState PreviousSwitchStates[NUMBER_OF_SWITCHES];

char message[8];
char sMsg[50];

float cpuTemp;
char LCDArray[2][17];

int selectModeActive = 0;
int rowIndex = 0;
int lcdCurrentSelection = 0;

/*
  0: Speed
  1: Power drain
  2: Battery Voltages
  3: Battery level
  4: Temperatures
 */

int lcdSelection1 = 0; //Default Selection
int lcdSelection2 = 1; //Default Selection

char dataPresets[5][17] = {"Speed           ", "Power drain     ", "Battery Voltage ", "Battery level   ", "Temperature     "};
char selectionText[17];

int8_t cruiseControl = 0;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

CAN_HandleTypeDef hcan1;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;

UART_HandleTypeDef huart2;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for cruiseControl */
osThreadId_t cruiseControlHandle;
const osThreadAttr_t cruiseControl_attributes = {
  .name = "cruiseControl",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 128 * 4
};
/* Definitions for ADC */
osThreadId_t ADCHandle;
const osThreadAttr_t ADC_attributes = {
  .name = "ADC",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_CAN1_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM16_Init(void);
static void MX_TIM17_Init(void);
void StartDefaultTask(void *argument);
void StartCruiseControl(void *argument);
void StartADC(void *argument);

/* USER CODE BEGIN PFP */
void serialMsg(char msg[]);
void HAL_CAN_RxFifo0FullCallBack(CAN_HandleTypeDef *hcan);
void CAN_filterConfig(void);
void CAN_Tx(char msg[], CAN_TxHeaderTypeDef TxHeader);
void CAN_Rx(void);
void ReceiveSensorData(uint32_t sensorId, float data);
void LcdSendString(int8_t row, char string[]);

float get_Temp(int16_t variable);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_CAN1_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_TIM16_Init();
  MX_TIM17_Init();
  /* USER CODE BEGIN 2 */
	//Init LCD array
	/*
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			LCDArray[i][j] = ' ';
		}
	}*/

	lcd_init();

	lcd_send_string("LCD Init");

	HAL_Delay(1000);

	lcd_clear();
	HAL_Delay(500);
	serialMsg("LCD Nucleo init\r\n");
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of cruiseControl */
  cruiseControlHandle = osThreadNew(StartCruiseControl, NULL, &cruiseControl_attributes);

  /* creation of ADC */
  ADCHandle = osThreadNew(StartADC, NULL, &ADC_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_ADC;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV8;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV64;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.NbrOfConversion = 2;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 40;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */
	CAN_filterConfig();
  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10909CEC;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 8000-1;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 5000-1;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief TIM17 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM17_Init(void)
{

  /* USER CODE BEGIN TIM17_Init 0 */

  /* USER CODE END TIM17_Init 0 */

  /* USER CODE BEGIN TIM17_Init 1 */

  /* USER CODE END TIM17_Init 1 */
  htim17.Instance = TIM17;
  htim17.Init.Prescaler = 8000-1;
  htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim17.Init.Period = 5000-1;
  htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim17.Init.RepetitionCounter = 0;
  htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM17_Init 2 */

  /* USER CODE END TIM17_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|BlinkRightLED_Pin|DRLLED_Pin|MCLED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, SafeStateLED_Pin|BrakeLED_Pin|BlinkLeftLED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD2_Pin BlinkRightLED_Pin DRLLED_Pin MCLED_Pin */
  GPIO_InitStruct.Pin = LD2_Pin|BlinkRightLED_Pin|DRLLED_Pin|MCLED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SwitchDRL_Pin SwitchBlinkLeft_Pin */
  GPIO_InitStruct.Pin = SwitchDRL_Pin|SwitchBlinkLeft_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SwitchBlinkRight_Pin SwitchHazardLights_Pin */
  GPIO_InitStruct.Pin = SwitchBlinkRight_Pin|SwitchHazardLights_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : SwitchMC_Pin SwitchSafeState_Pin SwitchForwardReverse_Pin SwitchPowerEco_Pin */
  GPIO_InitStruct.Pin = SwitchMC_Pin|SwitchSafeState_Pin|SwitchForwardReverse_Pin|SwitchPowerEco_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : ButtonLCDMenuSelect_Pin ButtonLCDMenuDown_Pin ButtonLCDMenuUp_Pin */
  GPIO_InitStruct.Pin = ButtonLCDMenuSelect_Pin|ButtonLCDMenuDown_Pin|ButtonLCDMenuUp_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : ButtonCruiseControll_Pin */
  GPIO_InitStruct.Pin = ButtonCruiseControll_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(ButtonCruiseControll_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SafeStateLED_Pin BrakeLED_Pin BlinkLeftLED_Pin */
  GPIO_InitStruct.Pin = SafeStateLED_Pin|BrakeLED_Pin|BlinkLeftLED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

//Send message on USART2 (USB 115200)
void serialMsg(char msg[])
{
	HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);
}

void CAN_Tx(char msg[], CAN_TxHeaderTypeDef TxHeader)
{

	if (sizeof(*msg) <= 8)
	{
		uint32_t TxMailBox; //Outgoing mail box

		if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, (uint8_t *)msg, &TxMailBox) != HAL_OK)
		{
			Error_Handler();
		}

		while (HAL_CAN_IsTxMessagePending(&hcan1, TxMailBox)); //Wait for message to be sent.
			  //serialMsg("Message transmitted!\n\r");//Debug
	}
	else
	{
		//Throw ERROR "CAN Packet size to large"
		if (DEBUG_MODE)
		{
			serialMsg("CAN Packet size to large. Packet size ");
			serialMsg((char *)sizeof(*msg));
			serialMsg(" Bytes.\n\r");
		}
	}
}

void CAN_Rx(void)
{

	uint8_t receivedData[8];
	RxHeader.DLC = 8;			 //Specifies the length of the frame that will be received.
	RxHeader.IDE = CAN_ID_STD;	 //Specifies the type of identifier for the message that will be received.
	RxHeader.RTR = CAN_RTR_DATA; //Specifies the type of frame for the message that will be received.
	RxHeader.StdId = 0x0;		 //Specifies the standard identifier. Has no use when receiving.

	//Receive the messsage
	if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, receivedData) != HAL_OK)
	{
		Error_Handler();
		return;
	}
	if (RxHeader.ExtId != 0x100)
	{
		ReceiveSensorData(RxHeader.ExtId, (float)atof((char *)receivedData));
	}

	HAL_Delay(1);
	if (DEBUG_MODE)
	{
		serialMsg("Received message: ");
		serialMsg((char *)receivedData);
		serialMsg("\n\r");
	}
}

void CAN_filterConfig(void)
{
	CAN_FilterTypeDef filterConfig;
	filterConfig.FilterBank = 0;						  //Specifies the filter bank which will be initialized.
	filterConfig.FilterActivation = ENABLE;				  //Enable or disable the filter.
	filterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0; //Specifies the FIFO (0 or 1U) which will be assigned to the filter.
	filterConfig.FilterIdHigh = 0x0000;					  //Specifies the filter identification number.
	filterConfig.FilterIdLow = 0x0000;					  //Specifies the filter identification number.
	filterConfig.FilterMaskIdHigh = 0x0000;				  //Specifies the filter mask number or identification number, according to the mode.
	filterConfig.FilterMaskIdLow = 0x0000;				  //Specifies the filter mask number or identification number, according to the mode.
	filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;	  //Specifies the filter mode to be initialized.
	filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;	  //Specifies the filter scale.

	HAL_CAN_ConfigFilter(&hcan1, &filterConfig);
}

void ReadSensorValues(void)
{
	//uint16_t value1 = GetRandomuint16();
	//uint16_t value2 = GetRandomuint16();
	//uint16_t value3 = GetRandomuint16();
}

int GetRandomInt(int max)
{
	return (int)rand() % max;
}
//Update LCD values
void UpdateLCDValues(void)
{
	if (selectModeActive == 0)
	{

		switch (lcdSelection1)
		//First row
		{
		case 0:
			sprintf(LCDArray[0], "Vel:%3ikm/h", GetRandomInt(110));
			break;
		case 1:
			sprintf(LCDArray[0], "Power Cons:%4iW", GetRandomInt(2000));
			break;
		case 2:
			sprintf(LCDArray[0], "Bat Volt:%3iV", GetRandomInt(120));
			break;
		case 3:
			sprintf(LCDArray[0], "Bat Level:%3i%%", GetRandomInt(100));
			break;
		case 4:
			sprintf(LCDArray[0], "Temp:%2iC", (int)cpuTemp);
			break;
		}
		//Second row
		switch (lcdSelection2)
		{
		case 0:
			sprintf(LCDArray[1], "Vel:%3ikm/h", GetRandomInt(110));
			break;
		case 1:
			sprintf(LCDArray[1], "Power Cons:%4iW", GetRandomInt(2000));
			break;
		case 2:
			sprintf(LCDArray[1], "Bat Volt:%3iV", GetRandomInt(120));
			break;
		case 3:
			sprintf(LCDArray[1], "Bat Level:%3i%%", GetRandomInt(100));
			break;
		case 4:
			sprintf(LCDArray[1], "Temp:%2iC", (int)cpuTemp);
			break;
		}
	}
	else //Display Values from Select Mode
	{

		memcpy(LCDArray[0], selectionText, strlen(selectionText));
		memcpy(LCDArray[1], dataPresets[lcdCurrentSelection], strlen(dataPresets[lcdCurrentSelection]));
	}
}

//Draw whatever is in the LCDArray
void DrawLCD(void)
{
	LcdSendString(0, LCDArray[0]);
	LcdSendString(1, LCDArray[1]);
}

void LcdSendString(int8_t row, char *string)
{
	sprintf(string, "%-16s", string);
	lcd_put_cur(row, 0);
	HAL_Delay(2);
	lcd_send_string(string);
	HAL_Delay(2);
}

//Reads and saves Switch states
void ReadSwitchStates()
{
	for (int8_t i = 0; i < NUMBER_OF_SWITCHES; i++)
	{
		PreviousSwitchStates[i] = SwitchStates[i];
	}
	SwitchStates[0] = HAL_GPIO_ReadPin(SwitchDRL_GPIO_Port, SwitchDRL_Pin);
	SwitchStates[1] = HAL_GPIO_ReadPin(SwitchBlinkLeft_GPIO_Port, SwitchBlinkLeft_Pin);
	SwitchStates[2] = HAL_GPIO_ReadPin(SwitchBlinkRight_GPIO_Port, SwitchBlinkRight_Pin);
	SwitchStates[3] = HAL_GPIO_ReadPin(SwitchHazardLights_GPIO_Port, SwitchHazardLights_Pin);
	SwitchStates[4] = HAL_GPIO_ReadPin(SwitchMC_GPIO_Port, SwitchMC_Pin);
	SwitchStates[5] = HAL_GPIO_ReadPin(SwitchSafeState_GPIO_Port, SwitchSafeState_Pin);
	SwitchStates[6] = HAL_GPIO_ReadPin(SwitchForwardReverse_GPIO_Port, SwitchForwardReverse_Pin);
	SwitchStates[7] = HAL_GPIO_ReadPin(SwitchPowerEco_GPIO_Port, SwitchPowerEco_Pin);

	for (int8_t i = 0; i < NUMBER_OF_SWITCHES; i++)
	{
		if (PreviousSwitchStates[i] != SwitchStates[i])
		{
			SwitchStateChanged(i, SwitchStates[i]);
		}
	}
}

void SwitchStateChanged(int8_t switchId, GPIO_PinState newState)
{
	if (DEBUG_MODE)
	{
		if (newState == GPIO_PIN_SET)
		{
			sprintf(sMsg, "Switch id: %i, changed state to: HIGH\n\r", switchId);
		}
		else
		{
			sprintf(sMsg, "Switch id: %i, changed state to: LOW\n\r", switchId);
		}
		serialMsg(sMsg);
	}

	switch (switchId)
	{
	case 0: //DRL
		SetDRLLED(newState);
		break;
	case 1: //BlinkLeft
		if (newState == GPIO_PIN_SET)
		{
			HAL_TIM_Base_Start_IT(&htim17);
		}
		else
		{
			HAL_TIM_Base_Stop_IT(&htim17);
			HAL_GPIO_WritePin(BlinkLeftLED_GPIO_Port, BlinkLeftLED_Pin, GPIO_PIN_RESET);
		}

		break;
	case 2: //BlinkRight
		if (newState == GPIO_PIN_SET)
		{
			HAL_TIM_Base_Start_IT(&htim16);
		}
		else
		{
			HAL_TIM_Base_Stop_IT(&htim16);
			HAL_GPIO_WritePin(BlinkRightLED_GPIO_Port, BlinkRightLED_Pin, GPIO_PIN_RESET);
		}
		break;
	case 3: //HazardLights
		if (newState == GPIO_PIN_SET)
		{
			HAL_TIM_Base_Start_IT(&htim17);
			HAL_TIM_Base_Start_IT(&htim16);
		}
		else
		{
			HAL_TIM_Base_Stop_IT(&htim17);
			HAL_TIM_Base_Stop_IT(&htim16);
			HAL_GPIO_WritePin(BlinkLeftLED_GPIO_Port, BlinkLeftLED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(BlinkRightLED_GPIO_Port, BlinkRightLED_Pin, GPIO_PIN_RESET);
		}
		break;
	case 4: //MC
		SetMCLED(newState);
		break;
	case 5: //SafeState
		if (newState == GPIO_PIN_SET)
		{
			//Enter safe state
			SetSafeStateLED(newState);
		}
		else
		{
			//Allow return from safe state
		}
		break;
	case 6: //ForwardReverse
		if (newState == GPIO_PIN_SET)
		{
			//Put motor in Reverse
			//SetForwardReverseLED(newState);
		}
		else
		{
			//Put motor in Forward
			//SetForwardReverseLED(newState);
		}
		break;
	case 7: //PowerEco
		if (newState == GPIO_PIN_SET)
		{
			//Set car in Eco mode
		}
		else
		{
			//Set car in Power mode
		}
		break;
	}
}

void ButtonCruiseControll()
{
	if (!cruiseControl)
		cruiseControl = 1; //Start Cruise Control
	else
		cruiseControl = 0; //End Cruise Control
}
void ButtonReset()
{
	//Restart Nucleo Safe
	//if(car in idle state)
	//Reset();
}
void ButtonLCDMenuUp()
{
	lcdCurrentSelection = (5 + lcdCurrentSelection - 1) % 5;
}
void ButtonLCDMenuDown()
{
	lcdCurrentSelection = (lcdCurrentSelection + 1) % 5;
}
void ButtonLCDMenuSelect()
{
	if (selectModeActive)
	{
		if (rowIndex == 1)
		{
			lcdSelection1 = lcdCurrentSelection;
			rowIndex = 2;
			lcdCurrentSelection = lcdSelection2;
			sprintf(selectionText, "Display Row:%i   ", rowIndex);
		}
		else if (rowIndex == 2)
		{
			lcdSelection2 = lcdCurrentSelection;
			selectModeActive = 0;
			if (DEBUG_MODE)
			{
				sprintf(sMsg, "LCD Selection %i : %i\n\r", lcdSelection1, lcdSelection2);
				serialMsg(sMsg);
			}
		}
	}
	else
	{
		selectModeActive = 1;
		rowIndex = 1;
		lcdCurrentSelection = lcdSelection1;
		sprintf(selectionText, "Display Row:%i   ", rowIndex);
	}
}
//Set
void SetDRLLED(GPIO_PinState pinState)
{
	HAL_GPIO_WritePin(DRLLED_GPIO_Port, DRLLED_Pin, pinState);
}

void SetMCLED(GPIO_PinState pinState)
{
	HAL_GPIO_WritePin(MCLED_GPIO_Port, MCLED_Pin, pinState);
}
void SetSafeStateLED(GPIO_PinState pinState)
{
	HAL_GPIO_WritePin(SafeStateLED_GPIO_Port, SafeStateLED_Pin, pinState);
}

void SetForwardReverseLED(GPIO_PinState pinState)
{
	//HAL_GPIO_WritePin(ForwardReverseLED_GPIO_Port, ForwardReverseLED_Pin, pinState);
}

//Toggle
void ToggleHazzardLED()
{
	HAL_GPIO_TogglePin(BlinkRightLED_GPIO_Port, BlinkRightLED_Pin);
	HAL_GPIO_TogglePin(BlinkLeftLED_GPIO_Port, BlinkLeftLED_Pin);
}
void ToggleDRLLED()
{
	HAL_GPIO_TogglePin(DRLLED_GPIO_Port, DRLLED_Pin);
}
void ToggleBlinkRightLED()
{
	HAL_GPIO_TogglePin(BlinkRightLED_GPIO_Port, BlinkRightLED_Pin);
}
void ToggleBlinkLeftLED()
{
	HAL_GPIO_TogglePin(BlinkLeftLED_GPIO_Port, BlinkLeftLED_Pin);
}
void ToggleBrakeLED()
{
	HAL_GPIO_TogglePin(BrakeLED_GPIO_Port, BrakeLED_Pin);
}
void ToggleMCLED()
{
	HAL_GPIO_TogglePin(MCLED_GPIO_Port, MCLED_Pin);
}
void ToggleSafeStateLED()
{
	HAL_GPIO_TogglePin(SafeStateLED_GPIO_Port, SafeStateLED_Pin);
}
void ToggleForwardReverseLED()
{
	//HAL_GPIO_TogglePin(ForwardReverseLED_GPIO_Port, ForwardReverseLED_Pin);
}
void TogglePowerEcoLED()
{
	//HAL_GPIO_TogglePin(PowerEcoLED_GPIO_Port, PowerEcoLED_Pin);
}
void ToggleOnOffLED()
{
	//HAL_GPIO_TogglePin(OnOffLED_GPIO_Port, OnOffLED_Pin);
}

// Convert ADC reading to temperature
float get_Temp(int16_t variable)
{
	// Values from datasheet and internal calibration registers
	float k = (110.f - 30.f) / ((TS_CAL2 - TS_CAL1));
	float temp = k * (variable - TS_CAL1) + 30;
	return temp;
}

// Read the ADC values in the DMA
uint32_t adc_val[2], adc_buf[2];
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{

	for (int i = 0; i < 2; i++)
	{
		adc_val[i] = adc_buf[i]; // store the values in adc_val from buffer
	}
}

void SendSensorData(uint16_t sensorId, float data)
{
	char sensorData[9];
	CAN_TxHeaderTypeDef TxHeader;
	TxHeader.DLC = 8;			 //Specifies the length of the frame that will be transmitted.
	TxHeader.IDE = CAN_ID_STD;	 //Specifies the type of identifier for the message that will be transmitted.
	TxHeader.RTR = CAN_RTR_DATA; //Specifies the type of frame for the message that will be transmitted.
	TxHeader.StdId = OwnID;		 //Specifies the standard identifier.
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.ExtId = sensorId; //Specifies the extended identifier.

	sprintf(sensorData, "%06f", data);
	CAN_Tx(sensorData, TxHeader);
}

void ReceiveSensorData(uint32_t sensorId, float data)
{
	char s_data[20];
	if(sensorId == TEMP_1){
		sprintf(s_data, "T1: %f C", data);
		serialMsg(s_data);
	}
	else if(sensorId == TEMP_2){
		sprintf(s_data, "T2: %f C", data);
		serialMsg(s_data);
	}
	else if(sensorId == TEMP_3){
		sprintf(s_data, "T3: %f C", data);
		serialMsg(s_data);
	}
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;)
	{
		UpdateLCDValues();
		DrawLCD();
		ReadSwitchStates();
		osDelay(500);
	}
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartCruiseControl */
/**
 * @brief Function implementing the cruiseControl thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartCruiseControl */
void StartCruiseControl(void *argument)
{
  /* USER CODE BEGIN StartCruiseControl */
	/* Infinite loop */
	for (;;)
	{
		osDelay(100);
		if (cruiseControl)
		{
			//initial code here
			while (cruiseControl)
			{
				//continus code here
				osDelay(100);
			}
			//end of loop code here
		}
	}
  /* USER CODE END StartCruiseControl */
}

/* USER CODE BEGIN Header_StartADC */
/**
 * @brief Function implementing the ADC thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartADC */
void StartADC(void *argument)
{
  /* USER CODE BEGIN StartADC */
	HAL_ADC_Stop(&hadc1);
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	osDelay(10);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buf, 2); // start adc in DMA mode
	//HAL_ADC_Start_IT (&hadc1);

	/* Infinite loop */
	for (;;)
	{
		cpuTemp = get_Temp((int16_t)adc_val[0]);
		osDelay(100);
	}
  /* USER CODE END StartADC */
}

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
	if (htim == &htim16)
	{
		ToggleBlinkRightLED();
	}
	if (htim == &htim17)
	{
		ToggleBlinkLeftLED();
	}
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
