#!/bin/bash
gcc -o build/dmx512 dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
