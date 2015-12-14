#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // in case you want to do strcpy or something like that

#define READ 0
#define WRITE 1 // This makes the code easier to write. You could always just use regular 0 and 1.

int main(){

  int fds[2];
  int f;
  
  pipe( fds );
  printf("fds[0]: %d\n", fds[0]);
  printf("fds[1]: %d\n", fds[1]);
  
  f = fork();
  if( f == 0 ) {
    close( fds[READ] );
    // float q = 123.456; This is not very common. Instead, you may see something like the child must act as a client for a human interactor. The child with then send the information back to the parent.
    // write( fds[WRITE], &q, sizeof(float) ); // or sizeof( q );
    fgets( line, sizeof(line), stdin );
    write( fds[WRITE], &line, sizeof(line) );
    close( fds[WRITE] );
  }
  else {
    close( fds[WRITE] );
    // float p;
    // read( fds[READ], &p, sizeof(p) );
    read( fds[READ], line, sizeof(line) ); // I'm not sure about this line
    printf("parent read: %f\n", p);
    close ( fds[READ] );
  }

}
