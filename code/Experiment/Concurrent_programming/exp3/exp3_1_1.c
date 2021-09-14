/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 18:45:06
 * @LastEditTime: 2021-09-14 20:25:35
 * @LastEditors: ZhouGuiqing
 * @Description: 售票员
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp3/exp3_1_1.c
 */
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char input_fgets_char(void)
{
    char buf[100];
    while (1)
    {
        bzero(buf, sizeof(buf));
        fgets(buf, 100, stdin);
        if (strlen(buf) <= 2)
        {
            break;
        }
        printf("格式不对，请重新输入\n");
    }
    return buf[0];
}

void handler_sigrtmin(int signum)
{
    printf("全部下车\n");
    exit(0);
}

int main(int argc, char const *argv[])
{
    signal(SIGRTMIN, handler_sigrtmin);

    int fd = open("myfifo", O_RDWR);
    if (fd == -1)
    {
        perror("open failed");
        return 0;
    }

    pid_t pid;
    char buf[100] = {0};
    read(fd, buf, 100);
    sscanf(buf, "driver:%d", &pid);



    char buf2[100] = {0};
    sprintf(buf2, "conductor:%d", getpid());
    write(fd, buf2, strlen(buf2));

    while (1)
    {
        switch (input_fgets_char())
        {
        case 'a':
            kill(pid, SIGRTMIN);
            break;
        case 'b':
            kill(pid, SIGRTMAX);
            break;
        }
    }

    return 0;
}
