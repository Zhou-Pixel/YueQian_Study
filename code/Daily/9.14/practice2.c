/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 16:43:13
 * @LastEditTime: 2021-09-14 17:00:20
 * @LastEditors: ZhouGuiqing
 * @Description: 0914课堂练习2
 * @FilePath: /YueQian/code/Daily/9.14/practice2.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_sigint(int signum)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGFPE);
    sigaddset(&set, SIGTRAP);
    sigprocmask(SIG_UNBLOCK, &set, NULL);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", getpid());
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGFPE);
    sigaddset(&set, SIGTRAP);
    sigprocmask(SIG_BLOCK, &set, NULL);

    signal(SIGINT, handler_sigint);


    while (1)
    {
        sleep(1);
        printf("正常运行中\n");
    }
    
    
    return 0;
}
