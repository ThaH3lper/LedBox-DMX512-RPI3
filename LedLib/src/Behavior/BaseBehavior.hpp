#ifndef BASEBEHAVIOR_H
#define BASEBEHAVIOR_H
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <math.h>
#include "../global.h"

#define DEFAULT_INTERVAL 300.0
#define PI 3.14159265

class BaseBehavior {

protected:
	double mInterval;
   long double mStartTime;
   long double mCurrentTime;
	signed char mRed;
	signed char mGreen;
	signed char mBlue;

public:
      BaseBehavior() {
         mRed = 120;
         mGreen = 20;
         mBlue = 0;
         mInterval = DEFAULT_INTERVAL;
      }

   	BaseBehavior(signed char red, 
		   		signed char green, 
		   		signed char blue) {

         mRed = red;
         mGreen = green;
         mBlue = blue;
         mInterval = DEFAULT_INTERVAL;

         mStartTime = getCurrentTimeMS();
   	}

      BaseBehavior & operator=(BaseBehavior const & other) = default;

      virtual double getUpdateInterval(){
      	return mInterval;
      }

      signed char getRed() {
      	return mRed;
      }

      signed char getGreen() {
      	return mGreen;
      }

      signed char getBlue() {
      	return mBlue;
      }

      virtual void update(long double currentTime) {};
};
#endif