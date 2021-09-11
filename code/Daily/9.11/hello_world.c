/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 16:04:05
 * @LastEditTime: 2021-09-11 16:37:42
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /YueQian/code/Daily/9.11/hello_world.c
 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
    // if (argc != 2)
    // {
    //     printf("参数错误\n");
    //     return 0;
    // }
    if (argv[1][0] == '1')
    {
        printf("hello world\n");
    }
    if (argv[1][0] == '2')
    {
        printf("hello java");
    }
    printf("%p\n", argv[0]);
    printf("1 %s\n", argv[1]);
    printf("2 %s\n", argv[2]);
    printf("3 %s\n", argv[3]);
    printf("4 %s\n", argv[4]);
    printf("5 %s\n", argv[5]);
    printf("6 %s\n", argv[6]);
    printf("7 %s\n", argv[7]);
    printf("8 %s\n", argv[8]);
    printf("9 %s\n", argv[9]);
    printf("10 %s\n", argv[10]);
    printf("11 %s\n", argv[11]);
    printf("hello    %d\n", argc);
    
    return 0;
}
