#ifndef RAINBOW_H
#define RAINBOW_H
#include "BaseBehavior.hpp"
#include <cmath>

class Rainbow : public BaseBehavior {

// RED --> RED BLUE --> BLUE --> BLUE GREEN --> GREEN --> GREEN RED --> 
private:
   long double mPartSpeed; // One arrow Above. Speed in ctor is full speed 
   long double mSpeed;
   signed char mMaxValue;

public:
   	Rainbow(char red, 
		   		char green, 
		   		char blue,
               signed char maxValue,
               signed char speed) 
      : BaseBehavior(red, green, blue) {
         mRed = red;
         mGreen = green;
         mBlue = blue;
         mSpeed = speed;
         mPartSpeed = speed * 1000 / 6;

         mInterval = 25;
   	}

      Rainbow & operator=(const Rainbow&) = default;

      void update(long double currentTime) {
         long double value = std::fmod((currentTime - mStartTime), mSpeed);
         double partValue = std::fmod(value, mPartSpeed);
         if (value <= mPartSpeed) {
            mRed = mMaxValue;
            mBlue = partValue / mPartSpeed * mMaxValue * 1.0;
            mGreen = 0;
         } else if (value > mPartSpeed && value <= mPartSpeed * 2) {
            mRed = partValue / mPartSpeed * mMaxValue * -1.0;
            mBlue = mMaxValue;
            mGreen = 0;
         } else if (value > mPartSpeed * 2 && value <= mPartSpeed * 3) {
            mRed = 0;
            mBlue = mBlue;
            mGreen = partValue / mPartSpeed * mMaxValue * 1.0;
         } else if (value > mPartSpeed * 3 && value <= mPartSpeed * 4) {
            mRed = 0;
            mBlue = partValue / mPartSpeed * mMaxValue * -1.0;
            mGreen = mMaxValue;
         } else if (value > mPartSpeed * 4 && value <= mPartSpeed * 5) {
            mRed = partValue / mPartSpeed * mMaxValue * 1.0;
            mBlue = 0;
            mGreen = mMaxValue;
         } else if (value > mPartSpeed * 5) {
            mRed = mMaxValue;
            mBlue = 0;
            mGreen = partValue / mPartSpeed * mMaxValue * -1.0;
         }
      }
};
#endif