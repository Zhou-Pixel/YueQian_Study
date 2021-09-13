/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 19:32:11
 * @LastEditTime: 2021-09-13 19:44:21
 * @LastEditors: ZhouGuiqing
 * @Description: 测试管道文件缓冲区大小
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp2/exp2_3.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{

    int count = 0;
    int pipe_fd[2];
    pipe(pipe_fd);

   long flag = fcntl(pipe_fd[1], F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(pipe_fd[1], F_SETFL, flag);

    while (1)
    {
        if(write(pipe_fd[1], "a", 1) == -1)
            break;
        count++;
    }
    printf("缓冲区大小是%d\n", count);   

    return 0;
}



