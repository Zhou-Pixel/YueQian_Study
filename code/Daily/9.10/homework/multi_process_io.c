/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-10 19:21:48
 * @LastEditTime: 2021-09-11 10:40:14
 * @LastEditors: ZhouGuiqing
 * @Description: 多进程文件io操作
 * @FilePath: /YueQian/code/Daily/9.10/homework/multi_process_io.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    FILE *fp = fopen("a.txt", "w+");

    pid_t pid1, pid2 = -1;
    pid1 = fork();
    if (pid1 > 0)
    {
        pid2 = fork();
    }
    


    if (pid1 == 0)
    {
        while (1)
        {
            fprintf(fp, "嘻嘻");
            fflush(fp);
            fseek(fp, -strlen("嘻嘻"), SEEK_SET);
            sleep(1);
        }
    }
    
    if (pid2 == 0)
    {
        while (1)
        {
            char buf[40];
            bzero(buf, sizeof(buf));
            fgets(buf, 40, fp);
            printf("%s\n", buf);
            sleep(1);
        }
        
    }

    printf("%d\n",getpid());
    
    
    return 0;
}
