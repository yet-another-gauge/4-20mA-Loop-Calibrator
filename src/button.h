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

#ifndef YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__BUTTON_H
#define YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__BUTTON_H

#include <stdint.h>

#include <observer.h>

#include <libopencm3/stm32/rcc.h>

typedef struct button_t button_t;

/**
 * @brief Allocate a struct button_t, intended to be used as an button
 * @param [in] clken
 * @param [in] gpio_pin
 * @param [in] gpio_port
 * @return The button
 */
button_t *button_new(enum rcc_periph_clken clken, uint16_t gpio_pin, uint32_t gpio_port);

/**
 * @brief Free the memory for the given button
 * @param [in,out] button
 */
void button_free(button_t *);

/**
 * @brief Attach the observer to a button
 * @param [in,out] button
 * @param [in] observer
 */
void button_attach(button_t *, const observer_t *);

/**
 * @brief Detach the given observer from the button
 * @param [in,out] button
 * @param [in] observer
 */
void button_detach(button_t *, const observer_t *);

/**
 * @brief Send a notification to all the observers of the button
 * @param [in] button
 * @param [in] argc
 * @param [in] argv
 */
void button_notify(const button_t *, int argc, const void *argv[]);

#endif // YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__BUTTON_H
