#include "mini-test.h"

#include "BNO055.h"
#include "i2c.h"

/**
 * Testing BNO055 IMU library.
 */

void TEST_bno055_determine_address(void);

void TEST_bno055_read_acc_x_success(void);
void TEST_bno055_read_acc_y_success(void);
void TEST_bno055_read_acc_z_success(void);

void TEST_bno055_read_acc_no_sensor(void);

/**
 * Register ALL tests to be run.
 */
void REGISTER_TESTS_PASS(void) {
  // Register tests that are expected to pass

  TEST_bno055_read_acc_x_success();
  // TEST_bno055_read_acc_y_success();
  // TEST_bno055_read_acc_z_success();
}

void REGISTER_TESTS_FAIL(void) {
  // Register tests that are expected to fail

  TEST_bno055_read_acc_no_sensor();
}

/**
 * Testing BNO055 IMU library.
 */

// Expected acceleration range (BNO055 range: ±4g, assuming raw values)
#define ACC_MAX_VALUE 4000

// Test: Read accelerometer X-axis successfully
void TEST_bno055_read_acc_x_success(void) {
  PRINT_TEST_MSG("TEST_bno055_read_acc_x_success\n");

  bno055_set_i2c_handler(&hi2c1);
  uint16_t acc_x = UINT16_MAX;
  BNO055_FUNC_RETURN ret = bno055_read_acc_x(&acc_x);

  TEST_ASSERT(BNO055_SUCCESS_DEFAULT == ret, __FILE__, __LINE__);
  TEST_ASSERT(acc_x <= ACC_MAX_VALUE, __FILE__, __LINE__);
}

// Test: Read accelerometer Y-axis successfully
void TEST_bno055_read_acc_y_success(void) {
  PRINT_TEST_MSG("TEST_bno055_read_acc_y_success\n");

  bno055_set_i2c_handler(&hi2c1);
  uint16_t acc_y = UINT16_MAX;
  BNO055_FUNC_RETURN ret = bno055_read_acc_y(&acc_y);

  TEST_ASSERT(BNO055_SUCCESS_DEFAULT == ret, __FILE__, __LINE__);
  TEST_ASSERT(acc_y <= ACC_MAX_VALUE, __FILE__, __LINE__);
}

// Test: Read accelerometer Z-axis successfully
void TEST_bno055_read_acc_z_success(void) {
  PRINT_TEST_MSG("TEST_bno055_read_acc_z_success\n");

  bno055_set_i2c_handler(&hi2c1);
  uint16_t acc_z = UINT16_MAX;
  BNO055_FUNC_RETURN ret = bno055_read_acc_z(&acc_z);

  TEST_ASSERT(BNO055_SUCCESS_DEFAULT == ret, __FILE__, __LINE__);
  TEST_ASSERT(acc_z <= ACC_MAX_VALUE, __FILE__, __LINE__);
}

// Test: Read accelerometer when sensor is disconnected
void TEST_bno055_read_acc_no_sensor(void) {
  PRINT_TEST_MSG("TEST_bno055_read_no_sensor\n");

  bno055_set_i2c_handler(&hi2c1);
  uint16_t acc_x = UINT16_MAX, acc_y = UINT16_MAX, acc_z = UINT16_MAX;

  TEST_ASSERT(BNO055_ERROR_DEFAULT == bno055_read_acc_x(&acc_x), __FILE__,
              __LINE__);
  TEST_ASSERT(BNO055_ERROR_DEFAULT == bno055_read_acc_y(&acc_y), __FILE__,
              __LINE__);
  TEST_ASSERT(BNO055_ERROR_DEFAULT == bno055_read_acc_z(&acc_z), __FILE__,
              __LINE__);
}
