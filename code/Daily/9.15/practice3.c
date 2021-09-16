/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-15 16:12:43
 * @LastEditTime: 2021-09-15 16:44:45
 * @LastEditors: ZhouGuiqing
 * @Description: 0915共享内存课堂练习
 * @FilePath: /YueQian/code/Daily/9.15/practice3.c
 */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int ipc_key = ftok(".", 1);

    if (ipc_key == -1)
    {
        perror("get ipc_key failed");
        return 0;
    }
    
    int shm_id = shmget(ipc_key, 4096, IPC_CREAT | 0644 | O_APPEND);
    
    if (shm_id == -1)
    {
        perror("get shm_id failed");
        return 0;
    }
    


    char *shmaddr = shmat(shm_id, NULL, 0);

    scanf("%s", shmaddr);


    shmdt(shmaddr);    

    return 0;
}

