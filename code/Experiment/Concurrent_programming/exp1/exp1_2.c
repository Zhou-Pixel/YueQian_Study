/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 11:17:56
 * @LastEditTime: 2021-09-11 13:05:11
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp1/exp1_2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void printf_pid(void)
{
    printf("%d\n", getpid());
}

int main(int argc, char const *argv[])
{

    atexit(printf_pid);

    for (int i = 0; i < 10; i++)
    {
        pid_t pid1 = fork();
        if (pid1 == 0)
            exit(i);
    }
    sleep(1);

    for (int i = 0; ; i++)
    {
        int status;
        wait(&status);

        
        printf("返回值是%d\n", WEXITSTATUS(status));
        if (WEXITSTATUS(status) == 9)
        {
            printf("完成\n");
            break;
        }
    }
    
    return 0;
}
