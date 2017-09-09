#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHMSZ     1024

int main( int argc, char *argv[] )
{
	key_t shm_key = 6166529;
	int shm_id;
	char c;

	char* shmaddr, *s;

	shm_id = shmget(shm_key, SHMSZ, IPC_CREAT | 0666);
	shmaddr = (char*)shmat(shm_id, NULL, 0);

	*shmaddr = NULL;

	while(1) {
	    for (s = shm; *s != NULL; s++)
	        putchar(*s);
	    putchar('\n');
		sleep(100);
	}

	return 0;
}