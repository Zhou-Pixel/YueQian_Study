/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-17 19:41:29
 * @LastEditTime: 2021-09-18 15:02:58
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.17/homework/2.c
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <strings.h>

int count = 5;
pthread_cond_t cond;
pthread_mutex_t lock;

void *count_v(void *arg)
{
    pthread_mutex_lock(&lock);
    while (1)
    {
        if (count <= 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        
        sleep(1);
        printf("减1\n");
        count--;        
    }
    pthread_mutex_unlock(&lock);
    
}

void sigint_handler(int signum)
{
    pthread_mutex_lock(&lock);

    printf("count+1\n");
    count += 1;

    pthread_mutex_unlock(&lock);

    pthread_cond_signal(&cond);

}

int main(int argc, char const *argv[])
{

    signal(SIGINT, sigint_handler);

    pthread_t tid[3];
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(tid+i, NULL, count_v, NULL);
    }
    
    char buf[100];
    while (1)
    {
        printf("请输入：");
        fgets(buf, 100, stdin);
        strtok(buf, "\n");
        if (strcmp(buf, "exit") == 0)
        {
            break;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        pthread_cancel(tid[i]);
    }

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    
    return 0;
}
