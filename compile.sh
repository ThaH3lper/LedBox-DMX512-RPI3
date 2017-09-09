#!/bin/bash
gcc -o build/dmx512 src/dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
gcc -o build/server src/server.c
gcc -o build/client src/client.c