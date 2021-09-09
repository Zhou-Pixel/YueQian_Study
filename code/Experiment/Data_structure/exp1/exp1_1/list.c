/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-23 18:33:28
 * @LastEditTime: 2021-08-23 19:53:50
 * @LastEditors: ZhouGuiqing
 * @Description: 单向链表
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "list.h"
// typedef struct node
// {
//     int  data;
//     struct node *next;
// }Node;

Node *initlist()
{
    Node *head = calloc(1, sizeof(Node));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    return head;
}



Node *create_node(int data)
{
    Node *new = calloc(1, sizeof(Node));
    if (new == NULL)
    {
        return NULL;

    }
    new->data = data;
    new->next = NULL;
    return new;

}

void listtailadd(Node *head, int data)
{
    Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next);
    temp->next = create_node(data);
    
}


void listheadadd(Node *head, int data)
{

    Node *new = create_node(data);
    new->next = head->next;
    head->next = new;

}


Node *removenode(Node *head, int data)
{
    if (head->next == NULL)
    {
        return NULL;
    }

    Node *temp, *k;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        if (temp->next->data == data)
        {
            break;
        }
        
    }
    if (temp->next == NULL)
    {
        return NULL;
    }
    
    k = temp->next;
    temp->next = temp->next->next;
    k->next = NULL;
    return k;    
       
    
}


void showlist(Node *head)
{
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
    
}