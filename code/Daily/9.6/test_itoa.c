/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 15:25:14
 * @LastEditTime: 2021-09-06 15:29:48
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/9.6/test_itoa.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    char buf[40];
    sprintf(buf, "%f", 465.4610);
    printf("%s", buf);
    return 0;
}
