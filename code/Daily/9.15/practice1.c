/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-15 14:26:45
 * @LastEditTime: 2021-09-15 15:01:13
 * @LastEditors: ZhouGuiqing
 * @Description: 0915课堂练习
 * @FilePath: /YueQian/code/Daily/9.15/practice1.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>



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
        return 0;
    }
    
    int msg_id = msgget(ipc_key, IPC_CREAT | 0644);
    if (msg_id == -1)
    {
        perror("get msg_id failed");
        return 0;
    }
    
    

    struct msgbuf *mymsg = malloc(sizeof(struct msgbuf)+99);


    while (1)
    {
        mymsg->mtype = 1;
        bzero(mymsg->mtext, 100);
        fgets(mymsg->mtext, 100, stdin);
        strtok(mymsg->mtext, "\n");
        int retvalue = msgsnd(msg_id, mymsg, strlen(mymsg->mtext), 0);
        if (retvalue == -1)
        {
            perror("send msg failed");
            continue;
        }
    }
    
    

    return 0;
}


