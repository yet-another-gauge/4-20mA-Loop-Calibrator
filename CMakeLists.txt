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

cmake_minimum_required(VERSION 3.5.1)

project(4-20mA-Loop-Calibrator C)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m0)

set(CMAKE_C_STANDARD 99)

set(triple arm-none-eabi)

set(CROSS_COMPILER_PREFIX arm-none-eabi-)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_C_COMPILER_TARGET ${triple})

set(CMAKE_EXECUTABLE_SUFFIX .elf)

add_definitions(-DSTM32F0)

set(CMAKE_C_FLAGS "--specs=nano.specs")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -mcpu=cortex-m0 -mfloat-abi=soft")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -MD")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-common -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wundef -Wextra -Wshadow")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-variable -Wimplicit-function-declaration -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code")

add_subdirectory(ld)
add_subdirectory(lib)
add_subdirectory(src)

set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mthumb -mcpu=cortex-m0 -mfloat-abi=soft")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections -Wl,-Map=$(${PROJECT_NAME}).map -Wl,--print-gc-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -nostartfiles -T${LDSCRIPT}")

get_target_property(LIBOPENCM3_LINK_DIRECTORIES libopencm3 LINK_DIRECTORIES)
link_directories(${LIBOPENCM3_LINK_DIRECTORIES})

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        $<TARGET_OBJECTS:observer>)

add_dependencies(${PROJECT_NAME}
        observer
        libopencm3)

target_link_libraries(${PROJECT_NAME}
        libopencm3)

target_include_directories(${PROJECT_NAME}
        PRIVATE $<TARGET_PROPERTY:observer,INTERFACE_INCLUDE_DIRECTORIES>
        PRIVATE $<TARGET_PROPERTY:libopencm3,INCLUDE_DIRECTORIES>)
