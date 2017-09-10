#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHMSZ     1024
#define CHANNELS     30

int main( int argc, char *argv[] )
{
    key_t shm_key = 8472;
    int shm_id;
    char* shmaddr, *s;

    int size = 1 + 2 * CHANNELS;
    char c;

    shm_id = shmget(shm_key, SHMSZ, IPC_CREAT | 0666);
    shmaddr = (char*)shmat(shm_id, 0, 0);
    s = shmaddr;

    char* status = "1";
    char* channel_r = "00";
    char* channel_g = "00";
    char* channel_b = "00";
    
	if(argc == 4) {
      channel_b = argv[1];
      channel_g = argv[2];
      channel_r = argv[3];
    }

    char* data;
    data = malloc(size);
    strcpy(data, status);

    for(int i = 0; i < CHANNELS/3; i++) {
        strcat(data, channel_r);
        strcat(data, channel_g);
        strcat(data, channel_b);
    }

    for(int i = 0; i < size; i++) {
       *s = data[i];
       s++;	
    }

    return 0;
}