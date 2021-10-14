/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int is_handled = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);
  is_handled = 1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 1 second
  while(1){
    is_handled = 0;
    alarm(5);
    while(!is_handled);
    printf("Turning was right\n");
  } 
  //busy wait for signal to be delivered
  return 0; //never reached
}