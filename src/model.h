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

#ifndef YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__MODEL_H
#define YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__MODEL_H

#include <observer.h>

typedef struct model_t model_t;

/**
 * @brief Allocate a struct model_t, intended to be used as a model
 * @return The model
 */
model_t *model_new(void);

/**
 * @brief Free the memory for the given model
 * @param [in,out] model
 */
void model_free(model_t *model);

/**
 * @brief Attach the observer to a model
 * @param [in,out] model
 * @param [in] observer
 */
void model_attach(model_t *, const observer_t *);

/**
 * @brief Detach the given observer from the model
 * @param [in,out] model
 * @param [in] observer
 */
void model_detach(model_t *, const observer_t *);

#endif // YET_ANOTHER_GAUGE__LOOP_CALIBRATOR__MODEL_H
