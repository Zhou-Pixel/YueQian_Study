/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 11:07:43
 * @LastEditTime: 2021-09-11 11:14:51
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp1/exp1_1.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        for (unsigned char ch = 97; ; ch++)
        {
            if (ch == 'z')
            {
                ch = 'a';
            }
            
            printf("%c\n", ch);
            sleep(1);
        }
        
        exit(0);
    }


    for (int i = 0; ; i++)
    {
        sleep(1);
        printf("%d\n", i);
    }
    
    
    return 0;
}
