/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static GPIO_InitTypeDef  GPIO_InitStruct;
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

uint16_t a = GPIO_PIN_2;
uint16_t b = GPIO_PIN_4;
uint16_t c = GPIO_PIN_5;
uint16_t d = GPIO_PIN_6;
uint16_t e = GPIO_PIN_3;
uint16_t f = GPIO_PIN_14;
uint16_t g = GPIO_PIN_15;

void number0(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 0);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 1);
}
void number1(){
	HAL_GPIO_WritePin(GPIOE, a, 1);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 1);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 1);
	HAL_GPIO_WritePin(GPIOE, g, 1);
}
void number2(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 1);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 0);
	HAL_GPIO_WritePin(GPIOE, f, 1);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number3(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 1);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number4(){
	HAL_GPIO_WritePin(GPIOE, a, 1);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 1);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number5(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 1);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number6(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 1);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 0);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number7(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 1);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 1);
}
void number8(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 0);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void number9(){
	HAL_GPIO_WritePin(GPIOE, a, 0);
	HAL_GPIO_WritePin(GPIOE, b, 0);
	HAL_GPIO_WritePin(GPIOE, c, 0);
	HAL_GPIO_WritePin(GPIOE, d, 0);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 0);
	HAL_GPIO_WritePin(GPIOE, g, 0);
}
void numberVoid(){
	HAL_GPIO_WritePin(GPIOE, a, 1);
	HAL_GPIO_WritePin(GPIOE, b, 1);
	HAL_GPIO_WritePin(GPIOE, c, 1);
	HAL_GPIO_WritePin(GPIOE, d, 1);
	HAL_GPIO_WritePin(GPIOE, e, 1);
	HAL_GPIO_WritePin(GPIOE, f, 1);
	HAL_GPIO_WritePin(GPIOE, g, 1);
}
char fnd[10][7] = {
{0,0,0,0,0,0,1}, // 0
{1,0,0,1,1,1,1}, // 1
{0,0,1,0,0,1,0}, // 2
{0,0,0,0,1,1,0}, // 3
{1,0,0,1,1,0,0}, // 4
{0,1,0,0,1,0,0}, // 5
{0,1,0,0,0,0,0}, // 6
{0,0,0,1,1,0,1}, // 7
{0,0,0,0,0,0,0}, // 8
{0,0,0,0,1,0,0}  // 9
};
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
  /* USER CODE BEGIN 2 */
  __HAL_RCC_GPIOF_CLK_ENABLE(); //PF 활성화. UP button
  GPIO_InitStruct.Mode	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull	= GPIO_PULLUP; //pullup모드로 하면 스위치가 계속 눌려있는 상태라고 볼 수 있음.
  GPIO_InitStruct.Speed	= GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin	= GPIO_PIN_14;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  __HAL_RCC_GPIOC_CLK_ENABLE();	//PC 활성화 DOWN button
  GPIO_InitStruct.Mode	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull	= GPIO_PULLDOWN; //pullup모드로 하면 스위치가 계속 눌려있는 상태라고 볼 수 있음.
  GPIO_InitStruct.Speed	= GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin	= GPIO_PIN_13;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  __HAL_RCC_GPIOE_CLK_ENABLE(); //PE 활성화
  GPIO_InitStruct.Mode	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull	= GPIO_PULLUP; //pullup모드로 하면 스위치가 계속 눌려있는 상태라고 볼 수 있음.
  GPIO_InitStruct.Speed	= GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pin	= a|b|c|d|e|f|g;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  int cnt = 0;
  int i = 0;
  while (1)
  {
    /* USER CODE END WHILE */
	  if(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_14) == 0) {
		  i++;
		  if(i > 9) i = 0;
	  }
	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1) {
		  i--;
		  if(i < 0) i = 9;
	  }
	  //2차 배열로 출력하기.
	  HAL_GPIO_WritePin(GPIOE, a, fnd[i][0]);
	  HAL_GPIO_WritePin(GPIOE, b, fnd[i][1]);
	  HAL_GPIO_WritePin(GPIOE, c, fnd[i][2]);
	  HAL_GPIO_WritePin(GPIOE, d, fnd[i][3]);
	  HAL_GPIO_WritePin(GPIOE, e, fnd[i][4]);
	  HAL_GPIO_WritePin(GPIOE, f, fnd[i][5]);
	  HAL_GPIO_WritePin(GPIOE, g, fnd[i][6]);
	  HAL_Delay(300);

	  //함수 호출하여 출력하기
//	  switch(cnt){
//		  case 0:
//			  number0();
//			  HAL_Delay(500);
//			  break;
//		  case 1:
//			  number1();
//			  break;HAL_Delay(500);
//		  case 2:
//			  number2();
//			  HAL_Delay(500);
//			  break;
//		  case 3:
//			  number3();
//			  HAL_Delay(500);
//			  break;
//		  case 4:
//			  number4();
//			  HAL_Delay(500);
//			  break;
//		  case 5:
//			  number5();
//			  HAL_Delay(500);
//			  break;
//		  case 6:
//			  number6();
//			  HAL_Delay(500);
//			  break;
//		  case 7:
//			  number7();
//			  HAL_Delay(500);
//			  break;
//		  case 8:
//			  number8();
//			  HAL_Delay(500);
//			  break;
//		  case 9:
//			  number9();
//			  HAL_Delay(500);
//			  break;
//	  }
//
//	  if(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_14) == 0){
//		  cnt++;
//		  if(i > 10) i = 0;
//	  }
//	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1){
//		  cnt--;
//		  if(i < 0) i = 9;
//	  }

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOE_CLK_ENABLE();
//  __HAL_RCC_GPIOF_CLK_ENABLE();
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
//                          |GPIO_PIN_6|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
//
//  /*Configure GPIO pins : PE2 PE3 PE4 PE5
//                           PE6 PE14 PE15 */
//  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
//                          |GPIO_PIN_6|GPIO_PIN_14|GPIO_PIN_15;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
//
//  /*Configure GPIO pin : PF14 */
//  GPIO_InitStruct.Pin = GPIO_PIN_14;
//  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
