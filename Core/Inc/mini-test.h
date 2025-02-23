#ifndef SIMPLE_TESTING_H
#define SIMPLE_TESTING_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "stm32f4xx_hal.h"
#include "usart.h"

#include "info_sequences.h"

#define MAX_TESTS 100

typedef void (*TestFunction)();

/**
 * USAGE:
 * To use this mini-test library do the following:
 * - Create a file tests, using TEST_ASSERT as needed
 * - Declare REGISTER_TESTS and use REGISTER_TEST to add all the tests that you want to run 
 * - Call either TEST_EXPECTED_PASS or TEST_EXPECTED_FAIL
 * - Observe the results from the serial terminal
 */
extern void REGISTER_TESTS(void);
__attribute__((always_inline)) static inline void REGISTER_TEST(TestFunction func, char a);

__attribute__((always_inline)) static inline void TEST_EXPECTED_PASS(void);
__attribute__((always_inline)) static inline void TEST_EXPECTED_FAIL(void);

__attribute__((always_inline)) inline void ASSERT_PASS(uint8_t *file, uint32_t line);
__attribute__((always_inline)) inline void ASSERT_FAIL(uint8_t *file, uint32_t line);
__attribute__((always_inline)) inline void TEST_ASSERT(uint8_t expr);
__attribute__((always_inline)) inline void NOTIFY_TEST_START(void);
__attribute__((always_inline)) inline void NOTIFY_TEST_END(void);

static TestFunction TEST_PASS_FUN[MAX_TESTS];
static TestFunction TEST_FAIL_FUN[MAX_TESTS];

static uint8_t pass_test_count = 0;
static uint8_t fail_test_count = 0;

static inline void TEST_EXPECTED_PASS(void) {
  // TODO add check to avoid running passing and failing tests at the same time
  NOTIFY_TEST_START();

  REGISTER_TESTS();

  for (int i = 0; i < MAX_TESTS; i++) {
    printf("Running test %d...\n", i + 1);
    TEST_PASS_FUN[i](); // Call the test function
  }

  NOTIFY_TEST_END();
}

static inline void TEST_EXPECTED_FAIL(void) {
  // TODO add check to avoid running passing and failing tests at the same time
  NOTIFY_TEST_START();

  REGISTER_TESTS();

  for (int i = 0; i < MAX_TESTS; i++) {
    printf("Running test %d...\n", i + 1);
    TEST_FAIL_FUN[i](); // Call the test function
  }

  NOTIFY_TEST_END();
}

// Inline function to register tests
static inline void REGISTER_TEST(TestFunction func, char a) {
  if (a == 'P' || a == 'p') {
    // Register in pass test array
    if (pass_test_count < MAX_TESTS) {
      TEST_PASS_FUN[pass_test_count++] = func;
    }
  } else if (a == 'F' || a == 'f') {
    // Register in fail test array
    if (fail_test_count < MAX_TESTS) {
      TEST_FAIL_FUN[fail_test_count++] = func;
    }
  }
}

inline void NOTIFY_TEST_START(void) {
  const char buffer[] = "\r\n---TESTING STARTING---\r\n";
  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

inline void NOTIFY_TEST_END(void) {
  const char buffer[] = "\r\n---TESTING ENDED---\r\n";
  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

inline void ASSERT_PASS(uint8_t *file, uint32_t line) {
  char buffer[100];
  snprintf(buffer, sizeof(buffer), "Pass: %s, line %lu\n", file, line);

  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

inline void ASSERT_FAIL(uint8_t *file, uint32_t line) {
  char buffer[100];
  snprintf(buffer, sizeof(buffer), "Fail: %s, line %lu\n", file, line);

  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

inline void TEST_ASSERT(uint8_t expr) {
  (expr) ? ASSERT_PASS((uint8_t *)__FILE__, __LINE__)
         : ASSERT_FAIL((uint8_t *)__FILE__, __LINE__);
}

#endif // SIMPLE_TESTING_H