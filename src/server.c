#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHMSZ     1024

int main( int argc, char *argv[] )
{
	key_t shm_key = 8472;
	int shm_id;
	char c;

	char* shmaddr, *s;

	shm_id = shmget(shm_key, SHMSZ, IPC_CREAT | S_IRUSR | S_IWUSR);
	shmaddr = (char*)shmat(shm_id, NULL, 0);

	*shmaddr = '*';

	while(1) {
	    for (s = shmaddr; *s != '*'; s++)
	        putchar(*s);
	    putchar('\n');
		sleep(100);
	}

	return 0;
}