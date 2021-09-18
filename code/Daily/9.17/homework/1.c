/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-17 18:59:50
 * @LastEditTime: 2021-09-18 09:22:55
 * @LastEditors: ZhouGuiqing
 * @Description: 1，利用线程间的信号量实现一个逻辑
 *	从键盘中获取数据，用另外一条线程将数据打印出来
 *		如果没有打印数据出来则不能再次往里面输入字符，如果没有输入字符则不能将数据打印出来
 * @FilePath: /YueQian/code/Daily/9.17/homework/1.c
 */


#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


sem_t sem_read;
sem_t sem_write;
char buf[100];

void *thread_printf(void *arg)
{
    while (1)
    {
        sem_wait(&sem_read);
        printf("打印线程打印中：%s\n", buf);
        sleep(1);
        sem_post(&sem_write);
    }
    
}





int main(int argc, char const *argv[])
{
    
    sem_init(&sem_read, 0, 0);
    sem_init(&sem_write, 0, 1);

    pthread_t tid;
    pthread_create(&tid, NULL, thread_printf, NULL);

    while (1)
    {
        sem_wait(&sem_write);
        printf("请输入:");
        fgets(buf, 100, stdin);
        sem_post(&sem_read);
    }
    

    return 0;
}

