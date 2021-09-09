/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 14:23:36
 * @LastEditTime: 2021-08-31 15:34:05
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.31/test.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"



int main(int argc, char const *argv[])
{
    Node *head = initlist();
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        increase_add(head, create_node(rand()%100));
    }

    showlist(head);
    while (1)
    {
        printf("输入1插入节点\n");
        printf("输入2打印节点\n");
        printf("输入3查找指定节点\n");
        printf("输入4删除指定节点\n");
        printf("输入5退出程序\n");
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            int data;
            scanf("%d", &data);
            increase_add(head, create_node(data));
            break;
        }

        case 2:
        {
            showlist(head);            
            break;
        }


        case 3:
        {
            int data;
            scanf("%d", &data);
            Node *temp = find_node_by_data(head, data);
            if (temp == NULL)
            {
                printf("找不到\n");
                continue;
            }
            printf("找到了\n");
            
            break;
        }



        case 4:
        {
            int data;
            scanf("%d", &data);
            Node *temp = find_node_by_data(head, data);
            if (temp == NULL)
            {
                printf("找不到\n");
                continue;
            }
            printf("找到了\n");
            remove_node(temp);
            free(temp);
            break;
        }

        case 5:
            destroyall(head);
            return 0;
            
        default:
            continue;
        }
    
    }

    
    return 0;
}
