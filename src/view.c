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
#include <stdint.h>

#include "view.h"
#include "model.h"
#include "indicator.h"

struct view_t {
  indicator_t *indicator;

  observer_t *observer;
};

static void view_update(const void *context, int argc, const void *argv[]) {
  view_t *view = (view_t *) context;
  const model_t *model = (const model_t *) argv[0];
}

view_t *view_new(void) {
  view_t *view = malloc(sizeof(view_t));

  view->indicator = indicator_new();
  view->observer = observer_new(view, view_update);

  indicator_off(view->indicator);

  return view;
}

void view_free(view_t *view) {
  if (view != NULL) {
    indicator_free(view->indicator);
    observer_delete(view->observer);

    free(view);
  }
}

const observer_t *view_get_observer(const view_t *view) {
  return view->observer;
}
