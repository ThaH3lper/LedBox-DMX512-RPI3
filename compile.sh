#!/bin/bash

#gcc -o LedLib/build/dmx512 src/dmx512.c -L. -lftd2xx -Wl,-rpath /usr/local/lib

#gcc -o build/led-start src/led-start.c -L. -lftd2xx -Wl,-rpath /usr/local/lib


printf "\033[1;30mBuilding: Led\n"

g++ LedLib/src/Led.cpp LedLib/src/Dmx/DmxController.cpp LedLib/src/SharedMemory/SharedMemory.cpp LedLib/src/Server.cpp LedLib/src/Behavior/BaseBehavior.hpp LedLib/src/Behavior/SinCurve.hpp LedLib/src/Behavior/FadeToSimple.hpp LedLib/src/global.cpp -o LedLib/build/Led -std=gnu++11 -L. -lftd2xx -Wl,-rpath /usr/local/lib


#sudo cp ./build/led /usr/bin/

#sudo cp ./build/led-start /usr/bin/


printf "\033[0;32m[Builds Completed]\n"
sudo cp ./LedLib/build/Led /usr/bin/
printf "\033[0;32m[File copied]\n"
