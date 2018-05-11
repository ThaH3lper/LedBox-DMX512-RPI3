#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/types.h> //key_t
#include "time.h" //nanosleep
#include <math.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define GRAY    "\x1b[90m"
#define RESET   "\x1b[0m"

#define PI 3.14159265

#define B_FADE_TO_SIMPLE 1
#define B_SIN_CURVE 2

void delay_ms (unsigned int howLong);
void delay_us (unsigned int howLong);
unsigned char getColorValue (double value);


namespace global {

	const key_t SMK_DATA = 5623; // Key for Shared preference data
	const key_t SMK_SERVER_STATUS = 7482; // Key for Shared preference holding server status
	const int MAX_CHANNEL_DATA = 11;
	const int MAX_CHANNELS = 10;
	const int DATA_SIZE = 110; // MAX_CHANNELS * CHANNEL_MAX_DATA
}
#endif