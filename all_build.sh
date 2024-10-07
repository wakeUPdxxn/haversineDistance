#!/bin/sh
if [[ "$OSTYPE" == "msys" ]]; 
then
   cmake -S . -B build/release -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release
   cmake --build build/release
else
   cmake -S . -B build/release -D CMAKE_BUILD_TYPE=Release
   cmake --build build/release
fi
