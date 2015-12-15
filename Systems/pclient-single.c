#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

  int to_server;
  char line[100];
  
  to_server = open( "mario", O_WRONLY );
  printf( "<client> pipe open" );
  
  printf( "<client> enter stuff: " );
  fgets( line, sizeof(line), stdin ); // You can read in one less than sizeof(line) to ensure you always have a terminating null at the end of your string
  write( to_server, line, sizeof(line) );
  
  close(to_server);

  return 0;
}
