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

#ifndef YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__CONTROLLER_H
#define YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__CONTROLLER_H

#include <observer.h>

#include "view.h"
#include "model.h"

typedef struct controller_t controller_t;

/**
 * @brief Allocate a struct controller_t, intended to be used as a controller
 * @param [in] model
 * @param [in] view
 * @return The controller
 */
controller_t *controller_new(const model_t *, const view_t *);

/**
 * @brief Free the memory for the given controller
 * @param [in,out] controller
 */
void controller_free(controller_t *);

/**
 * @brief Return the observer of the given controller
 * @param [in] controller
 * @return The observer
 */
const observer_t *controller_get_observer(const controller_t *);

#endif // YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__CONTROLLER_H
