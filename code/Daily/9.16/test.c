/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-16 19:14:20
 * @LastEditTime: 2021-09-16 19:17:55
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.16/test.c
 */
#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    time_t t = time(NULL);
    printf("%s\n", ctime(&t));
    return 0;
}
