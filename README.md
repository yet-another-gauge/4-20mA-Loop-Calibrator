# 4-20mA-Loop-Calibrator
[![Build Status](https://travis-ci.org/yet-another-gauge/4-20mA-Loop-Calibrator.svg?branch=master)](https://travis-ci.org/yet-another-gauge/4-20mA-Loop-Calibrator)

## Getting started

### Clone a repository

```bash
$ git clone git@github.com:yet-another-gauge/4-20mA-Loop-Calibrator.git
$ git submodule update --init --recursive
```

### Build source code inside a Docker container

```bash
$ cd 4-20mA-Loop-Calibrator

$ docker build --tag=yet-another-gauge/4-20ma-lc .
$ docker run -v $PWD:/usr/src -it yet-another-gauge/4-20ma-lc /bin/bash

$ root@<hash>:/usr/src# mkdir build
$ root@<hash>:/usr/src# cd build
$ root@<hash>:/usr/src# cmake -DCMAKE_BUILD_TYPE=Debug ..
$ root@<hash>:/usr/src# make
```

## OpenOCD and GDB

- `openocd/ST-LINK-V2-1.cfg` specifies configuration to use the `ST-LINK/V2-1` adapter
- `openocd/STM32-NUCLEO-F091RC.cfg` contains initialization items that are specific to a `STM32 NUCLEO-F091RC` board

```bash
$ openocd -f openocd/ST-LINK-V2-1.cfg -f openocd/STM32-NUCLEO-F091RC.cfg
```

```bash
$ arm-none-eabi-gdb build/4-20mA-Loop-Calibrator.elf
...
Reading symbols from 4-20mA-Loop-Calibrator.elf...
(gdb) target extended-remote localhost:3333
Remote debugging using localhost:3333
...
(gdb) monitor reset halt
...
(gdb) set substitute-path /usr/src <absolute path to the working directory>
...
(gdb) load
...
(gdb) continue
Continuing.
```

## Dependencies

* [CMake](https://cmake.org/) is an open-source, cross-platform family of tools designed to build, test and package software
* [LibOpenCM3](http://libopencm3.org/) is open source ARM Cortex-M microcontroller library
* [Observer](https://github.com/yet-another-gauge/observer) is a pure C implementation of the observer pattern
