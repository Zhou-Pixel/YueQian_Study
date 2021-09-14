/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 18:57:05
 * @LastEditTime: 2021-09-14 09:48:38
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp2/exp2_2_2.c
 */
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int fd = open("test", O_RDWR);

    while (1)
    {
        sleep(3);
        if (fork() == 0)
        {
            char buf[100]={0};
            time_t t = time(NULL);
            sprintf(buf, "%d    %s", getpid(), ctime(&t));
            printf("%s", buf);
            write(fd, buf, strlen(buf));
            exit(0);
        }

        
    }
    
    
    return 0;
}
