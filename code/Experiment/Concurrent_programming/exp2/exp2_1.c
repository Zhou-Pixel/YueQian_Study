/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:54:19
 * @LastEditTime: 2021-09-14 09:39:19
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp2/exp2_1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int pipe_fd[2];
    if(pipe(pipe_fd) == -1)
        return 0;

    pid_t pid = fork();

    if (pid == 0)
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        execlp("ls", "ls", "/etc", NULL);
        printf("测试\n");
        exit(0);
    }

    // char buf[100] = {0};
    // sprintf(buf, "test");
    // write(pipe_fd[1], buf, strlen(buf));
    close(pipe_fd[1]);
    dup2(pipe_fd[0], STDIN_FILENO);

    execlp("wc", "wc", "-w", NULL);


    exit(0);

    return 0;
}
