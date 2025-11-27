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

// RMH Todo lists below

// Digital PinName array
const PinName digitalPin[] = {
  PB_10,   // 0 - LPUART1_RX
  PB_11,   // 1 - LPUART1_TX
  PB_12,   // 2 - SPI2_CS
  PB_13,   // 3 - SPI2_SCK
  PB_14,   // 4 - SPI2_POCI
  PB_15,   // 5 - SPI2_PICO
  PA_8,   // 6 - USER_SW
  PA_9,   // 7 - DEBUG_UART_TX
  PA_10,   // 8 - DEBUG_UART_RX
  // RMH Todo lists below
  PB_14,  // 9 - D9
  PB_13,  // 10 - D10
  PB_0,   // 11 - D11
  PB_15,  // 12 - D12
  PB_4,   // 13 - D13
  PA_5,   // 14 - CK
  PA_6,   // 15 - MI
  PA_7,   // 16 - A5
  PA_9,   // 17 - TX
  PA_10,  // 18 - RX
  PA_11,  // 19 - USB_DM
  PA_12,  // 20 - USB_DP
  PA_13,  // 21 - SWDIO
  PA_14,  // 22 - SWCLK
  PA_15,  // 23 - CHARGE_DETECT
  PB_3,   // 24 - USB_DETECT
  PB_5,   // 25 - MO
  PB_6,   // 26 - SCL
  PB_7,   // 27 - SDA
  PB_10,  // 28 - LPUART1_VCP_RX
  PB_11,  // 29 - LPUART1_VCP_TX
  PC_13,  // 30 - USER_BTN
  PC_14,  // 31 - OSC32_IN
  PC_15,  // 32 - OSC32_OUT
  PH_0,   // 33 - ENABLE_3V3
  PH_1,   // 34 - DISCHARGE_3V3
  PH_3    // 35 - B
};

// Analog (Ax) to digital pin number array
const uint32_t analogInputPin[] = {
  0,  // PA0, A0
  1,  // PA1, A1
  2,  // PA2, A2
  3,  // PA3, A3
  4,  // PB1, A4
  16, // PA7, A5
  7   // PA4, BAT_VOLTAGE
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
