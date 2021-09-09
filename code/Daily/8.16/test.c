/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-16 09:02:25
 * @LastEditTime: 2021-08-16 09:41:03
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \code\Daily\8.16\test.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *statingp1[] = {"mm_lcd", "mm_lcd+240*800*4", "mm_lcd+240*800*4+200*4", "mm_lcd+240*800*4+400*4","mm_lcd+240*800*4+600*4","mm_lcd+600*4", "mm_lcd+400*4", "mm_lcd+200*4"};
    for (int i = 7; i >= 0; i--)
    {
        printf("%s, ", statingp1[i]);
    }
    printf("\n");
    return 0;
}
