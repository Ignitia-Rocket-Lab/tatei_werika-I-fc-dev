#include "info_sequences.h"
#include "main.h"

void blink_builtin_LED(LED_COLOR color) {
  const uint32_t blink_delay =
      (uint32_t)(1000 / LED_BLINK_FREQ_HZ); // Blink delay in milliseconds

  for (int i = 0; i < (LED_BLINK_TIME_SEC * LED_BLINK_FREQ_HZ); ++i) {
    switch (color) {
    case LED_GREEN:
      HAL_GPIO_TogglePin(BUILTIN_GREEN_LED_GPIO_Port, BUILTIN_GREEN_LED_Pin);
      HAL_Delay(blink_delay);
      break;

    case LED_BLUE:
      HAL_GPIO_TogglePin(BUILTIN_BLUE_LED_GPIO_Port, BUILTIN_BLUE_LED_Pin);
      HAL_Delay(blink_delay);
      break;

    case LED_OFF:
      HAL_GPIO_WritePin(BUILTIN_GREEN_LED_GPIO_Port, BUILTIN_GREEN_LED_Pin,
                        GPIO_PIN_RESET);
      HAL_GPIO_WritePin(BUILTIN_BLUE_LED_GPIO_Port, BUILTIN_BLUE_LED_Pin,
                        GPIO_PIN_RESET);
      break;

    default:
      break;
    }
  }
}
