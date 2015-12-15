#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

  int from_client;
  int e;
  char line[100];
  
  e = mkfifo( "mario", 0644 );
  printf("<server> pipe created: %d\n", e);
  
  from_client = open( "mario", O_RDONLY ); // Using O_APPEND or O_TRUNC wouldn't mean anything in terms of pipes
  printf( "<server> pipe open\n" );
  remove("mario");
  
  read( from_client, line, sizeof(line) );
  printf( "<server> read: [%s]\n", line );
  
  close( from_client );
  
  return 0;
}
