#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ftd2xx.h"
#include "time.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
 
BYTE Start[] = {0x00};
BYTE MAB[256] = {0};
BYTE DMX_Data[35];
DWORD   BytesWritten;
 
void delay_ms(unsigned int howLong);
void delay_us(unsigned int howLong);
 
int main(void)
{
	DWORD dwBytesInQueue = 0;
	EVENT_HANDLE eh;
	FT_STATUS ftStatus;
	FT_HANDLE ftHandle;
	int iport = 0;
 
	ftStatus = FT_Open(iport, &ftHandle);
	if(ftStatus != FT_OK) {
	/* 
	This can fail if the ftdi_sio driver is loaded
	use lsmod to check this and rmmod ftdi_sio to remove
	also rmmod usbserial
	*/
	printf("FT_Open(%d) failed\n", iport);
	return 1;
	}
	printf( "FT_OPEN DONE");
 
	ftStatus = FT_SetDataCharacteristics(ftHandle, 8, 2, 0);
	if(ftStatus != FT_OK)
	{
	FT_Close(ftHandle);
					printf("Can't set characteristics\n");
					return 1;
	}

//
ftStatus = FT_SetDivisor(ftHandle,12);
ftStatus = FT_SetFlowControl(ftHandle, 0, 0, 0);
ftStatus = FT_ClrRts(ftHandle);
ftStatus = FT_Purge(ftHandle, 2);
ftStatus = FT_Purge(ftHandle, 1);
//
 
	ftStatus = FT_SetBaudRate(ftHandle,240000);
			if(ftStatus != FT_OK) {
					FT_Close(ftHandle);
					printf("Can't set baudrate\n");
					return 1;
			}
	//////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////
 
	memset(&DMX_Data[0],0,sizeof(DMX_Data));

	printf( "ALLGOOD");
 
	while(1)
	{       
memset(&DMX_Data[1],100,1);
memset(&DMX_Data[2],100,1);
memset(&DMX_Data[3],100,1);
//DMX_Data[1] = 0x64;
//DMX_Data[2] = 0x64;
//DMX_Data[3] = 0x64;

		/////////////////////////// Send DMX512 Packet ///////////////////////////////////
		ftStatus = FT_SetBreakOn(ftHandle);
		delay_ms(10); //10ms delay
		ftStatus = FT_SetBreakOff(ftHandle);
		delay_us(8);
		ftStatus = FT_Write(ftHandle,Start,sizeof(Start),&BytesWritten);
BytesWritten = 0;
		ftStatus = FT_Write(ftHandle,DMX_Data,sizeof(DMX_Data),&BytesWritten);
		delay_ms(15);
		//////////////////////////////////////////////////////////////////////////////////
 
		}
 
	return 0;
}
 
void delay_ms (unsigned int howLong)
{
  struct timespec sleeper, dummy ;
 
  sleeper.tv_sec  = (time_t)(howLong / 1000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;
 
  nanosleep (&sleeper, &dummy) ;
}
 
 
void delay_us (unsigned int howLong)
{
  struct timespec sleeper, dummy ;
 
  sleeper.tv_sec  = (time_t)(howLong / 1000000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000 ;
 
  nanosleep (&sleeper, &dummy) ;
}