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

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/exti.h>

#include "user-button.h"

#define USER_BUTTON_RCC_PERIPH_CLKEN   RCC_GPIOC

#define USER_BUTTON_GPIO_PORT          GPIOC
#define USER_BUTTON_GPIO_PIN           GPIO13

#define USER_BUTTON_EXTI               EXTI13
#define USER_BUTTON_EXTI_TRIGGER_TYPE  EXTI_TRIGGER_BOTH

#define USER_BUTTON_NVIC_IRQ           NVIC_EXTI4_15_IRQ
#define USER_BUTTON_NVIC_IRQ_PRIORITY  0

#define LED_RCC_PERIPH_CLKEN  RCC_GPIOA

#define LED_GPIO_PORT   GPIOA
#define LED_GPIO_PIN    GPIO5

void exti4_15_isr(void) {
  gpio_set(LED_GPIO_PORT, LED_GPIO_PIN);

  exti_reset_request(USER_BUTTON_EXTI);
}

void user_button_new(void) {
  // Enable the clock on particular peripheral
  rcc_periph_clock_enable(LED_RCC_PERIPH_CLKEN);
  rcc_periph_clock_enable(USER_BUTTON_RCC_PERIPH_CLKEN);

  // Enable the peripheral clock
  gpio_mode_setup(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);
  gpio_mode_setup(USER_BUTTON_GPIO_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, USER_BUTTON_GPIO_PIN);

  // Remap an external interrupt line to the corresponding pin on the specified GPIO port
  exti_select_source(USER_BUTTON_EXTI, USER_BUTTON_GPIO_PORT);

  // Choose a signal change that will trigger the external interrupt
  exti_set_trigger(USER_BUTTON_EXTI, USER_BUTTON_EXTI_TRIGGER_TYPE);

  // Unmask the external interrupt line of interest
  exti_enable_request(USER_BUTTON_EXTI);

  // NVIC set interrupt priority
  nvic_set_priority(USER_BUTTON_NVIC_IRQ, USER_BUTTON_NVIC_IRQ_PRIORITY);

  // NVIC enable interrupt
  nvic_enable_irq(USER_BUTTON_NVIC_IRQ);
}
