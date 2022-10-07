#!/bin/bash

set -xe

OUT=$PWD/resid-build-amiga
rm -rf $OUT
mkdir $OUT
pushd resid-build-amiga
cmake -DCMAKE_TOOLCHAIN_FILE=../Amiga.cmake ..
make VERBOSE=1
popd
