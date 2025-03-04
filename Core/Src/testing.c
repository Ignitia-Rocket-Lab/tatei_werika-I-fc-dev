#include "mini-test.h"

#include "BNO055.h"
#include "MS5607.h"

#include "i2c.h"
#include "spi.h"

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

void TEST_ms5607_generic_setup_pass(void);
void TEST_ms5607_generic_setup_fail(void);
void TEST_ms5607_repeated_get_pressure(void);
void TEST_ms5607_repeated_get_temperature(void);

/**
 * Register ALL tests to be run.
 */
void REGISTER_TESTS_PASS(void) {
  // Register tests that are expected to pass

  TEST_bno055_get_generic_event_pass();
  TEST_bno055_get_event_vect_gyro();
  TEST_bno055_get_event_vect_euler();
  TEST_bno055_get_event_vect_linear_acc();

  TEST_ms5607_generic_setup_pass();
  TEST_ms5607_repeated_get_pressure();
  TEST_ms5607_repeated_get_temperature();
}

void REGISTER_TESTS_FAIL(void) {
  // Register tests that are expected to fail

  TEST_bno055_get_generic_event_fail();

  TEST_ms5607_generic_setup_fail();
}

/**
 * Testing BNO055 IMU library.
 */

// Expected acceleration range (BNO055 range: ±4g, assuming raw values)
#define ACC_MAX_VALUE 4000

void bno055_generic_setup(void) {}

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_generic_event_pass(void) { bno055_generic_setup(); }

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_generic_event_fail(void) { bno055_generic_setup(); }

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_gyro(void) { bno055_generic_setup(); }

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_euler(void) { bno055_generic_setup(); }

// Test: Read accelerometer X-axis successfully
void TEST_bno055_get_event_vect_linear_acc(void) { bno055_generic_setup(); }

/**
 * Testing MS5607 BAR library.
 */

#define MS5607_PRESSURE_MIN 60000  // Minimum expected pressure in Pa
#define MS5607_PRESSURE_MAX 110000 // Maximum expected pressure in Pa
#define MS5607_TEMP_MIN 5          // Minimum expected temperature in °C
#define MS5607_TEMP_MAX 40         // Maximum expected temperature in °C

void ms5607_clean_up(void) { (void)MS5607_Init(NULL, NULL, INFINITY); }

void TEST_ms5607_generic_setup_pass(void) {
  MS5607StateTypeDef init_state =
      MS5607_Init(&hspi3, BAR_CS_GPIO_Port, BAR_CS_Pin);

  TEST_ASSERT(init_state == MS5607_STATE_READY, __FILE__, __LINE__);
  ms5607_clean_up();
}

// Test: Confirm bad init in case of bad SPI handle, bad GPIO port, bad PIN
void TEST_ms5607_generic_setup_fail(void) {
  // Bad SPI handle
  MS5607StateTypeDef init_state =
      MS5607_Init(NULL, BAR_CS_GPIO_Port, BAR_CS_Pin);
  TEST_ASSERT(init_state == MS5607_STATE_FAILED, __FILE__, __LINE__);
  ms5607_clean_up();

  // Bad GPIO port
  MS5607StateTypeDef init_state = MS5607_Init(&hspi3, NULL, BAR_CS_Pin);
  TEST_ASSERT(init_state == MS5607_STATE_FAILED, __FILE__, __LINE__);
  ms5607_clean_up();

  // Bad PIN
  MS5607StateTypeDef init_state =
      MS5607_Init(&hspi3, BAR_CS_GPIO_Port, UINT16_MAX);
  TEST_ASSERT(init_state == MS5607_STATE_FAILED, __FILE__, __LINE__);
  ms5607_clean_up();
}

void TEST_ms5607_repeated_get_pressure(void) {
  // NOTE: This test assumes average altitude and atmospheric conditions

  MS5607_Init(&hspi3, BAR_CS_GPIO_Port, BAR_CS_Pin); // Assume good init

  const uint8_t repetitions = 10;
  const uint32_t wait_ms = 10; // Wait between repeated readings
  uint32_t readings[10];

  for (uint8_t i = 0; i < repetitions; i++) {
    MS5607Update();
    readings[i] = MS5607GetPressurePa();
    HAL_Delay(wait_ms);
  }

  for (uint8_t i = 0; i < repetitions; i++) {
    TEST_ASSERT(readings[i] >= MS5607_PRESSURE_MIN, __FILE__, __LINE__);
    TEST_ASSERT(readings[i] <= MS5607_PRESSURE_MAX, __FILE__, __LINE__);
  }

  ms5607_clean_up();
}

void TEST_ms5607_repeated_get_temperature(void) {
  // NOTE: This test assumes average room temperature during testing

  MS5607_Init(&hspi3, BAR_CS_GPIO_Port, BAR_CS_Pin); // Assume good init

  const uint8_t repetitions = 10;
  const uint32_t wait_ms = 10; // Wait between repeated readings
  float readings[10];

  for (uint8_t i = 0; i < repetitions; i++) {
    MS5607Update();
    readings[i] = MS5607GetTemperatureC();
    HAL_Delay(wait_ms);
  }

  for (uint8_t i = 0; i < repetitions; i++) {
    TEST_ASSERT(readings[i] >= MS5607_TEMP_MIN, __FILE__, __LINE__);
    TEST_ASSERT(readings[i] <= MS5607_TEMP_MAX, __FILE__, __LINE__);
  }

  ms5607_clean_up();
}
