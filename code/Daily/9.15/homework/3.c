/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-15 19:59:08
 * @LastEditTime: 2021-09-15 20:03:21
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.15/homework/3.c
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

    struct shmid_ds shm_info;
    shmctl(shm_id, IPC_STAT, &shm_info);
    printf("当前共享内存有:%lu个字节", shm_info.shm_segsz);
    shmctl(shm_id, IPC_RMID, NULL);

    shmdt(shmaddr);    

    return 0;
}

