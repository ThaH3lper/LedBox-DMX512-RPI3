#ifndef TEST_H
#define TEST_H

#include <unistd.h> //Sleep
#include "global.h"
#include <stdlib.h>
#include <string>
#include <cmath>

int main (int argc, char *argv[])
{
	long double mStartTime = getCurrentTimeMS();

    long double mSpeed = 30 * 1000;
    long double mPartSpeed = 30 * 1000 / 6;
    signed char mMaxValue = 127;
	signed char mRed;
	signed char mGreen;
	signed char mBlue;

	while(true) {
		printf("start\n");


         long double currentTime = getCurrentTimeMS();

		 long double value = std::fmod((currentTime - mStartTime), mSpeed);
         double partValue = std::fmod(value, mPartSpeed);
         printf("%f\n", partValue);
         if (value <= mPartSpeed) {
            printf("1   ");
            mRed = mMaxValue;
            mBlue = partValue / mPartSpeed * mMaxValue * 1.0;
            mGreen = 0;
         } else if (value > mPartSpeed && value <= mPartSpeed * 2) {
            printf("2   ");
            mRed = (1.0 - (partValue / mPartSpeed)) * mMaxValue;
            mBlue = mMaxValue;
            mGreen = 0;
         } else if (value > mPartSpeed * 2 && value <= mPartSpeed * 3) {
            printf("3   ");
            mRed = 0;
            mBlue = mBlue;
            mGreen = partValue / mPartSpeed * mMaxValue * 1.0;
         } else if (value > mPartSpeed * 3 && value <= mPartSpeed * 4) {
            printf("4   ");
            mRed = 0;
            mBlue = (1.0 - (partValue / mPartSpeed)) * mMaxValue;
            mGreen = mMaxValue;
         } else if (value > mPartSpeed * 4 && value <= mPartSpeed * 5) {
            printf("5   ");
            mRed = partValue / mPartSpeed * mMaxValue * 1.0;
            mBlue = 0;
            mGreen = mMaxValue;
         } else if (value > mPartSpeed * 5) {
            printf("6   ");
            mRed = mMaxValue;
            mBlue = 0;
            mGreen = (1.0 - (partValue / mPartSpeed)) * mMaxValue;
         }
         printf("%i %i %i\n", mRed, mGreen, mBlue);

        delay_ms(200);
    }
	return 0;
}
#endif