/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 15:41:58
 * @LastEditTime: 2021-09-06 15:43:31
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/9.6/test_fputs.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("commodity.txt", "w+");

    char *temp = malloc(200);
    for(int i = 0; i<5; i++)
    {
        bzero(temp, 200);
        sprintf(temp, "商品名字:%s  价格:%f    库存:%d\n", "测试", 1.5, 10);

        fputs(temp, fp);

    }
    return 0;
}
