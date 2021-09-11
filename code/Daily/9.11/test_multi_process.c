/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 12:23:46
 * @LastEditTime: 2021-09-11 12:32:10
 * @LastEditors: ZhouGuiqing
 * @Description: 分别测试多进程，父进程正常和非正常退出时，子进程的存活情况
 * @FilePath: /YueQian/code/Daily/9.11/test_multi_process.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 * @description: 测试结果：父进程被ctrl+c杀死时，子进程也会被杀死，但是父进程正常退出时，子进程会继续正常运行，并被系统的1号进程收养
 * @param {int} argc
 * @return {*}
 */
int main(int argc, char const *argv[])
{
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        while (1)
        {
            sleep(2);
            printf("第一个\n");
        }
        
    }


    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        while (1)
        {
            sleep(2);
            printf("第二个\n");
        }
        
    }


    // while (1)
    // {
    //     sleep(2);
    //     printf("这是父进程\n");
    // }
    
    
    
    return 0;
}
