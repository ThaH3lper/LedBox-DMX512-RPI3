#ifndef FADETOSIMPLE_H
#define FADETOSIMPLE_H
#include "BaseBehavior.hpp"

class FadeToSimple : public BaseBehavior {

private:
   double FROM_ZERO_TO_ONE = 0.5;
   char mRedDiff;
   char mGreenDiff;
   char mBlueDiff;

   char mRedStart;
   char mGreenStart;
   char mBlueStart;

public:
   	FadeToSimple(char red, 
		   		char green, 
		   		char blue,
               char newRed,
               char newGreen,
               char newBlue) 
      : BaseBehavior(red, green, blue) {
         mRedStart = red;
         mGreenStart = green;
         mBlueStart = blue;

         mRedDiff = newRed - mRed;
         mGreenDiff = newGreen - mGreen;
         mBlueDiff = newBlue - mBlue;

         printf("%i\n", mRedDiff);

         mInterval = 1;
   	}

      FadeToSimple & operator=(const FadeToSimple&) = default;

      void update(long double currentTime) {
         double value = (currentTime - mStartTime) / FROM_ZERO_TO_ONE / 1000.0;
         if (value <= 1.0) {
            mRed = mRedStart + mRedDiff * value;
            mGreen = mGreenStart + mGreenDiff * value;
            mBlue = mBlueStart + mBlueDiff * value;
            mInterval = 1;
         } else {
            mRed = mRedStart + mRedDiff;
            mGreen = mGreenStart + mGreenDiff;
            mBlue = mBlueStart + mBlueDiff;
            mInterval = DEFAULT_INTERVAL;
         }
      }
};
#endif