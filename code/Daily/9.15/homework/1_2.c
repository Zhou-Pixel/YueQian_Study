/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-15 18:39:39
 * @LastEditTime: 2021-09-15 20:30:12
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.15/homework/1_2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <pthread.h>


struct msgbuf
{
    long mtype;
    char mtext[1];
};

int ipc_key;
int msg_id;



void *rev_msg(void *none)
{
    struct msgbuf *revbuf = malloc(sizeof(struct msgbuf) + 99);

    while (1)
    {
        bzero(revbuf, sizeof(struct msgbuf) + 99);
        msgrcv(msg_id, revbuf, 100, 1, 0);
        printf("收到消息:%s\n", revbuf->mtext);
    }
}


int main(int argc, char const *argv[])
{

    ipc_key = ftok(".", 1);
    if (ipc_key == -1)
    {
        perror("get ipc_key failed");
        return 0;
    }

    msg_id = msgget(ipc_key, IPC_CREAT | 0644);
    if (msg_id == -1)
    {
        perror("get msg_id failed");
        return 0;
    }

    pthread_t t;
    pthread_create(&t, NULL, rev_msg, NULL);

    struct msgbuf *send_msg = malloc(sizeof(struct msgbuf) + 99);
    while (1)
    {
        bzero(send_msg->mtext, 100);
        send_msg->mtype = 2;
        fgets(send_msg->mtext, 100, stdin);
        int revl = msgsnd(msg_id, send_msg, strlen(send_msg->mtext), 0);      
    }

    
    
    return 0;
}

