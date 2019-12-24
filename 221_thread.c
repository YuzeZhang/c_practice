#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_start(void* arg){  
  while(1){ 
    printf("主线程传递了一个参数：%s\n",(char*)arg);
    sleep(1);
  }
  return NULL;
}
int main(){ 
  pthread_t tid;
  char buf[] = "Hello,world!\n";
  int ret = pthread_create(&tid,NULL,thread_start,(void*)buf);
  if(ret != 0){ 
    printf("thread creat eror:%d\n",ret);
    return -1;
  }
  while(1){ 
    printf("我是主线程！\n");
    sleep(1);
  }
  return 0;
}
