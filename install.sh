#!/bin/sh
cd build/release
cmake --install . 
cd - 
rm -r -f build 
