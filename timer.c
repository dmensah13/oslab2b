/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int is_handled = 0;
int alarm_count = 0;
time_t start_time;
time_t stop_time;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);
  is_handled = 1;
  alarm_count += 1;
  //exit(1); //exit after printing
}

void sigHandler(int signum){
  int elapsed_time;
  stop_time = time(NULL);
  elapsed_time = stop_time - start_time;
  printf("Alarms Delivered: %d in %d seconds", alarm_count, elapsed_time);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigHandler);
  start_time = time(NULL);
  
  while(1){
    is_handled = 0;
    alarm(5);
    while(!is_handled);
    printf("Turning was right\n");
  } 
  //busy wait for signal to be delivered
  return 0; //never reached
}