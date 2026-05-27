#!/bin/bash

# Autoplay Perfect Score Build Script
echo "Building Autoplay Perfect Score qmod..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake -DCMAKE_TOOLCHAIN_FILE=./ndk/build/cmake/android.toolchain.cmake \
      -DCMAKE_BUILD_TYPE=MinSizeRel \
      ..

# Build the library
cmake --build . --config MinSizeRel

# Package the qmod
echo "Packaging qmod..."
zip -r ../AutoplayMod.qmod \
  ../mod.json \
  lib/libAutoplayMod.so

echo "Build complete! AutoplayMod.qmod created."
echo "Ready to install with QuestPatcher."
