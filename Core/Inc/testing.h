#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>

#include "main.h"
#include "stm32f4xx_hal.h"
#include "usart.h"

#include "unity.h"

#define RUN_SUCCESS_TESTS

void test_main(void);

__weak void SystemClock_Config(void);
__weak void MX_I2C1_Init(void);

// Redefine fputc to output to a specific UART channel called TEST_RX/TX instead
// to whatever it would default to.

void custom_putchar(int c);

/**
 * Testing BNO055 IMU library.
 */

void test_bno055_read_acc_x_success(void);
void test_bno055_read_acc_y_success(void);
void test_bno055_read_acc_z_success(void);
void test_bno055_read_acc_no_sensor(void);

#endif // TESTING_H