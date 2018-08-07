#ifndef SELECTOR_H
#define SELECTOR_H
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include "../global.h"
#include "../Behavior/BaseBehavior.hpp"
#include "../Behavior/FadeToSimple.hpp"
#include "../Behavior/SinCurve.hpp"

class Selector {

public:

   void select(unsigned char * & data, BaseBehavior* behaviours[]) {
      for (int behaviourIndex = 0; behaviourIndex < global::MAX_CHANNELS; behaviourIndex++)
      {
         int dataIndex = behaviourIndex * global::MAX_CHANNEL_DATA;
         signed char type = data[dataIndex+0];
         signed char oldRed = behaviours[behaviourIndex]->getRed();
         signed char oldGreen = behaviours[behaviourIndex]->getGreen();
         signed char oldBlue = behaviours[behaviourIndex]->getBlue();

         if (type == B_FADE_TO_SIMPLE) {
            signed char red = data[dataIndex+1];
            signed char green = data[dataIndex+2];
            signed char blue = data[dataIndex+3];

            printf(RED "%.0i" RESET, type);
            printf(YELLOW " --> %.0i | %.0i | %.0i \n" RESET, red, green, blue);
            behaviours[behaviourIndex] = new FadeToSimple(oldRed, oldGreen, oldBlue, red, green, blue);
         
         } else if (type == B_SIN_CURVE) {
            signed char minRed = data[dataIndex+1];
            signed char maxRed = data[dataIndex+2];
            signed char minGreen = data[dataIndex+3];
            signed char maxGreen = data[dataIndex+4];
            signed char minBlue = data[dataIndex+5];
            signed char maxBlue = data[dataIndex+6];
            signed char speed = data[dataIndex+7];
            signed char offset = data[dataIndex+8];

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