#!/bin/bash

# Run CMake to configure
cmake -Bbuild

# Build
cmake --build build

# Run the executable
./build/luajit-test