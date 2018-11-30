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

#ifndef YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__INDICATOR_H
#define YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__INDICATOR_H

typedef struct indicator_t indicator_t;

/**
 * @brief Allocate a struct indicator_t, intended to be used as an indicator
 * @return The indicator
 */
indicator_t *indicator_new(void);

/**
 * @brief Free the memory for the given indicator
 * @param [in,out] indicator
 */
void indicator_free(indicator_t *);

/**
 * @brief Turn on the indicator light
 * @param [in,out] indicator
 */
void indicator_on(indicator_t *);

/**
 * @brief Turn off the indicator light
 * @param [in,out] indicator
 */
void indicator_off(indicator_t *);

/**
 * @brief Toggle the indicator light
 * @param [in,out] indicator
 */
void indicator_toggle(indicator_t *);

#endif // YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__INDICATOR_H
