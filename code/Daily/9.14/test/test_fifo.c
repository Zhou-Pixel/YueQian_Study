/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 17:19:14
 * @LastEditTime: 2021-09-14 17:29:51
 * @LastEditors: ZhouGuiqing
 * @Description: 测试有两个程序同时读管道文件的情况
 * @FilePath: /YueQian/code/Daily/9.14/test/test_fifo.c
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
        write(fd, "测试有两个程序读取管道文件的", strlen("测试有两个程序读取管道文件的"));
        close(fd);
        exit(0);
    }
    
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        int fd = open("myfifo", O_RDWR);
        char buf[100] = {0};
        read(fd, buf, 100);
        printf("2进程:%s\n", buf);
        exit(0);
    }
    
    int fd = open("myfifo", O_RDWR);
    char buf[100] = {0};
    read(fd, buf, 100);
    printf("3进程:%s\n", buf);
    wait(NULL);
    wait(NULL);
    exit(0);
    
    
    return 0;
}



