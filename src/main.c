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

#include <libopencm3/stm32/rcc.h>

#include "indicator.h"

void infinite_loop(void) {
  while (1)
    asm volatile("");
}

int main(void) {
  /**
   * Set System Clock PLL at 48MHz from HSI
   */
  rcc_clock_setup_in_hsi_out_48mhz();

  indicator_t* indicator = indicator_new();

  indicator_on(indicator);

  indicator_free(indicator);

  infinite_loop();

  return 0;
}
