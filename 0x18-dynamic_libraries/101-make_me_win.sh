#!/bin/bash
wget -P .. https://github.com/tok2fatsu/alx-low_level_programming/blob/ff8e794f236d8786050ca8cb837c2526d18e2439/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD="$PWD/../libinject.so"
