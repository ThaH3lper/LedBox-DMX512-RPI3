#ifndef BASEBEHAVIOR_H
#define BASEBEHAVIOR_H
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <math.h>
#include "../global.h"

#define DEFAULT_INTERVAL 3000.0
#define PI 3.14159265

class BaseBehavior {

protected:
	double mInterval;
   long double mStartTime;
   long double mCurrentTime;
	char mRed;
	char mGreen;
	char mBlue;

public:
      BaseBehavior() {
         mRed = 120;
         mGreen = 20;
         mBlue = 0;
         mInterval = DEFAULT_INTERVAL;
      }

   	BaseBehavior(char red, 
		   		char green, 
		   		char blue) {

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

      char getRed() {
      	return mRed;
      }

      char getGreen() {
      	return mGreen;
      }

      char getBlue() {
      	return mBlue;
      }

      virtual void update(long double currentTime) {};
};
#endif