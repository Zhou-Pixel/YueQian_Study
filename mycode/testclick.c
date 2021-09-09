/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-21 09:07:31
 * @LastEditTime: 2021-08-21 11:10:19
 * @LastEditors: ZhouGuiqing
 * @Description: 测试点击库
 * @FilePath: \YueQian\mycode\testclick.c
 */
#include <stdio.h>
#include "click.h"

int main(int argc, char const *argv[])
{
    int x, y;
    while(1) 
    {
        returnclick(&x, &y);
        printf("点击：%d\n", __LINE__);
        printf("(%d, %d)\n", x, y);
    }
    
    return 0;
}
