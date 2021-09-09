/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 14:50:08
 * @LastEditTime: 2021-08-24 16:35:05
 * @LastEditors: ZhouGuiqing
 * @Description: 测试循环链表
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\exp1_2\test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void kill3(Node *head)
{
    int i = 1;
    for (Node *temp = head; ; temp = temp->next)
    {

        if (head->next->next->next == head)
        {
            break;
        }
        if (temp == head)
        {
            continue;
        }
        if (i%3 == 0)
        {
            temp = removepnode(head, temp);
            showlist(head);
        }
        i++;
        
    }
    
}

int main(int argc, char const *argv[])
{
    Node *head = initlist();


    for (int i = 0; i < 10; i++)
    {
        listtailadd(head, i);

    }
    showlist(head);
    // while (1)
    // {
    //    int a;
    //    scanf("%d", &a);
    //    if (a == 100)
    //    {
    //        break;

    //    }
    //    Node *temp  = removenode(head, a);
    //    if (temp != NULL)
    //    {
    //        free(temp);
    //    }
       
    //    showlist(head);
        
    // }
    kill3(head);
    
    showlist(head);
    
    return 0;
}
