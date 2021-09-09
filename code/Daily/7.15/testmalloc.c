/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 19:04:00
 * @LastEditTime: 2021-09-02 19:49:35
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/7.15/testmalloc.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    void *p = malloc(4);
    *((int*)p) = 100;
    printf("%d\n",*((int*)p));
    free(p);
    return 0;
}
