#ifndef SELECTOR_H
#define SELECTOR_H
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <math.h>
#include "../global.h"
#include "../Behavior/BaseBehavior.hpp"
#include "../Behavior/FadeToSimple.hpp"
#include "../Behavior/SinCurve.hpp"

#define DEFAULT_INTERVAL 3000.0

class Selector {

public:

   void select(unsigned char * & data, BaseBehavior* behaviours[]) {
      for (int behaviourIndex = 0; behaviourIndex < global::MAX_CHANNELS; behaviourIndex++)
      {
         int dataIndex = behaviourIndex * global::MAX_CHANNEL_DATA;
         unsigned char type = data[dataIndex+0];
         unsigned char oldRed = behaviours[behaviourIndex]->getRed();
         unsigned char oldGreen = behaviours[behaviourIndex]->getGreen();
         unsigned char oldBlue = behaviours[behaviourIndex]->getBlue();

         if (type == B_FADE_TO_SIMPLE) {
            unsigned char red = data[dataIndex+1];
            unsigned char green = data[dataIndex+2];
            unsigned char blue = data[dataIndex+3];

            printf(RED "%.0i" RESET, type);
            printf(YELLOW " --> %.0i | %.0i | %.0i \n" RESET, red, green, blue);
            behaviours[behaviourIndex] = new FadeToSimple(oldRed, oldGreen, oldBlue, red, green, blue);
         
         } else if (type == B_SIN_CURVE) {
            unsigned char minRed = data[dataIndex+1];
            unsigned char maxRed = data[dataIndex+2];
            unsigned char minGreen = data[dataIndex+3];
            unsigned char maxGreen = data[dataIndex+4];
            unsigned char minBlue = data[dataIndex+5];
            unsigned char maxBlue = data[dataIndex+6];
            unsigned char speed = data[dataIndex+7];
            unsigned char offset = data[dataIndex+8];

            behaviours[behaviourIndex] = new SinCurve(oldRed, oldGreen, oldBlue, 
                     minRed, maxRed, 
                     minGreen, maxGreen, 
                     minBlue, maxBlue,
                     speed, offset * behaviourIndex);
         
         } else {
            printf(RED "UNDEFINED" RESET "\n");
         }
      }
   }
};
#endif