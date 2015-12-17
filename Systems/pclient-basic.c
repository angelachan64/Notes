#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

  int to_server;
  int from_server;
  char buffer[100];
  
  to_server = client_handshake( &from_server );

}
