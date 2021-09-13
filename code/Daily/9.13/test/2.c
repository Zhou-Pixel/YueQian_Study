/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:39:35
 * @LastEditTime: 2021-09-13 18:43:12
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.13/test/2.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    int fd = open("a.txt", O_RDWR);


    while (1)
    {
        sleep(1);
        printf("%ld\n", lseek(fd, 0, SEEK_CUR));
    }
    
    return 0;
}
