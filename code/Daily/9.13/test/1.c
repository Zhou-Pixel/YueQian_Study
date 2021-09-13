/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:37:03
 * @LastEditTime: 2021-09-13 18:44:07
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.13/test/1.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    int fd = open("a.txt", O_RDWR);
    char buf[10];

    while (1)
    {
        sleep(2);
        read(fd, buf, 10);
        printf("%s\n", buf);
    }
    

    return 0;
}
