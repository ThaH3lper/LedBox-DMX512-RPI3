#ifndef BASEBEHAVIOR_H
#define BASEBEHAVIOR_H
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <math.h>
#include "../global.h"

#define DEFAULT_INTERVAL 3000.0
#define PI 3.14159265

class BaseBehavior {

protected:
	double mInterval;
   unsigned long mStartTime;
   unsigned long mCurrentTime;
	unsigned char mRed;
	unsigned char mGreen;
	unsigned char mBlue;

public:
      BaseBehavior() {
         mRed = 120;
         mGreen = 20;
         mBlue = 0;
         mInterval = DEFAULT_INTERVAL;
      }

   	BaseBehavior(unsigned char red, 
		   		unsigned char green, 
		   		unsigned char blue) {

         mRed = red;
         mGreen = green;
         mBlue = blue;
         mInterval = DEFAULT_INTERVAL;
         mStartTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
   	}

      BaseBehavior & operator=(BaseBehavior const & other) = default;

      virtual double getUpdateInterval(){
      	return mInterval;
      }

      unsigned char getRed() {
      	return mRed;
      }

      unsigned char getGreen() {
      	return mGreen;
      }

      unsigned char getBlue() {
      	return mBlue;
      }

      virtual void update(unsigned long currentTime) {};
};
#endif