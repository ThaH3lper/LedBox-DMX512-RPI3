#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define TOTAL_CHANNELS 30

int main( int argc, char *argv[] )
{
	key_t shm_key = 6166529;
	const int shm_size = 1024;

	int shm_id;
	int* shmaddr, *ptr;
	int next[TOTAL_CHANNELS];
	int channelValue = 0;

   if( argc == 2 ) {
   	int num;
	sscanf (argv[1],"%d",&num);
      channelValue = num;
   }

	printf("writer started.\n");

	/* Allocate a shared memory segment. */
	shm_id = shmget(shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

	/* Attach the shared memory segment. */
	shmaddr = (int*)shmat(shm_id, 0, 0);

	printf("shared memory attached at address %p\n", shmaddr);

	/* Start to write data. */
	ptr = shmaddr + sizeof(next);
	for (int i = 0; i < TOTAL_CHANNELS; ++i)
	{
		next[i] = channelValue;
	}
	memcpy(shmaddr, &next, sizeof(next));
	printf("writer ended.\n");

	/*calling the other process*/
	//system("./read");
	getchar();

	/* Detach the shared memory segment. */
	shmdt(shmaddr);

	return 0;
}