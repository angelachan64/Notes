#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

  int socket_id, socket_client;
  
  //create the socket
  socket_id = socket( AF_INET, SOCK_STREAM, 0 );
  // There are four things we need to keep in mind
  // - What is the IP address?
  // - What is the port?
  // - What TYPE of IP address is it?
  // - What is the protocol?
  // AF_INET is an IPv4 address, AF_INET6 is an IPv6 address
  // SOCK_STREAM is TCP, SOCK_DGRAM for UDP
  
  // bind to port/address
  struct sockaddr-in listener;
  listener.sin_family = AF_INET; //socket type IPv4
  listener.sin_port = htons(5000); //port #
  listener.sin_addr.s_asddr = INADDR_ANY; //bind to any incoming address
  bind(socket_id, (struct sockaddr *)&listener, sizeof(listener)
  
  listen( socket_id, 1 ); 
  // the number used to show how many sockets had to wait before it could use the socket, but now it has no purpose. However, you must still include this number
  printf("<server> listening\n");
  
  socket_client = accept( socket_id, NULL, NULL );
  printf("<server> connected: %d\n", socket_client);
  
  write( socket_client, "hello", 6 );
  
  close(socket_client);
  close(socket_id);

}
