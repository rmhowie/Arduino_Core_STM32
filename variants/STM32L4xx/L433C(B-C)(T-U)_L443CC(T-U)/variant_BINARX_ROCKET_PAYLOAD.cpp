/*
 *******************************************************************************
 * Copyright (c) 2020, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#if defined(ARDUINO_BINARX_ROCKET_PAYLOAD)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  PB_10,   // 0 - LPUART1_RX
  PB_11,   // 1 - LPUART1_TX
  PB_12,   // 2 - SPI2_CS
  PB_13,   // 3 - SPI2_SCK
  PB_14,   // 4 - SPI2_POCI
  PB_15,   // 5 - SPI2_PICO
  PA_8,    // 6 - USER_SW
  PA_9,    // 7 - DEBUG_UART_TX
  PA_10,   // 8 - DEBUG_UART_RX
  PA_15,   // 9 - D9
  PB_4,    // 10 - D10
  PB_5,    // 11 - D11
  PB_6,    // 12 - I2C1_SCL
  PB_7,    // 13 - I2C1_SDA
  PB_8,    // 14 - PB8
  PB_9,    // 15 - PB9
  PB_2,    // 16 - PB2
  PC_13,   // 17 - CARD_DETECT
  PH_3,    // 18 - BOOT0
  PA_11,   // 19 - USB_D_N
  PA_12,   // 20 - USB_D_P
  PA_13,   // 21 - SWDIO
  PA_14,   // 22 - SWCLK
  PB_3,    // 23 - SWO
  PC_14,   // 24 - OSC_32_IN
  PC_15,   // 25 - MOSC_32_OUT
  PH_0,    // 26 - OSC_IN
  PH_1,    // 27 - OSC_OUT
  PA_0,    // 28 - ADC1_IN5
  PA_1,    // 29 - ADC1_IN6
  PA_2,    // 30 - ADC1_IN7
  PA_3,    // 31 - ADC1_IN8
  PA_4,    // 32 - ADC1_IN9
  PA_5,    // 33 - SPI1_SCK
  PA_6,    // 34 - SPI1_POCI
  PA_7,    // 35 - SPI1_PICO
  PB_0,    // 34 - SPI1_CS
  PB_1     // 35 - PB1
};

// Analog (Ax) to digital pin number array
const uint32_t analogInputPin[] = {
  28,  // PA0, ADC1_IN5,  A0
  29,  // PA1, ADC1_IN6,  A1
  30,  // PA2, ADC1_IN7,  A2
  31,  // PA3, ADC1_IN8,  A3
  32,  // PA4, ADC1_IN9,  A4
  33,  // PA5, SPI1_SCK,  A5
  34,  // PA6, SPI1_POCI, A6
  35,  // PA7, SPI1_PICO, A7
  36,  // PB0, SPI1_CS,   A8
  37   // PB1, PB1,       A9
};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

// WEAK void initVariant(void)
// {
  
// }

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
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
}

#ifdef __cplusplus
}
#endif

#endif /* BINARX_ROCKET_PAYLOAD */
