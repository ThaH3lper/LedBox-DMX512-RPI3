#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHMSZ     1024

int main( int argc, char *argv[] )
{
  key_t shm_key = 6166529;
  int shm_id;
  char c;

  char* shmaddr, *s;

  shm_id = shmget(shm_key, SHMSZ, 0666);
  shmaddr = (char*)shmat(shm_id, NULL, 0);

  for (c = 'a'; c <= 'z'; c++)
      *s++ = c;
  *s = '*';

    for (s = shmaddr; *s != '*'; s++)
        putchar(*s);
    putchar('\n');

  return 0;
}