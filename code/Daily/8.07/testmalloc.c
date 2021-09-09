/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-07 15:56:17
 * @LastEditTime: 2021-08-07 15:59:06
 * @LastEditors: ZhouGuiqing
 * @Description: 内存泄漏
 * @FilePath: \code\Daily\8.7\testmalloc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    while(1)
    {
        char *buf = malloc(100);
        sleep(1);
    }
    return 0;
}

