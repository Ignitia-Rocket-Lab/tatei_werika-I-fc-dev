#ifndef INFO_SEQUENCES_H
#define INFO_SEQUENCES_H

#include "stm32f4xx_hal.h"

#include <stdio.h>

#define LED_BLINK_TIME_SEC 3
#define LED_BLINK_FREQ_HZ 0.5

typedef enum {
  LED_OFF = 0,
  LED_RED,
  LED_GREEN,
  LED_BLUE,
  LED_YELLOW,
  LED_CYAN,
  LED_MAGENTA,
  LED_WHITE
} LED_COLOR;

void blink_builtin_LED(LED_COLOR color);


#endif // INFO_SEQUENCES_H