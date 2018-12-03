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

#include <subject.h>

#include "model.h"

struct model_t {
  subject_t *subject;
};

model_t *model_new(void) {
  model_t *model = malloc(sizeof(model_t));

  model->subject = subject_new();

  return model;
}

void model_free(model_t *model) {
  if (model != NULL) {
    subject_delete(model->subject);

    free(model);
  }
}

void model_attach(model_t *model, const observer_t *observer) {
  subject_attach(model->subject, observer);
}

void model_detach(model_t *model, const observer_t *observer) {
  subject_detach(model->subject, observer);
}
