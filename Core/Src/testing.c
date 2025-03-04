#include "mini-test.h"

#include "BNO055.h"
#include "i2c.h"

/**
 * Testing BNO055 IMU library.
 */

void TEST_bno055_get_generic_event_pass(void);
void TEST_bno055_get_generic_event_fail(void);

void TEST_bno055_get_event_vect_gyro(void);
void TEST_bno055_get_event_vect_euler(void);
void TEST_bno055_get_event_vect_linear_acc(void);

/**
 * Testing MS5607 BAR library.
 */

void TEST_ms5607_update(void);

void TEST_ms5607_get_pressure_pa(void);

/**
 * Register ALL tests to be run.
 */
void REGISTER_TESTS_PASS(void) {
  // Register tests that are expected to pass

  TEST_bno055_get_generic_event_pass();
  TEST_bno055_get_event_vect_gyro();
  TEST_bno055_get_event_vect_euler();
  TEST_bno055_get_event_vect_linear_acc();

  TEST_ms5607_update();
  TEST_ms5607_get_pressure_pa();
}

void REGISTER_TESTS_FAIL(void) {
  // Register tests that are expected to fail

  TEST_bno055_get_generic_event_fail();
}

/**
 * Testing BNO055 IMU library.
 */

// Expected acceleration range (BNO055 range: ±4g, assuming raw values)
#define ACC_MAX_VALUE 4000

void bno055_generic_setup(void) {

}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_generic_event_pass(void) {
}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_generic_event_fail(void) {

}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_gyro(void) {

}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_euler(void) {

}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_linear_acc(void) {

}
