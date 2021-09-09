/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 16:38:49
 * @LastEditTime: 2021-08-24 20:17:54
 * @LastEditors: ZhouGuiqing
 * @Description: 双向循环链表
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp2\list.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"



Node *initlist()
{
    Node *head = calloc(1, sizeof(Node));
    if (head != NULL)
    {
        head->next = head;
        head->prev = head;
    }
    return head;
    
}


Node *create_node(int data)
{
    Node *new = calloc(1, sizeof(Node));
    if (new != NULL)
    {
        new->data = data;
        new->next = new;
        new->prev = new;
    }
    return new;

}

void listheadadd(Node *head, int data)
{
    Node *new = create_node(data);

    new->prev = head;
    new->next = head->next;

    head->next->prev = new;
    head->next = new;

}




void listtailadd(Node *head, int data)
{
    Node *new = create_node(data);
    new->next = head;
    new->prev = head->prev;

    head->prev->next = new;
    head->prev = new;
}



Node *removenode(Node *head, int data)
{
    Node *temp;
    for (temp = head->next; data != temp->data; temp = temp->next)
    {
        if (temp == head)
        {
            break;
        }
        
    }
    if (temp == head)
    {
        return NULL;
    }
    

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->prev = temp;
    temp->next = temp;
    return temp;
    
}

void showlist(Node *head)
{
    for (Node *temp = head->next; temp != head; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
}

void distroyall(Node *head)
{
    Node *temp1, *temp2;
    for (temp1 = head->next; temp1 != head; temp1 = temp2)
    {
        temp2 = temp1->next;
        free(temp1);
    }
    free(head);
    
}