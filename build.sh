#!/bin/bash

if [ $1 = "-r" ]; then
    echo '########## rebuild "##########'
    rm -rf build lib bin install
fi
mkdir -p build
cd build
echo '########## start build dependencies "##########'
cmake .. 
make -j
if [ $? = 0 ]; then
    echo '########## install "##########'
    make install
    cmake .. -DBUILD_EXECUTE=ON
    echo '########## start build target "##########'
    make -j
fi