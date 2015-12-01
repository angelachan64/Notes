#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler( int signo ){ //sighandler and signo can be different
  if ( signo == SIGINT ) //all signals are caught with this one function{
    printf(“Interrupted… how rude!\n”);
    exit(0);
  }
  
  else if (signo == SIGKILL ){
    printf("I'm unstoppable!\n"); // This will not print because SIGKILL can't be caught
  }
  
  else if ( signo == SIGSEGV )
    printf("Nothing to see here...\n");
}

int main(){

  signal( SIGINT, sighandler ); //attaches sighandler to the signal sent
  signal( SIGSEGV, sighandler );
  
  int *p = 0;
  *p = 123;
  /* The above code won't work, and instead will trigger a segfault. However, the OS will still realize
  that there is a segfault and will continue to send the signal. This will create an infinite loop. */

  int i = 0;
  while(1){
    printf(“G’day mate!\t%d\t%d\n”, i++, getpid());
    sleep(1);
  }

  return 0;
}
