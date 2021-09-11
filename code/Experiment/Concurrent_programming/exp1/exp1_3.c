/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 13:17:36
 * @LastEditTime: 2021-09-11 15:18:22
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp1/exp1_3.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void printf_pid(void)
{
    printf("pid=%d\n", getpid());
}
int main(int argc, char const *argv[])
{

    atexit(printf_pid);
    for (int i = 0; i < 10; i++)
    {
        pid_t pid = fork();
        if (pid > 0)
        {
            exit(0);
        }
    }
    
    return 0;
}
