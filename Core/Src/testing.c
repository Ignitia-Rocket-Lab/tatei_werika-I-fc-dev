#include "testing.h"
#include "info_sequences.h"

#include "BNO055.h"

#if defined(TEST_TX_GPIO_Port) && defined(TEST_TX_Pin)
void custom_putchar(int c) {
  char ch = (char)c;
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
}

#undef UNITY_OUTPUT_CHAR
#define UNITY_OUTPUT_CHAR(a) (void)custom_putchar(a)

void UnityOutputStart(void) {}
void UnityOutputComplete(void) {}

void setUp(void) {}
void tearDown(void) {}

#else
#error                                                                         \
    "Either TEST_TX_Pin or TEST_TX_GPIO_Port not defined, cannot print test outputs. Probably not compiling in test mode."
#endif

// Expected acceleration range (BNO055 range: ±16g, assuming raw values)
#define ACC_MIN_VALUE -16000
#define ACC_MAX_VALUE 16000


/**
 * Testing entry points for main.
 * NOTE: One one can be compiled at a time, given that success and failure cases
 * are mutually exclusive during execution and thus cannot be tested together.
 */

void test_main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_USART2_UART_Init();
  MX_I2C1_Init();

  blink_builtin_LED(LED_BLUE);

  UNITY_BEGIN();
#ifdef RUN_SUCCESS_TESTS
  RUN_TEST(test_bno055_read_acc_x_success);
  RUN_TEST(test_bno055_read_acc_y_success);
  RUN_TEST(test_bno055_read_acc_z_success);
#elif defined(RUN_FAILURE_TESTS)
  RUN_TEST(test_bno055_read_acc_no_sensor);
#endif
  UNITY_END();
}

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