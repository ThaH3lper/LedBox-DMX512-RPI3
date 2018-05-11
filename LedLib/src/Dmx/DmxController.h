#ifndef DMXCONTROLLER_H
#define DMXCONTROLLER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset
#include "../FTD2XX/ftd2xx.h"
#include "time.h"
#include "../global.h"

class DmxController {

private:

	FT_STATUS mFTStatus;
	FT_HANDLE mFTHandle;
	unsigned char mDmxData[512];
	unsigned char mStart[1];
	DWORD BytesWritten;

public:

	bool setup();

	void clear();

	void sendData();

	void setChannel(int channel,
					unsigned char red,
					unsigned char green,
					unsigned char blue);

	void printData();

};

#endif