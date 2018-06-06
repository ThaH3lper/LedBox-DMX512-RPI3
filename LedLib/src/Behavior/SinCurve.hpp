#ifndef SINCURVE_H
#define SINCURVE_H
#include "BaseBehavior.hpp"

class SinCurve : public BaseBehavior {

private:
   double FROM_ZERO_TO_ONE = 1.0;
   char mRedDiff;
   char mGreenDiff;
   char mBlueDiff;

   char minimumRed;
   char minimumGreen;
   char minimumBlue;

   char mSpeed;
   char mOffset;

public:
   	SinCurve(char red, char green, char blue,
               char minRed, char maxRed,
               char minGreen, char maxGreen,
               char minBlue, char maxBlue,
               char speed,
               char offset) 
      : BaseBehavior(red, green, blue) {

         mRedDiff = maxRed - minRed;
         mGreenDiff = maxGreen - minGreen;
         mBlueDiff = maxBlue - minBlue;

         minimumRed = minRed;
         minimumGreen = minGreen;
         minimumBlue = minBlue;

         mSpeed = speed;
         mOffset = offset;

         mInterval = 1;

   	}

      SinCurve & operator=(const SinCurve&) = default;

      void update(long double currentTime) {
         double value = (currentTime - mStartTime) / FROM_ZERO_TO_ONE / 1000.0;
         double zeroToOne = sin((value / mSpeed) + mOffset / 10.0) * 0.5 + 0.5;

         mRed = minimumRed + mRedDiff * zeroToOne;
         mGreen = minimumGreen + mGreenDiff * zeroToOne;
         mBlue = minimumBlue + mBlueDiff * zeroToOne;

         mInterval = 1;
      }
};
#endif