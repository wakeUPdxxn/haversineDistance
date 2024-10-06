#!/bin/sh
cmake -S . -B build/release -D CMAKE_BUILD_TYPE=Release
cmake --build build/release
