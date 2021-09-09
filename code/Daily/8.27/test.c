/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-27 16:51:20
 * @LastEditTime: 2021-08-30 09:15:34
 * @LastEditors: ZhouGuiqing
 * @Description: 测试用例
 * @FilePath: /code/Daily/8.27/test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showlist(int data)
{
    printf("%d\t", data);
}


int main(int argc, char const *argv[])
{
    Node *head = initlist();
    for (int i = 1; i < 11; i++)
    {
        addnode(head, create_node(i));
    }

    forEach(head, showlist);

    while (1)
    {
        int input;
        scanf("%d", &input);
        if (input > 0)
        {
            addnode(head, create_node(input));

        }
        if (input < 0)
        {
            removenode(head, abs(input));
        }

        forEach(head, showlist);
        
        
        
    }
    


    destroyall(head);
    
    
        
    return 0;
}
