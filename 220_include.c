//
// Created by Zeno on 2019/12/22.
//

#include <signal.h>
#include <sys/types.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);  //返回：如果成功则为0，若出错则为-1
int sigismember(const sigset_t *set, int signum); //返回：若signum是sef的成员则为1，如果不是则为0，若出错则为-1
