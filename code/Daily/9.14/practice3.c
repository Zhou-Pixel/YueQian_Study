/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 17:04:20
 * @LastEditTime: 2021-09-14 17:13:19
 * @LastEditors: ZhouGuiqing
 * @Description: 0914课堂练习3
 * @FilePath: /YueQian/code/Daily/9.14/practice3.c
 */
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void handler_sigint(int signum)
{
    int fd =  open("a.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
    {
        return;
    }
    char buf[100] = {0};
    fgets(buf, 100, stdin);
    write(fd, buf, strlen(buf));
    close(fd);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, handler_sigint);
    while (1)
    {
        sleep(1);
    }
    
    return 0;
}

