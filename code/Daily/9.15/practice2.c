/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-15 14:50:03
 * @LastEditTime: 2021-09-15 14:57:33
 * @LastEditors: ZhouGuiqing
 * @Description: 0915课堂练习2
 * @FilePath: /YueQian/code/Daily/9.15/practice2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <strings.h>

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[1];    /* message data */
};

int main(int argc, char const *argv[])
{
    key_t ipc_key = ftok(".", 1);
    if (ipc_key == -1)
    {
        perror("get ipc_key failed");
        exit(0);
    }

    int msg_id = msgget(ipc_key, IPC_CREAT | 0644);
    if (msg_id == -1)
    {
        perror("get msg_id failed");
        exit(0);
    }

    struct msgbuf *revbuf = malloc(sizeof(struct msgbuf) + 99);

    while (1)
    {
        bzero(revbuf, sizeof(struct msgbuf) + 99);
        msgrcv(msg_id, revbuf, 100, 1, 0);

        printf("收到消息:%s\n", revbuf->mtext);
    }
    

    
    return 0;
}
