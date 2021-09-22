/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-18 16:04:19
 * @LastEditTime: 2021-09-18 16:12:07
 * @LastEditors: ZhouGuiqing
 * @Description: 测试线程的取消点
 * @FilePath: /YueQian/code/Daily/9.18/test_pthread_cancel.c
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_test(void *arg)
{
    while (1)
    {
        pthread_testcancel();
    }

    return NULL;
    
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_test, NULL);
    
    pthread_cancel(tid);
    pthread_join(tid, NULL);

    printf("子线程结束\n");
        
    while (1)
    {
        sleep(1);
        printf("主线程\n");
    }
    
    return 0;
}
