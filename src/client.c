#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHMSZ     1024

int main( int argc, char *argv[] )
{
  key_t shm_key = 6166529;
  int shm_id;

  char* shmaddr;

  shm_id = shmget(shm_key, shm_size, 0666);
  shmaddr = (char*)shmat(shm_id, 0, 0);

  for (c = 'a'; c <= 'z'; c++)
      *s++ = c;
  *s = NULL;

    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');

  return 0;
}