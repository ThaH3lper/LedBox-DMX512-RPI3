#ifndef BOOTBEHAVIOR_H
#define BOOTBEHAVIOR_H
#include "BaseBehavior.hpp"

class BootBehavior : public BaseBehavior {

private:
   double FADE_IN_AND_OUT_TIME = 0.6;
   double mDelay;
   char mFadeColorRed;
   char mFadeColorGreen;
   char mFadeColorBlue;

   double FADE_TO_FINAL = 1650.0;
   double FADE_TO_FINAL_TIME = 2.0;
   char mFinalRed = 127;
   char mFinalGreen = 25;
   char mFinalBlue = 0;

public:
	BootBehavior(char red, 
	   		char green, 
	   		char blue, double delay) 
   : BaseBehavior(red, green, blue) {
      mFadeColorRed = red;
      mFadeColorGreen = green;
      mFadeColorBlue = blue;
      mRed = 0;
      mGreen = 0;
      mBlue = 0;
      mInterval = 1;
      mDelay = delay;

	}

   BootBehavior & operator=(const BootBehavior&) = default;

   void update(long double currentTime) {
      long double delta = (currentTime - mStartTime);
      if (delta > FADE_TO_FINAL + (FADE_TO_FINAL_TIME * 1000.0)) {
         mGreen = mFinalGreen;
         mRed = mFinalRed;
         mBlue = mFinalBlue;
         mInterval = DEFAULT_INTERVAL;

      } else if (delta > FADE_TO_FINAL) {
         double fade = sin((delta - FADE_TO_FINAL) / 1000.0 / FADE_TO_FINAL_TIME * (PI / 2.0));
         mGreen = mFinalGreen * fade;
         mRed = mFinalRed * fade;
         mBlue = mFinalBlue * fade;

      } else if (delta > mDelay + (FADE_IN_AND_OUT_TIME * 1000.0)) {
         mGreen = 0;
         mRed = 0;
         mBlue = 0;
      } else if (delta > mDelay) {
         double fade = sin((delta - mDelay) / 1000.0 / FADE_IN_AND_OUT_TIME * PI);
         mGreen = mFadeColorGreen * fade;
         mRed = mFadeColorRed * fade;
         mBlue = mFadeColorBlue * fade;
      }
   }
};
#endif