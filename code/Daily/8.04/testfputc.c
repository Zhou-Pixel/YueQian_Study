/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-04 20:15:24
 * @LastEditTime: 2021-08-04 20:18:39
 * @LastEditors: ZhouGuiqing
 * @Description:测试fputc函数 
 * @FilePath: \code\Daily\8.4\testfputc.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c = 97;
    fputc(c,stderr);
    return 0;
}
