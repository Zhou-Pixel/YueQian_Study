/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-27 16:51:20
 * @LastEditTime: 2021-08-30 14:20:32
 * @LastEditors: ZhouGuiqing
 * @Description: 测试用例
 * @FilePath: /code/Daily/8.27/studentlist/test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"




int main(int argc, char const *argv[])
{
    Node *head = initlist();

    while (1)
    {
        showui();
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            Node *temp = create_node();
            addnode(head, temp);
            break;
        }

        case 2:
        {
            forEach(head, showlist);            
            break;
        }


        case 3:
        {
            printf("请输入名字\n");
            char name[20];
            scanf("%s", name);
            Node *temp = findnode(head, name);
            if (temp == NULL)
            {
                printf("找不到\n");
                continue;
            }
            printf("找到了：");
            showlist(&temp->data);
            break;
        }



        case 4:
        {
            printf("请输入名字\n");
            char name[20];
            scanf("%s", name);
            Node *temp = findnode(head, name);
            if (temp == NULL)
            {
                continue;
            }
            
            removenode(head, &temp->data);
            break;
        }

        case 5:
            destroyall(head);
            return 0;
            
        default:
            continue;
        }
    }


    destroyall(head);
    
    
        
    return 0;
}
