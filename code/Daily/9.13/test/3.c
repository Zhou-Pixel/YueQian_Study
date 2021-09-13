/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:45:48
 * @LastEditTime: 2021-09-13 18:48:35
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.13/test/3.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int fd = open("a.txt", O_RDWR | O_TRUNC);


    if (fork() == 0)
    {
        close(fd);
        exit(0);
    }
    
    wait(NULL);
    
    write(fd, "zhou", 4);

    return 0;
}


