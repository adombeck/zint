#!/bin/sh -eu
mkdir build
cd build
cmake .. # Here, you can place your CMake options such as -DDISABLE_TESTS
make -j$(nproc)
