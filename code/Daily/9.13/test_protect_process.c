/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-13 10:40:59
 * @LastEditTime: 2021-09-13 11:08:01
 * @LastEditors: ZhouGuiqing
 * @Description: 守护进程的课堂练习
 * @FilePath: /YueQian/code/Daily/9.13/test_protect_process.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <syslog.h>
#include <unistd.h>


#include "daemon.h"


int main(int argc, char const *argv[])
{
    daemon_init();

    FILE *fp = fopen("/home/gec/git/YueQian/code/Daily/9.13/a.txt", "r");
    if (fp == NULL)
    {
        return 0;
    }
    
    char buf[10];
    
    openlog("zhou", LOG_PID, LOG_DAEMON);
    
    
    while (1)
    {
        bzero(buf, 10);
        if(fgets(buf, 10, fp) == NULL)
            break;
        sleep(2);
        syslog(LOG_INFO, "%s", buf);

    }
    closelog();
    fclose(fp);

    return 0;
}
