# 4-20mA-Loop-Calibrator
[![Build Status](https://travis-ci.org/yet-another-gauge/4-20mA-Loop-Calibrator.svg?branch=master)](https://travis-ci.org/yet-another-gauge/4-20mA-Loop-Calibrator)

## Getting started

```bash
git clone git@github.com:yet-another-gauge/4-20mA-Loop-Calibrator.git
git submodule update --init --recursive
```

```bash
cd 4-20mA-Loop-Calibrator

docker build --tag=yet-another-gauge/4-20ma-lc .
docker run -v $PWD:/usr/src -it yet-another-gauge/4-20ma-lc /bin/bash

root@<hash>:/usr/src# mkdir build
root@<hash>:/usr/src# cd build
root@<hash>:/usr/src# cmake ..
root@<hash>:/usr/src# make
```



## Dependencies

* [CMake](https://cmake.org/) is an open-source, cross-platform family of tools designed to build, test and package software
* [LibOpenCM3](http://libopencm3.org/) is open source ARM Cortex-M microcontroller library
