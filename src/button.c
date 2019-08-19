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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include <subject.h>

#include <libopencm3/stm32/gpio.h>

#include "button.h"

struct button_t {
  uint16_t gpio_pin;
  uint32_t gpio_port;

  enum rcc_periph_clken clken;

  subject_t *subject;
};

button_t *button_new(enum rcc_periph_clken clken, uint16_t gpio_pin, uint32_t gpio_port) {
  // Enable the clock on particular peripheral
  rcc_periph_clock_enable(clken);

  // Enable the peripheral clock
  gpio_mode_setup(gpio_port, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, gpio_pin);

  button_t *button = malloc(sizeof(button_t));

  button->gpio_pin = gpio_pin;
  button->gpio_port = gpio_port;

  button->clken = clken;

  button->subject = subject_new();

  return button;
}

void button_free(button_t *button) {
  if (button != NULL) {
    subject_delete(button->subject);

    free(button);
  }
}

void button_attach(button_t *button, const observer_t *observer) {
  subject_attach(button->subject, observer);
}

void button_detach(button_t *button, const observer_t *observer) {
  subject_detach(button->subject, observer);
}

void button_notify(const button_t *button, int argc, const void *argv[]) {
  subject_notify(button->subject, argc, argv);
}
