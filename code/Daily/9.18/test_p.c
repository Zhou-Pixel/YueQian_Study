/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-18 16:53:42
 * @LastEditTime: 2021-09-18 16:59:04
 * @LastEditors: ZhouGuiqing
 * @Description: 测试地址
 * @FilePath: /YueQian/code/Daily/9.18/test_p.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{    
    int a;
    printf("%ld\n", (long)&a);

    printf("%ld", sizeof(&a));
    return 0;
}
