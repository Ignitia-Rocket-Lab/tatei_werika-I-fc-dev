#include "testing.h"
#include "info_sequences.h"

// Expected acceleration range (BNO055 range: ±16g, assuming raw values)
#define ACC_MIN_VALUE -16000
#define ACC_MAX_VALUE 16000

/**
 * Testing entry points for main.
 * NOTE: One one can be compiled at a time, given that success and failure cases
 * are mutually exclusive during execution and thus cannot be tested together.
 */

#ifdef RUN_SUCCESS_TESTS
int test_success(void) {
  HAL_Init();
  SystemClock_Config();
  MX_USART2_UART_Init();
  MX_I2C1_Init();

  blink_builtin_LED(LED_BLUE);

  UNITY_BEGIN();
  RUN_TEST(test_bno055_read_acc_x_success);
  RUN_TEST(test_bno055_read_acc_y_success);
  RUN_TEST(test_bno055_read_acc_z_success);
  return UNITY_END();
}

int test_failure(void) { return -1; }
#endif

#ifdef RUN_FAILURE_TESTS
int test_failure(void) {
  HAL_Init();
  SystemClock_Config();
  MX_USART2_UART_Init();
  MX_I2C1_Init();

  blink_builtin_LED(LED_GREEN);

  UNITY_BEGIN();
  RUN_TEST(test_bno055_read_acc_no_sensor);
  return UNITY_END();
}

int test_success(void) { return -1; }
#endif

/**
 * Testing BNO055 IMU library.
 */

// Test: Read accelerometer X-axis successfully
void test_bno055_read_acc_x_success(void) {
  uint16_t acc_x = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_x(&acc_x);

  TEST_ASSERT_EQUAL_INT(SUCCESS, ret);
  TEST_ASSERT_GREATER_OR_EQUAL_INT(ACC_MIN_VALUE, acc_x);
  TEST_ASSERT_LESS_OR_EQUAL_INT(ACC_MAX_VALUE, acc_x);
}

// Test: Read accelerometer Y-axis successfully
void test_bno055_read_acc_y_success(void) {
  uint16_t acc_y = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_y(&acc_y);

  TEST_ASSERT_EQUAL_INT(SUCCESS, ret);
  TEST_ASSERT_GREATER_OR_EQUAL_INT(ACC_MIN_VALUE, acc_y);
  TEST_ASSERT_LESS_OR_EQUAL_INT(ACC_MAX_VALUE, acc_y);
}

// Test: Read accelerometer Z-axis successfully
void test_bno055_read_acc_z_success(void) {
  uint16_t acc_z = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_z(&acc_z);

  TEST_ASSERT_EQUAL_INT(SUCCESS, ret);
  TEST_ASSERT_GREATER_OR_EQUAL_INT(ACC_MIN_VALUE, acc_z);
  TEST_ASSERT_LESS_OR_EQUAL_INT(ACC_MAX_VALUE, acc_z);
}

// Test: Read accelerometer when sensor is disconnected
void test_bno055_read_acc_no_sensor(void) {
  uint16_t acc_x = 0, acc_y = 0, acc_z = 0;

  TEST_ASSERT_EQUAL_INT(ERROR_DEFAULT, bno055_read_acc_x(&acc_x));
  TEST_ASSERT_EQUAL_INT(ERROR_DEFAULT, bno055_read_acc_y(&acc_y));
  TEST_ASSERT_EQUAL_INT(ERROR_DEFAULT, bno055_read_acc_z(&acc_z));
}