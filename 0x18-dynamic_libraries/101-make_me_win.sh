#!/bin/bash
wget -P .. https://raw.githubusercontent.com/shahTanya/alx-low_level_programming/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD="$PWD/../libgiga.so"
./gm 9 8 10 24 75 9
