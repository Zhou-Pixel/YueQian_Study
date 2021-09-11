/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-10 18:46:20
 * @LastEditTime: 2021-09-10 19:22:11
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.10/homework/multi_process.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void readytoexit(void)
{
    printf("父进程退出了\n");
}

int main(int argc, char const *argv[])
{
    printf("adc\n");
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("def\n");
        switch (getchar())
        {
        case 'a':
            exit(1);
        case 'b':
            exit(2);
        default:
            exit(0);
        }
    }


    atexit(readytoexit);

    int status;
    waitpid(pid, &status, 0);
    
    if (!WIFEXITED(status))
    {
        exit(0);
    }
    

    switch (WEXITSTATUS(status))
    {
    case 1:
        printf("hello\n");
        break;
    case 2:
        printf("world\n");
        break;
    }
    
    exit(0);
}
