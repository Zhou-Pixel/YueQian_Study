/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 15:28:33
 * @LastEditTime: 2021-08-27 09:10:52
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.26/test.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"



void p(int data)
{
    printf("%d\t", data);
}

int main(int argc, char const *argv[])
{

    datalist *list = initlist();
    for (int i = 0; i < 10; i++)
    {
        int s;
        scanf("%d", &s);
        // printf("s的值是%d\n", s);
        // printf("last:%d\n", list->last);
        increaseadd(list, s);
        forEachnode(list, p);
    }

    forEachnode(list, p);


    // while (1)//可以再封装一个函数
    // {
    //     int input;
    //     scanf("%d", &input);
    //     if (input > 0)
    //     {
    //         addnode(list, input);

    //     }
    //     if (input < 0)
    //     {
    //         removenode(list, abs(input));
    //     }
    //     forEachnode(list, p);
        
    // }
        
    
    return 0;
}
