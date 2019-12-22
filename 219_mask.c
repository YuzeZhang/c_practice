#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigcb(int signum){ 
  printf("receive a signal:%d\n",signum);
}
int main(){ 
  signal(SIGINT, sigcb);//修改停止信号(序号2，键盘ctrl+z)的处理方式为调用sigcb函数
  signal(40, sigcb);//修改信号40的处理方式为调用sigcb函数

  //阻塞所有信号
  sigset_t set, old;
  sigemptyset(&set);//清空信号集合
  sigemptyset(&old);//清空信号集合

  //sigaddset(int signum, sigset_t *set)将指定信号添加到集合
  sigfillset(&set);//将所有的信号都添加到set集合中
  sigprocmask(SIG_BLOCK, &set, &old);//将set中的信号添加到blocked中造成信号阻塞

  printf("presse enter to continue:\n");
  getchar();//在按下回车之前，程序卡在这里

  sigprocmask(SIG_UNBLOCK, &set, NULL);//解除阻塞
  return 0;
}
