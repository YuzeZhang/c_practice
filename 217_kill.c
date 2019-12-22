#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){ 
  kill(getpid(),SIGQUIT);
  printf("hello/n");
  return 0;
}
