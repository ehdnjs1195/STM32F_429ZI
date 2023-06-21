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
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
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
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
//printf를 사용하기 위해 _write() 함수를 재정의함.
int _write(int file, char *ptr, int len)
{
	HAL_UART_Transmit(&huart3, (uint8_t *)ptr, len, 500); //문자열을 보내는 것. 문자열의 주소를 받아서 문자열의 길이까지 같이 들어옴.

	return len;
}
int __io_putchar(int ch)
{
	HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 1000); //문자 하나를 보내는 것.
	return ch;
}

//scanf를 사용하기 위해 _read재정의
int _read(int file, char *ptr, int len)
{
	HAL_UART_Receive(&huart3, (unsigned char*)ptr, len, HAL_MAX_DELAY);
	return len;
}
int __io_getchar(void)
{
	uint8_t ch = 0;
	HAL_UART_Receive(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//segment 핀 번호 설정
uint16_t a = GPIO_PIN_2;
uint16_t b = GPIO_PIN_12;
uint16_t c = GPIO_PIN_5;
uint16_t d = GPIO_PIN_6;
uint16_t e = GPIO_PIN_3;
uint16_t f = GPIO_PIN_14;
uint16_t g = GPIO_PIN_15;

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

int cnt = 0;
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
  MX_USART3_UART_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();

//  HAL_UART_Receive_IT(&huart3, (uint8_t *)&cnt, 1); //UART 인터럽트 활성화를 메인에서 한번 해야함.
  /* USER CODE BEGIN 2 */
  //scanf를 사용하기 위해 버퍼를 만들어 주고, standard input/output header를 include 해주어야 한다. #include "stdio.h"
  char str[30];
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  //키보드로 문자를 입력하면 실행하고, 그 값 1바이트를 cnt에 저장하기
	  //폴링방식으로 timeout 시간 만큼 기다렸다가 버퍼가 차면
	  if(HAL_UART_Receive(&huart3, (uint8_t *)&cnt, 1, 3000) == HAL_OK)
	  {
		  if(cnt >= 48 && cnt <= 57 ) cnt -= 48;
		  else cnt = 0;
//		  cnt = atoi(str);
	  }

	  HAL_GPIO_WritePin(GPIOE, a, fnd[cnt][0]);
	  HAL_GPIO_WritePin(GPIOE, b, fnd[cnt][1]);
	  HAL_GPIO_WritePin(GPIOE, c, fnd[cnt][2]);
	  HAL_GPIO_WritePin(GPIOE, d, fnd[cnt][3]);
	  HAL_GPIO_WritePin(GPIOE, e, fnd[cnt][4]);
	  HAL_GPIO_WritePin(GPIOE, f, fnd[cnt][5]);
	  HAL_GPIO_WritePin(GPIOE, g, fnd[cnt][6]);
//	  HAL_UART_Transmit(&huart3, (uint8_t *)&cnt, 1, 1000);
	  printf("count : %d\r\n", cnt);
	  HAL_Delay(300);
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
  * @brief NVIC Configuration.2
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USART3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* EXTI15_10_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE5 PE6
                           PE12 PE14 PE15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13; //down btn
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PF14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14; //up btn
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart -> Instance == USART3)
	{
//		printf("UART콜백 호출");
//		HAL_UART_Receive(&huart3, (uint8_t *)&cnt, 1, 1000);
		HAL_UART_Receive_IT(&huart3, (uint8_t *)&cnt, 1); //cnt는 1바이트짜리 변수임을 말한다.
		if(cnt >= 48 && cnt <= 57 ) cnt -= 48;
		else cnt = 0;
		HAL_UART_Transmit(&huart3, (uint8_t *)&cnt, 1, 500);
//		if(HAL_UART_Receive(&huart3, (uint8_t *)&cnt, 1, 1000) == HAL_OK)
//	  {
//		  if(cnt >= 48 && cnt <= 57 ) cnt -= 48;
//		  else cnt = 0;
////		  cnt = atoi(str);
//	  }
	}
}

/* USER CODE BEGIN 4 */
//채터링을 제어하기 위한 변수
uint32_t start = 0;

//interrupt가 발생하면 실행되는 콜백함수. 재정의하여 사용함. 외부 인터럽트는 핀의 개수인 16개까지만 사용 가능. 각 핀마다 하나씩 작동함.
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//HAL_GetTick()은 프로그램이 실행되고 흐른 시간을 millisecond로 반환한다.
	//인터럽트가 발생하면 그 시간을 저장.
	uint32_t currentTime = HAL_GetTick();

	if(GPIO_Pin == GPIO_PIN_14) //UP Button
	{
		if(currentTime - start > 500) { //채터링에 의해 인터럽트가 발생하더라도 그 시간의 차이가 500ms보다 클때만 실행이 되도록 하여 채터링을 조절함.
			cnt++;
			start = currentTime;	//start 시간을 인터럽트가 발생한 시간으로 초기화해준다.
		}
		if(cnt > 9) cnt = 0;
	}
	if(GPIO_Pin == GPIO_PIN_13) //Down Button
	{
		if(currentTime - start > 500) {
			cnt--;
			start = currentTime;
		}
		if(cnt < 0) cnt = 9;
	}
}
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
