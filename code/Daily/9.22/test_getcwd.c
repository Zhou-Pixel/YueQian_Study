/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-22 17:12:26
 * @LastEditTime: 2021-09-22 17:13:47
 * @LastEditors: ZhouGuiqing
 * @Description: 测试getcwd函数
 * @FilePath: /YueQian/code/Daily/9.22/test_getcwd.c
 */
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    printf("%s\n", getcwd(NULL, 0));
    return 0;
}
