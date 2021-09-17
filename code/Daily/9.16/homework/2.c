/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-16 18:59:51
 * @LastEditTime: 2021-09-16 19:54:07
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.16/homework/2.c
 */
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *wait_ten_sec(void *none)
{
    pthread_attr_t attr;
    int de_status;
    pthread_getattr_np(pthread_self(), &attr);
    pthread_attr_getdetachstate(&attr, &de_status);//从attr中获取分离的属性放进de_status中

    if (de_status == PTHREAD_CREATE_DETACHED)
    {
        printf("分离\n");
    }
    if (de_status == PTHREAD_CREATE_JOINABLE)
    {
        printf("可接和\n");
    }
    
    
    sleep(10);
    return "线程";
}

int main(int argc, char const *argv[])
{

    pthread_attr_t attr;
    pthread_attr_init(&attr);//初始化attr的值
    
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);//把完全分离的属性放进attr中

    pthread_t tid;
    pthread_create(&tid, &attr, wait_ten_sec, NULL);//按照attr中的属性设置线程
    
    pthread_attr_destroy(&attr);//摧毁attr（可能申请了某一些内存）
    
    void *get_string;
    pthread_join(tid, &get_string);//等待指定线程
    printf("线程的返回值：%s\n", (char *)get_string);    

    sleep(1);

    return 0;
}
