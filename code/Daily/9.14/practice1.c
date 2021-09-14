/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 16:25:14
 * @LastEditTime: 2021-09-14 16:41:45
 * @LastEditors: ZhouGuiqing
 * @Description: 0914课堂练习
 * @FilePath: /YueQian/code/Daily/9.14/practice1.c
 */
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void handler_sigint(int signum)
{
    printf("当前pid是%d 信号码是%d\n", getpid(), signum);
}


int main(int argc, char const *argv[])
{
    signal(SIGQUIT, SIG_IGN);

    signal(SIGINT, handler_sigint);
    
    while (1)
    {
        sleep(1);
        printf("正在正常运行\n");
    }
    

    return 0;
}
