#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "time.h"

#define TOTAL_CHANNELS 3

void delay_ms(unsigned int howLong);
void delay_us(unsigned int howLong);

int main ()
{
  key_t shm_key = 6166529;
  const int shm_size = 1024;

  int shm_id;
  char* shmaddr, *ptr;
  char* shared_memory[TOTAL_CHANNELS];
  int *p;

  /* Allocate a shared memory segment. */
  shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

  /* Attach the shared memory segment. */
  shmaddr = (char*) shmat (shm_id, 0, 0);

  printf ("shared memory attached at address %p\n", shmaddr);

while(1) {
  printf ("READING");
  /* Start to read data. */
  p = (int *)shmaddr;
  ptr = shmaddr + sizeof (int) * 2;

  for (int i = 0; i < TOTAL_CHANNELS; ++i)
  {
    shared_memory[i] = ptr;
    ptr += *p++;
  }

  for (int i = 0; i < TOTAL_CHANNELS; ++i)
  {
    printf ("|%s", shared_memory[i]);
  }

  //if(*shared_memory[0] == '10' ) {
  //  break;
  //}

  delay_ms(50);
  printf("\e[1;1H\e[2J");
}

  /* Detach the shared memory segment. */
  shmdt (shmaddr);

  /* Deallocate the shared memory segment.*/
  shmctl(shm_id, IPC_RMID, 0);

  return 0;
}

void delay_ms (unsigned int howLong)
{
  struct timespec sleeper, dummy ;
 
  sleeper.tv_sec  = (time_t)(howLong / 1000) ;
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;
 
  nanosleep (&sleeper, &dummy) ;
}