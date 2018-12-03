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

#include "controller.h"

struct controller_t {
  const view_t *view;
  const model_t *model;

  observer_t *observer;
};

static void controller_update(const void *context, int argc, const void *argv[]) {
  controller_t *controller = (controller_t *) context;
  const model_t *model = (const model_t *) argv[0];
}

controller_t *controller_new(const model_t *model, const view_t *view) {
  controller_t *controller = malloc(sizeof(controller_t));

  controller->view = view;
  controller->model = model;
  controller->observer = observer_new(controller, controller_update);

  return controller;
}

void controller_free(controller_t *controller) {
  if (controller != NULL) {
    observer_delete(controller->observer);

    free(controller);
  }
}

const observer_t *controller_get_observer(const controller_t *controller) {
  return controller->observer;
}
