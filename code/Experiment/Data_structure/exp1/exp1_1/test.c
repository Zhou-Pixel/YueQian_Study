/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-23 19:12:15
 * @LastEditTime: 2021-08-23 20:33:50
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\test.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Node *head = initlist();

    for (int i = 0; i < 10; i++)
    {
        listtailadd(head, i);
    }

    showlist(head);
    // int a;
    // while (1)
    // {
    //     scanf("%d", &a);
    //     if (a == 100)
    //     {
    //         break;
    //     }
    //     Node *temp = removenode(head, a);
    //     if (temp != NULL)
    //     {
    //         free(temp);
    //     }
        
    
    //     showlist(head);
        
    // }
    Node *newhead = head->next;
    head->next =NULL;
    // Node *k;
    for (Node *temp = newhead; temp != NULL; temp = newhead)
    {
        // newhead = temp->next;
        // head->next = temp->next;
        // temp->next->next = temp;
        // temp->next = NULL;
        newhead = temp->next;
        temp->next = head->next;
        head->next = temp;


    }

    showlist(head); 
    
    


    return 0;
}
