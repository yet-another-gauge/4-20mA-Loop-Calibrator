# This file is part of the 'Yet another gauge' project.
#
# Copyright (C) 2018 Ivan Dyachenko <vandyachen@gmail.com>
#
# This library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library. If not, see <http://www.gnu.org/licenses/>.

# LibOpenCM3. Open-Source lowlevel hardware library for various ARM microcontrollers

set(LIBOPENCM3_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libopencm3")

set(LIBOPENCM3_IMPORTED_LOCATION "${LIBOPENCM3_DIRECTORY}/lib/libopencm3_stm32f0.a")

set(LIBOPENCM3_LINK_LIBRARIES "${LIBOPENCM3_DIRECTORY}/lib/libopencm3_stm32f0.a")
set(LIBOPENCM3_LINK_DIRECTORIES "${LIBOPENCM3_DIRECTORY}/lib")
set(LIBOPENCM3_INCLUDE_DIRECTORIES "${LIBOPENCM3_DIRECTORY}/include")

message(STATUS "LIBOPENCM3_LINK_LIBRARIES: ${LIBOPENCM3_LINK_LIBRARIES}")
message(STATUS "LIBOPENCM3_LINK_DIRECTORIES: ${LIBOPENCM3_LINK_DIRECTORIES}")
message(STATUS "LIBOPENCM3_INCLUDE_DIRECTORIES: ${LIBOPENCM3_INCLUDE_DIRECTORIES}")

add_custom_target(libopencm3-build
        COMMAND make
        WORKING_DIRECTORY "${LIBOPENCM3_DIRECTORY}"
        COMMENT "Build libopencm3"
        VERBATIM)

add_library(libopencm3 STATIC IMPORTED GLOBAL)

add_dependencies(libopencm3 libopencm3-build)

set_target_properties(libopencm3 PROPERTIES
        IMPORTED_LOCATION "${LIBOPENCM3_IMPORTED_LOCATION}"

        LINK_LIBRARIES "${LIBOPENCM3_LINK_LIBRARIES}"
        LINK_DIRECTORIES "${LIBOPENCM3_LINK_DIRECTORIES}"
        INCLUDE_DIRECTORIES "${LIBOPENCM3_INCLUDE_DIRECTORIES}"

        INTERFACE_POSITION_INDEPENDENT_CODE ON)

# Observer. A pure C implementation of the observer pattern

add_subdirectory(observer)
