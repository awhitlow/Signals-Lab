int hold = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  hold = 1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(!hold); //busy wait for signal to be delivered
  printf("Turing was right!\n");
  return 0;
}
