#!/usr/bin/env bash

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-debug}

if [ "$1"x = "all"x ]; then
    mkdir -p $BUILD_DIR/$BUILD_TYPE \
        && cd $BUILD_DIR/$BUILD_TYPE \
        && cmake \
        -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
        $SOURCE_DIR \
        && make $*
elif [ "$1"x = "clean"x ]; then
    cd $BUILD_DIR/$BUILD_TYPE \
        && make clean
fi
