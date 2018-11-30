/*
 * This file is part of the 'Yet another gauge' project.
 *
 * Copyright (C) 2018 Ivan Dyachenko <vandyachen@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "indicator.h"

#define LED_RCC_PERIPH_CLKEN  RCC_GPIOA

#define LED_GPIO_PORT   GPIOA
#define LED_GPIO_PIN    GPIO5

struct indicator_t {
  uint16_t pin;
  uint32_t port;
};

indicator_t *indicator_new(void) {
  /**
   * Enable the clock on particular peripheral
   */
  rcc_periph_clock_enable(LED_RCC_PERIPH_CLKEN);

  /**
   * Enable the peripheral clock
   */
  gpio_mode_setup(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);

  indicator_t *indicator = malloc(sizeof(indicator_t));

  indicator->pin = LED_GPIO_PIN;
  indicator->port = LED_GPIO_PORT;

  return indicator;
}

void indicator_free(indicator_t *indicator) {
  if (indicator != NULL) {
    free(indicator);
  }
}

void indicator_on(indicator_t *indicator) {
  gpio_set(indicator->port, indicator->pin);
}

void indicator_off(indicator_t *indicator) {
  gpio_clear(indicator->port, indicator->pin);
}

void indicator_toggle(indicator_t *indicator) {
  gpio_toggle(indicator->port, indicator->pin);
}
