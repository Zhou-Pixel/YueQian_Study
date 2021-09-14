/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 19:20:03
 * @LastEditTime: 2021-09-14 19:26:45
 * @LastEditors: ZhouGuiqing
 * @Description: 测试管道文件边读边写
 * @FilePath: /YueQian/code/Daily/9.14/test/test_fifo2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    if (access("myfifo", F_OK) == -1)
    {
        mkfifo("myfifo", 0644);
    }

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        int fd = open("myfifo", O_RDWR | O_APPEND | O_CREAT, 0644);
        write(fd, "1:测试有两个程序读取管道文件的", strlen("1:测试有两个程序读取管道文件的"));
        while (1)
        {
            sleep(1);
            char buf[100] = {0};
            read(fd, buf, 100);
            printf("1进程:%s\n", buf);
        }

        close(fd);
        exit(0);
    }

    int fd = open("myfifo", O_RDWR);
    write(fd, "2:测试有两个程序读取管道文件的", strlen("2:测试有两个程序读取管道文件的"));
    while (1)
    {
        sleep(1);
        char buf[100] = {0};
        read(fd, buf, 100);
        printf("2进程:%s\n", buf);
    }

    exit(0);
}
