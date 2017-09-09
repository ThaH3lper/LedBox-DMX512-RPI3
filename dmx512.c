#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ftd2xx.h"
#include "time.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
 
#define JOY_DEV "/dev/input/js0"
 
BYTE Start[] = {0x00};
BYTE MAB[256] = {0};
BYTE DMX_Data[512];
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
float fAxis;
 
//////////////////////////////////// JOYSTICK Definitions /////////////////////////////
/*int f;
int joy_fd, *axis=NULL, num_of_axis=0, num_of_buttons=0, x;
char *button=NULL, name_of_joystick[80];
struct js_event js;
 
if( ( joy_fd = open( JOY_DEV , O_RDONLY)) == -1 )
{
printf( "Couldn't open joystick\n" );
return -1;
}
 
ioctl( joy_fd, JSIOCGAXES, &num_of_axis );
ioctl( joy_fd, JSIOCGBUTTONS, &num_of_buttons );
ioctl( joy_fd, JSIOCGNAME(80), &name_of_joystick );
 
axis = (int *) calloc( num_of_axis, sizeof( int ) );
button = (char *) calloc( num_of_buttons, sizeof( char ) );
 
printf("Joystick detected: %s\n\t%d axis\n\t%d buttons\n\n"
, name_of_joystick
, num_of_axis
, num_of_buttons );
 
fcntl( joy_fd, F_SETFL, O_NONBLOCK ); /* use non-blocking mode */
///////////////////////////////////////////////////////////////////////////////////////
 
 
////////////////////////////////////////// DMX ////////////////////////////////////////
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
 
ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_2,FT_PARITY_NONE);
if(ftStatus != FT_OK)
{
FT_Close(ftHandle);
                printf("Can't set characteristics\n");
                return 1;
}
 
ftStatus = FT_SetBaudRate(ftHandle,120000);
        if(ftStatus != FT_OK) {
                FT_Close(ftHandle);
                printf("Can't set baudrate\n");
                return 1;
        }
//////////////////////////////////////////////////////////////////////////////////////////
 
memset(&DMX_Data[0],0,sizeof(DMX_Data));

printf( "ALLGOOD");
 
while(1)
{       
 
//////////////////////////////// Read Joystick data /////////////////////////////
//read(joy_fd, &js, sizeof(struct js_event));
///* see what to do with the event */
//switch (js.type & ~JS_EVENT_INIT)
//{
//case JS_EVENT_AXIS:
//axis   [ js.number ] = js.value;
//break;
//case JS_EVENT_BUTTON:
//button [ js.number ] = js.value;
//break;
//}
// 
///* print the results */
////printf( "X: %6d  Y: %6d  ", axis[0], axis[1] );
// 
////if( num_of_axis > 2 )
//// printf("Z: %6d  ", axis[2] );
// 
////if( num_of_axis > 3 )
//// printf("R: %6d  ", axis[3] );
// 
////for( x=0 ; x<num_of_buttons ; ++x )
//// printf("B%d: %d  ", x, button[x] );
// 
//                
// 
// 
//if(axis[0] < 0)
//{
//if(DMX_Data[0] != 0)
//DMX_Data[0] -= 5;
//}
// 
//else if(axis[0] > 0)
//{
//if(DMX_Data[0] < 0xFF)
//DMX_Data[0] += 5;
//}
// 
//else{}
// 
// 
//if(axis[1] < 0)
//                {
//                        if(DMX_Data[2] != 0)
//                        DMX_Data[2] -= 5;
//                }
// 
//                else if(axis[1] > 0)
//                {
//                        if(DMX_Data[2] < 0xFF)
//                        DMX_Data[2] += 5;
//                }
// 
//                else{}
// 
// 
//if(button[0] == 1)
//{
//DMX_Data[5] = 0xFF;
//  DMX_Data[7] = 0xFF;
//}
// 
//if(button[1] == 1)
//                {
//                        DMX_Data[5] = 0xFF;
//                        DMX_Data[6] = 0xFF;
//                }
// 
//if(button[2] == 1)
//                {
//                        DMX_Data[5] = 0xFF;
//                        DMX_Data[8] = 0xFF;
//                }
// 
//       if(button[3] == 1)
//                {
//                        DMX_Data[5] = 0x00;
//                        DMX_Data[6] = 0x00;
//DMX_Data[7] = 0x00;
//                        DMX_Data[8] = 0x00;
// 
//                }

for (int i = 0; i < 500; i++)
{
	DMX_Data[i] = 255;
}

 
//////////////////////////////////////////////////////////////////////////////////
 printf( "Begin Write");
/////////////////////////// Send DMX512 Packet ///////////////////////////////////
ftStatus = FT_SetBreakOn(ftHandle);
delay_ms(10); //10ms delay
ftStatus = FT_SetBreakOff(ftHandle);
delay_us(8);
ftStatus = FT_Write(ftHandle,Start,sizeof(Start),&BytesWritten);
ftStatus = FT_Write(ftHandle,DMX_Data,sizeof(DMX_Data),&BytesWritten);
delay_ms(500);
printf( "success Write");
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