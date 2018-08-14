#include "DmxController.h"
void DmxController::clear() {
	/*
	FT_Open can fail if the ftdi_sio driver is loaded
	use lsmod to check this and rmmod ftdi_sio to remove
	also rmmod usbserial
	*/
	printf(YELLOW "rmmod executed: (ignore errors):" GRAY "\n");
	system("rmmod ftdi_sio");
	system("rmmod usbserial");
	printf(YELLOW "]" RESET" \n");
}

bool DmxController::setup() {
	// The array needs to be filled before using. (Or the DMX will flash)
	memset(mDmxData, 1, 512);
	memset(mStart, 0x00, 1);

	mFTStatus = FT_Open(0, &mFTHandle);
	if (mFTStatus != FT_OK) {
    	      	printf(RED "FT_Open() failed" RESET "\n");
    		return false;
	}

	mFTStatus = FT_SetDataCharacteristics(mFTHandle, FT_BITS_8, FT_STOP_BITS_2,FT_PARITY_NONE);
	if (mFTStatus != FT_OK) {
    		FT_Close(mFTHandle);
    		printf(RED "Can't set characteristics" RESET "\n");
    		return false;
	}

	mFTStatus = FT_SetBaudRate(mFTHandle, 220183.486239);
	if (mFTStatus != FT_OK) {
		FT_Close(mFTHandle);
		printf(RED "Can't set baudrate" RESET "\n");
		return false;
	}

	printf(GREEN "[Setup completed]" RESET "\n");
	return true;
}

void DmxController::setChannel(int channel,
					unsigned char red,
					unsigned char green,
					unsigned char blue) {
	if (red < 0 || green < 0 || blue < 0 || 
		red > 127 || green > 127 || blue > 127) {
		printf(RED "ERROR! Value outside range! This should never happen\n");
	}
	mDmxData[channel * 3 + 1] = red; 
	mDmxData[channel * 3 + 2] = green;
	mDmxData[channel * 3 + 3] = blue;
}

void DmxController::sendData() {
	//Send Dmx
    mFTStatus = FT_SetBreakOn(mFTHandle);
    delay_ms(10);
    mFTStatus = FT_SetBreakOff(mFTHandle);
    delay_us(8);
    mFTStatus = FT_Write(mFTHandle, mStart, sizeof(mStart), &BytesWritten);
    mFTStatus = FT_Write(mFTHandle, mDmxData, sizeof(mDmxData), &BytesWritten);
    delay_ms(25);

}

void DmxController::printData() {
	printf("[");
	for (int i = 0; i < 30; ++i)
	{
		printf("%x, ", mDmxData[i]);
	}
	printf("]\n");
}

unsigned char * DmxController::getData() {
	return mDmxData;
}
