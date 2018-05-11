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