#!/bin/bash
gcc -o build/dmx512 src/dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
gcc -o build/test1 src/test1.c
gcc -o build/test2 src/test2.c