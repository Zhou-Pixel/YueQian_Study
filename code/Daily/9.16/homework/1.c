/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-16 18:59:51
 * @LastEditTime: 2021-09-16 19:13:13
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.16/homework/1.c
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *wait_ten_sec(void *none)
{
    sleep(10);
    return "线程";
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, wait_ten_sec, NULL);
    
    
    void *get_string;
    pthread_join(tid, &get_string);
    printf("线程的返回值：%s\n", (char *)get_string);    

    return 0;
}
