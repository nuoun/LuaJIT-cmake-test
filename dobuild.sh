#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Delete the build directory if it exists
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# Create the build directory
mkdir "$BUILD_DIR"

# Run CMake to configure the project
cmake -B"$BUILD_DIR"

# Build the project
cmake --build "$BUILD_DIR"

# Run the executable
./build/luajit-test