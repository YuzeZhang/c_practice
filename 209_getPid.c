//
// Created by Zeno on 2019/12/7.
//

#include <unistd.h>
pid_t getpid(void); //返回值：调用进程的进程ID
pid_t getppid(void); //返回值：调用进程的父进程ID

#include<sys/types.h>
uid_t getuid(void); //返回值：调用进程的实际用户ID
uid_t geteuid(void); //返回值：调用进程的有效用户ID

gid_t getgid(void); //返回值：调用进程的实际组ID
gid_t getegid(void); //返回值：调用进程的有效组ID

