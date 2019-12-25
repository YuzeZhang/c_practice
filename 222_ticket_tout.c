#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int tickets = 100;
pthread_mutex_t mutex;

void* thr_tout(void* arg){  
  while(1){ 
  pthread_mutex_lock(&mutex);
  if(tickets > 0){  
    usleep(1500);
    printf("tout:%p - get a ticket:%d\n",(void*)pthread_self(),tickets);
    tickets--;
    pthread_mutex_unlock(&mutex);
  }else{  
    pthread_exit(NULL);
  }
  }
  return NULL;
}

int main(){ 
  int i = 0, ret;
  pthread_t tid[4];
  //互斥锁的初始化
  pthread_mutex_init(&mutex,NULL);
  for(; i < 4; i++){  
    ret = pthread_create(&tid[i],NULL,thr_tout,NULL);
    if(ret != 0){ 
      printf("thread create error\n");
      return -1;
    }
  }
  for(i = 0 ; i < 4; i++){  
    pthread_join(tid[i],NULL);
  }
  return 0;
}
