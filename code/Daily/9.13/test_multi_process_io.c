/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 17:10:14
 * @LastEditTime: 2021-09-13 17:15:57
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.13/test_multi_process_io.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    int fd = open("a.txt", O_RDWR);


    pid_t pid = fork();
    if (pid == 0)
    {
        char buf[10];
        while (1)
        {
            sleep(1);
            read(fd, buf, sizeof(buf));
        }
        
        exit(0);
    }


    while (1)
    {
        sleep(1);
        printf("当前位置:%ld\n", lseek(fd, 0, SEEK_CUR));
    }
    
    
    return 0;
}
