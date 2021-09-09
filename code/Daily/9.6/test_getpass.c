/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 19:28:26
 * @LastEditTime: 2021-09-06 19:32:06
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/9.6/test_getpass.c
 */
#define __USE_MISC
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *p = getpass();
    printf("%s\n", p);
    return 0;
}
