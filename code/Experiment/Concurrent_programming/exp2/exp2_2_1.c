/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:56:01
 * @LastEditTime: 2021-09-13 19:22:59
 * @LastEditors: ZhouGuiqing
 * @Description: 服务器
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp2/exp2_2_1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{

    if (access("test", F_OK) == -1)
    {
        mkfifo("test", 0644);
    }

    int fd1 = open("test", O_RDONLY);
    int fd2 = open("a.txt", O_RDWR | O_CREAT, 0644);

    char buf[100];

    while (1)
    {
        bzero(buf, sizeof(buf));
        read(fd1, buf, sizeof(buf));
        write(fd2, buf, strlen(buf));
    }
    
    
    return 0;
}
