#!/bin/bash
echo "start build..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j