/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int hold = 0;
int seconds = 0;

void firstHandler(int signum){ 
  hold = 1;
}

//Executes after CTRL^c is pressed
void nextHandler(int signum){
  printf("Program was running for %d seconds.\n", seconds);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGINT, nextHandler);
  while(1){
    signal(SIGALRM, firstHandler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!hold);
    seconds++;
    hold=0;
  };
  
  //busy wait for signal to be delivered
  return 0; //never reached
}