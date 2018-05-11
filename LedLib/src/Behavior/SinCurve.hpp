#ifndef SINCURVE_H
#define SINCURVE_H
#include "BaseBehavior.hpp"

class SinCurve : public BaseBehavior {

private:
   double FROM_ZERO_TO_ONE = 1.0;
   unsigned char mRedDiff;
   unsigned char mGreenDiff;
   unsigned char mBlueDiff;

   unsigned char minimumRed;
   unsigned char minimumGreen;
   unsigned char minimumBlue;

   unsigned char mSpeed;
   unsigned char mOffset;

public:
   	SinCurve(unsigned char red, 
		   		unsigned char green, 
		   		unsigned char blue,
               unsigned char minRed,
               unsigned char maxRed,
               unsigned char minGreen,                
               unsigned char maxGreen,
               unsigned char minBlue,
               unsigned char maxBlue,
               unsigned char speed,
               unsigned char offset) 
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

      void update(unsigned long currentTime) {
         double value = (currentTime - mStartTime) / FROM_ZERO_TO_ONE / 1000.0;
         double zeroToOne = sin((value / mSpeed) + mOffset / 10.0) * 0.5 + 0.5;

         mRed = minimumRed + mRedDiff * zeroToOne;
         mGreen = minimumGreen + mGreenDiff * zeroToOne;
         mBlue = minimumBlue + mBlueDiff * zeroToOne;

         mInterval = 1;
      }
};
#endif