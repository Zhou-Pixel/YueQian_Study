/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-16 19:56:58
 * @LastEditTime: 2021-09-16 20:28:29
 * @LastEditors: ZhouGuiqing
 * @Description: POSIX信号量和共享内存1.c
 * @FilePath: /YueQian/code/Daily/9.16/homework/3_1.c
 */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <strings.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int ipc_key = ftok(".", 1);
    if (ipc_key == -1)
    {
        perror("get ipc_key failed");
        return -1;
    }

    int shm_id = shmget(ipc_key, 4096, IPC_CREAT | 0644);
    if (shm_id == -1)
    {
        perror("get shm_id failed");
        return -1;
    }

    char *shm_p = shmat(shm_id, NULL, 0);
    if (shm_p == (void *) -1)
    {
        perror("get shm_p failed");
        return -1;
    }
    
    sem_t *sem = sem_open("/my_sem", O_CREAT, 0644, 0);
    if (sem == SEM_FAILED)
    {
        perror("get sem failed");
        return -1;
    }
    
    bzero(shm_p, 4096);
    while (1)
    {
        fgets(shm_p, 4096, stdin);
        strtok(shm_p, "\n");
        sem_post(sem);
    }
        

    return 0;
}
