#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(){ 
  pid_t pid;
  pid = fork();
  if(pid < 0){  
    perror("fork error");
    exit(1);
  }
  if(pid == 0){ 
    printf("This is the child!\n");
    printf("pid = %d,ppid = %d\n",getpid(),getppid());//父进程退出前的pid和ppid
    sleep(5);
    printf("\npid = %d,ppid = %d\n",getpid(),getppid());//父进程退出后的pid和ppid
  }else{  
    printf("This is the father!\n");
    sleep(1);
    printf("father process is exited!\n");
  }
  return 0;
}
