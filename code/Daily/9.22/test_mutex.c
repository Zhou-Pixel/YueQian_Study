/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-22 14:53:14
 * @LastEditTime: 2021-09-22 16:44:49
 * @LastEditors: ZhouGuiqing
 * @Description: 测试锁和条件变量
 * @FilePath: /YueQian/code/Daily/9.22/test_mutex.c
 */
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

int count = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void unlock_mutex(void *arg)
{
    pthread_mutex_unlock((pthread_mutex_t *)arg);
}


void *thread_func(void *arg)
{
    pthread_cleanup_push(unlock_mutex, NULL)

    while (1)
    {
        pthread_mutex_lock(&mutex);
        sleep(1);
        while (count <= 0)//需要使用while，不能使用if，会导致锁没有意义
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("第%s条线程, count=%d\n", (char *)arg, --count);
        pthread_mutex_unlock(&mutex);
    }

    pthread_cleanup_pop(0);
}


void handler(int signum)
{
    pthread_mutex_lock(&mutex);

    count+=3;

    pthread_mutex_unlock(&mutex);

    pthread_cond_broadcast(&cond);
}

int main(int argc, char const *argv[])
{

    signal(SIGINT, handler);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t tid[3];


    pthread_create(tid, NULL, thread_func, "0");
    pthread_create(tid+1, NULL, thread_func, "1");
    pthread_create(tid+2, NULL, thread_func, "2");


    for (int i = 0; i < 3; i++)
    {
        pthread_join(tid[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}
