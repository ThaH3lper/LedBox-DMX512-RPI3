#!/bin/bash
gcc -o build/dmx512 src/dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
gcc -o build/led-start src/led-start.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
gcc -o build/led src/led.c
sudo cp ./build/led /usr/bin/
sudo cp ./build/led-start /usr/bin/