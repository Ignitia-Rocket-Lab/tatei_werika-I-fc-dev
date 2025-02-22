#ifndef TESTING_H
#define TESTING_H

#include "main.h"
#include "stm32f4xx_hal.h"
#include "usart.h"

#include "unity.h"

#include <stdint.h>

#define RUN_SUCCESS_TESTS

__weak void SystemClock_Config(void);
__weak void MX_I2C1_Init(void);

// Redefine fputc to output to a specific UART channel called TEST_RX/TX instead
// to whatever it would default to.

#if defined(TEST_TX_GPIO_Port) && defined(TEST_TX_Pin)
void UnityOutputChar(int c) {
  char ch = (char)c;
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
}

void UnityOutputStart(void) {}
void UnityOutputComplete(void) {}

void setUp(void) {}
void tearDown(void) {}
#else
#error                                                                         \
    "Either TEST_TX_Pin or TEST_TX_GPIO_Port not defined, cannot print test outputs. Probably not compiling in test mode.
#endif

#if defined(RUN_SUCCESS_TESTS) || defined(RUN_FAILURE_TESTS)
int test_success(void);
int test_failure(void);
#else
#error                                                                         \
    "Define either RUN_SUCCESS_TESTS or RUN_FAILURE_TESTS in your compiler settings."
#endif

/**
 * Testing BNO055 IMU library.
 */
#include "BNO055.h"

void test_bno055_read_acc_x_success(void);
void test_bno055_read_acc_y_success(void);
void test_bno055_read_acc_z_success(void);
void test_bno055_read_acc_no_sensor(void);

#endif // TESTING_H