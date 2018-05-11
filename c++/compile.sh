#!/bin/bash
#gcc -o build/dmx512 src/dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib
#gcc -o build/led-start src/led-start.c -L. -lftd2xx -Wl,-rpath /usr/local/lib

printf "\033[1;30mBuilding: Led\n"
g++ src/Led.cpp src/Dmx/DmxController.cpp src/SharedMemory/SharedMemory.cpp src/Server.cpp src/Behavior/BaseBehavior.hpp src/Behavior/SinCurve.hpp src/Behavior/FadeToSimple.hpp src/global.cpp -o build/Led -std=gnu++11 -L. -lftd2xx -Wl,-rpath /usr/local/lib

#sudo cp ./build/led /usr/bin/
#sudo cp ./build/led-start /usr/bin/

printf "\033[0;32m[Builds Completed]\n"