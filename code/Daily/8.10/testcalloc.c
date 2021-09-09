/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-10 09:02:50
 * @LastEditTime: 2021-08-10 15:05:31
 * @LastEditors: ZhouGuiqing
 * @Description: 测试同一块堆内存的传参
 * @FilePath: \code\Daily\8.10\testcalloc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

char *func1(char *buf, char *str)
{
    bzero(buf, 100);
    strcpy(buf, str);    
    return buf;
}


void func2(char *str1, char *str2)
{
    printf("%s\n", str1);
    printf("%s\n", str2);
}

int main(int argc, char const *argv[])
{
    char *buf = calloc(1, 100); 

    func2(func1(buf, "123"), func1(buf, "abc"));

    free(buf);

    return 0;
}
