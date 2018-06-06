#include "global.h"

void delay_ms (unsigned int howLong)
{
  struct timespec sleeper, dummy ;
 
  sleeper.tv_sec  = (time_t)(howLong / 1000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;
 
  nanosleep (&sleeper, &dummy) ;
};

void delay_us (unsigned int howLong)
{
  struct timespec sleeper, dummy ;
 
  sleeper.tv_sec  = (time_t)(howLong / 1000000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000 ;
 
  nanosleep (&sleeper, &dummy) ;
};

unsigned char getColorValue (double value)
{
	return 127 * pow((value * 0.9) + 0.1, 2.5);
};

long double getCurrentTimeMS ()
{
	struct timespec gettime_now;
	clock_gettime(CLOCK_REALTIME, &gettime_now);
	
	time_t s = gettime_now.tv_sec;
	long ms = round(gettime_now.tv_nsec / 1.0e6);
	if (ms > 999) {
	    s++;
	    ms = 0;
	}

	return (s * 1000.0) + ms;
};
