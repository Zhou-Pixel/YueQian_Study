/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-10 19:09:55
 * @LastEditTime: 2021-09-10 19:12:49
 * @LastEditors: ZhouGuiqing
 * @Description: 测试getchar遇到整数的情况
 * @FilePath: /YueQian/code/Daily/9.10/test_getchar.c
 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%c\n", getchar());
    }
    
    return 0;
}
