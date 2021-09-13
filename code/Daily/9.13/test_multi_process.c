/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 11:10:36
 * @LastEditTime: 2021-09-13 17:17:36
 * @LastEditors: ZhouGuiqing
 * @Description: 用来调用写系统日志的程序
 * @FilePath: /YueQian/code/Daily/9.13/test_multi_process.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    pid_t pid = vfork();
    if (pid == 0)
    {
        execl("test", "test", NULL);
        exit(0);
    }
    
    printf("程序正在运行\n");
    printf("%d\n", pid);
    waitpid(pid, NULL, 0);

    exit(0);
    

    return 0;
}


