/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-16 15:24:38
 * @LastEditTime: 2021-09-16 15:32:51
 * @LastEditors: ZhouGuiqing
 * @Description: 停车课堂练习1
 * @FilePath: /YueQian/code/Daily/9.16/park/park1.c
 */
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    sem_t *sem = sem_open("/mysem", O_CREAT, 0644, 0);
    if (sem == SEM_FAILED)
    {
        perror("get sem failed");
        return -1;
    }
    

    while (1)
    {
        sem_wait(sem);
        printf("停车成功\n");
    }
    
    sem_close(sem);
    return 0;
}
