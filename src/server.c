#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "ftd2xx.h"
#include "time.h"
#include <fcntl.h>
#include <sys/ioctl.h>

#define SHMSZ      1024
#define CHANNELS     30

void delay_ms(unsigned int howLong);
void delay_us(unsigned int howLong);

BYTE Start[] = {0x00};
BYTE MAB[256] = {0};
BYTE DMX_Data[512];
DWORD   BytesWritten;
char* OldString = "old";

char* TAG = "[Led Server]";

int main( int argc, char *argv[] )
{
	DWORD dwBytesInQueue = 0;
	EVENT_HANDLE eh;
	FT_STATUS ftStatus;
	FT_HANDLE ftHandle;
	int iport = 0;

	key_t shm_key = 8472;
	int shm_id;
    int size = 1 + 2 * CHANNELS;
	char c;

	char* shmaddr, *s;

	shm_id = shmget(shm_key, SHMSZ, IPC_CREAT | 0666);
	shmaddr = (char*)shmat(shm_id, 0, 0);

    ftStatus = FT_Open(iport, &ftHandle);
	if (ftStatus != FT_OK) {
    	/* 
    	This can fail if the ftdi_sio driver is loaded
    	use lsmod to check this and rmmod ftdi_sio to remove
    	also rmmod usbserial
    	*/
    	printf("FT_Open(%d) failed\n", iport);
    	return 1;
	}
 
	ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_2,FT_PARITY_NONE);
	if (ftStatus != FT_OK) {
    	FT_Close(ftHandle);
    	printf("Can't set characteristics\n");
    	return 1;
	}
 
	ftStatus = FT_SetBaudRate(ftHandle, 120000);
	if (ftStatus != FT_OK) {
		FT_Close(ftHandle);
		printf("Can't set baudrate\n");
		return 1;
	}
	memset(&DMX_Data[0],0,sizeof(DMX_Data));

	s = shmaddr;

    char* status = "0";
    char* channel_value = "FF";
    char* data;
    data = malloc(size);
    strcpy(data, status);
    for (int i = 0; i < CHANNELS; i++) {
        strcat(data, channel_value);
    }
    for (int i = 0; i < size; i++) {
       *s = data[i];
       s++;	
    }
    s = shmaddr;

    for (int i = 0; i < 512; i++) {
		DMX_Data[i] = 255;
	}
    printf("%s Started sucessfully", TAG);
    int running = 1;
	while(running) {
        switch(s*) {
            case '9':
                running = false;
            break;
        }
        if(strcmp(s, OldString) != 0) {
            *OldString = *s;
            for (int i = 0; i < CHANNELS; i++) {
                int pos = i * 2 + 1;
    			char subbuff[3];
    			memcpy( subbuff, &s[pos], 2);
    			subbuff[3] = '\0';
    			
    			DMX_Data[i] = strtol(subbuff, NULL, 16);
    		}

    		ftStatus = FT_SetBreakOn(ftHandle);
    		delay_ms(10);
    		ftStatus = FT_SetBreakOff(ftHandle);
    		delay_us(8);
    		ftStatus = FT_Write(ftHandle, Start, sizeof(Start), &BytesWritten);
    		ftStatus = FT_Write(ftHandle, DMX_Data, sizeof(DMX_Data), &BytesWritten);
            printf("%s Changed Color", TAG);
    		delay_ms(1000);
            //for(int i = 0; i < CHANNELS; i++) {
            //   printf("%i",DMX_Data[i]);
            //}
            //putchar('\n');
        } else {
            delay_ms(1000);
        }
    }
    printf("%s Closed sucessfully", TAG);

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