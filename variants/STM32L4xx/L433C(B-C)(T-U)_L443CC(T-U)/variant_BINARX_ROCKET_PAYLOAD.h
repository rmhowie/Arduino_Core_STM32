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
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pin numbers
 *----------------------------------------------------------------------------*/
// Digital Pins
#define PB10                    0        // LPUART1_RX
#define PB11                    1        // LPUART1_TX
#define PB12                    2        // SPI2_CS
#define PB13                    3        // SPI2_SCK
#define PB14                    4        // SPI2_POCI
#define PB15                    5        // SPI2_PICO
#define PA8                     6        // USER_SW
#define PA9                     7        // DEBUG_UART_TX
#define PA10                    8        // DEBUG_UART_RX
#define PA15                    9        // PA15
#define PB4                     10       // PB4
#define PB5                     11       // PB5
#define PB6                     12       // I2C1_SCL
#define PB7                     13       // I2C1_SDA
#define PB8                     14       // PB8
#define PB9                     15       // PB9
#define PB2                     16       // PB2
// Board Defined Functionality
#define PC13                    17       // CARD_DETECT
#define PH3                     18       // BOOT0
// Other Pins
#define PA11                    19       // USB_D_N
#define PA12                    20       // USB_D_P
#define PA13                    21       // SWDIO
#define PA14                    22       // SWCLK
#define PB3                     23       // SWO
#define PC14                    24       // OSC_32_IN
#define PC15                    25       // OSC_32_OUT
#define PH0                     26       // OSC_IN
#define PH1                     27       // OSC_OUT
// Analog Pins
#define PA0                     PIN_A0   // ADC1_IN5
#define PA1                     PIN_A1   // ADC1_IN6
#define PA2                     PIN_A2   // ADC1_IN7
#define PA3                     PIN_A3   // ADC1_IN8
#define PA4                     PIN_A4   // ADC1_IN9
#define PA5                     PIN_A5   // SPI1_SCK
#define PA6                     PIN_A6   // SPI1_POCI
#define PA7                     PIN_A7   // SPI1_PICO
#define PB0                     PIN_A8   // SPI1_CS
#define PB1                     PIN_A9   // PB1

// Alternate pins number //TODO RMH
#define PA1_ALT1                (PA1  | ALT1)
#define PA2_ALT1                (PA2  | ALT1)
#define PA3_ALT1                (PA3  | ALT1)
#define PA4_ALT1                (PA4  | ALT1)
#define PA6_ALT1                (PA6  | ALT1)
#define PA15_ALT1               (PA15 | ALT1)
#define PB1_ALT1                (PB1  | ALT1)
#define PB3_ALT1                (PB3  | ALT1)
#define PB4_ALT1                (PB4  | ALT1)
#define PB5_ALT1                (PB5  | ALT1)
#define PB13_ALT1               (PB13 | ALT1)
#define PB14_ALT1               (PB14 | ALT1)
#define PB15_ALT1               (PB15 | ALT1)

#define NUM_DIGITAL_PINS        38
#define NUM_ANALOG_INPUTS       10

// On-board LED pin number
// No controllable LED on board.
// #ifndef LED_BUILTIN
//   #define LED_BUILTIN           PA8
// #endif

// On-board user button
#ifndef USER_SW
  #define USER_SW              PA8
#endif

// Power switch ENABLE and DISCHARGE pins
// Not relevant to this board.
// #ifndef ENABLE_3V3
//   #define ENABLE_3V3            PH0
// #endif
// #ifndef DISCHARGE_3V3
//   #define DISCHARGE_3V3         PH1
//   #define DISABLE_DISCHARGING   HIGH
//   #define ENABLE_DISCHARGING    LOW
// #endif
// #ifndef CHARGE_DETECT
//   #define CHARGE_DETECT         PA15
// #endif

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PB1
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PA7
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PA6
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PA5
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB7
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB6
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM6
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM7
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  1
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PA10
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PA9
#endif

// LPUART1
#ifndef PIN_SERIAL_LP1_RX
  #define PIN_SERIAL_LP1_RX     PB10
#endif
#ifndef PIN_SERIAL_LP1_TX
  #define PIN_SERIAL_LP1_TX     PB11
#endif

// Extra HAL modules
#if !defined(HAL_DAC_MODULE_DISABLED)
  #define HAL_DAC_MODULE_ENABLED
#endif
#if !defined(HAL_QSPI_MODULE_DISABLED)
  #define HAL_QSPI_MODULE_ENABLED
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
