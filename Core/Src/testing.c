#include "mini-test.h"

#include "BNO055.h"

/**
 * Testing BNO055 IMU library.
 */

void TEST_bno055_read_acc_x_success(void);
void TEST_bno055_read_acc_y_success(void);
void TEST_bno055_read_acc_z_success(void);
void TEST_bno055_read_acc_no_sensor(void);

/**
 * Register ALL tests to be run.
 * Use P/p for tests that are expected to pass.
 * Use F/f for tests that are expected to fail.
 */
void REGISTER_TESTS(void) {
  REGISTER_TEST(TEST_bno055_read_acc_x_success, 'P');
  REGISTER_TEST(TEST_bno055_read_acc_y_success, 'P');
  REGISTER_TEST(TEST_bno055_read_acc_z_success, 'P');

  REGISTER_TEST(TEST_bno055_read_acc_no_sensor, 'F');
}

/**
 * Testing BNO055 IMU library.
 */

// Expected acceleration range (BNO055 range: ±16g, assuming raw values)
#define ACC_MAX_VALUE 16000

// Test: Read accelerometer X-axis successfully
void TEST_bno055_read_acc_x_success(void) {
  uint16_t acc_x = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_x(&acc_x);

  TEST_ASSERT(SUCCESS == ret);
  TEST_ASSERT(acc_x <= ACC_MAX_VALUE);
}

// Test: Read accelerometer Y-axis successfully
void TEST_bno055_read_acc_y_success(void) {
  uint16_t acc_y = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_y(&acc_y);

  TEST_ASSERT(SUCCESS == ret);
  TEST_ASSERT(acc_y <= ACC_MAX_VALUE);
}

// Test: Read accelerometer Z-axis successfully
void TEST_bno055_read_acc_z_success(void) {
  uint16_t acc_z = 0;
  BNO055_FUNC_RETURN ret = bno055_read_acc_z(&acc_z);

  TEST_ASSERT(SUCCESS == ret);
  TEST_ASSERT(acc_z <= ACC_MAX_VALUE);
}

// Test: Read accelerometer when sensor is disconnected
void TEST_bno055_read_acc_no_sensor(void) {
  uint16_t acc_x = 0, acc_y = 0, acc_z = 0;

  TEST_ASSERT(ERROR_DEFAULT == bno055_read_acc_x(&acc_x));
  TEST_ASSERT(ERROR_DEFAULT == bno055_read_acc_y(&acc_y));
  TEST_ASSERT(ERROR_DEFAULT == bno055_read_acc_z(&acc_z));
}
