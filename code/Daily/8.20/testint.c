/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-20 18:42:38
 * @LastEditTime: 2021-08-20 18:48:34
 * @LastEditors: ZhouGuiqing
 * @Description: 测试类型自动转换
 * @FilePath: \code\Daily\8.20\testint.c
 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 1024, b=600;
    int x = 800,  y=480;
    int input;
    scanf("%d", &input);
    input = input*(1024/800.0);
    printf("%d\n", input);
    
    return 0;
}
