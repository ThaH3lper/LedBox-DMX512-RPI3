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

         struct timespec gettime_now;
         clock_gettime(CLOCK_REALTIME, &gettime_now);
         time_t s = gettime_now.tv_sec;
         long ms = round(gettime_now.tv_nsec / 1.0e6);
         if (ms > 999) {
             s++;
             ms = 0;
         }

         mStartTime = (s * 1000.0) + ms;
         printf("START --> %Lf\n", mStartTime);
         //mStartTime = std::time(nullptr) * 1000.0;
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

      virtual void update(long double currentTime) {};
};
#endif