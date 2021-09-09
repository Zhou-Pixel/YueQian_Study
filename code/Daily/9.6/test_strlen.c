/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 15:20:37
 * @LastEditTime: 2021-09-09 17:29:47
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.6/test_strlen.c
 */
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%ld, %ld\n", strlen("中文"), sizeof("中文"));
    return 0;
}


