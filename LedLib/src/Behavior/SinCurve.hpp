#ifndef SINCURVE_H
#define SINCURVE_H
#include "BaseBehavior.hpp"

class SinCurve : public BaseBehavior {

private:
   double FROM_ZERO_TO_ONE = 1.0;
   signed char mRedDiff;
   signed char mGreenDiff;
   signed char mBlueDiff;

   signed char minimumRed;
   signed char minimumGreen;
   signed char minimumBlue;

   signed char mSpeed;
   signed char mOffset;

public:
   	SinCurve(signed char red, signed char green, signed char blue,
               signed char minRed, signed char maxRed,
               signed char minGreen, signed char maxGreen,
               signed char minBlue, signed char maxBlue,
               signed char speed,
               signed char offset) 
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