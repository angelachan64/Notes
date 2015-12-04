#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  
  int sd;
  int *x;
  int key = ftok("makefile", 78);
  
  sd = shmget( key, sizeof(int), 0644 | IPC_CREAT );
  printf("sd: %d\n", sd);
  
  x = shmat( sd, 0, 0 );
  *x = 0;
  // Some more things here I think?
}
