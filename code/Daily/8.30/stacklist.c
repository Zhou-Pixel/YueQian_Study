/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-30 15:27:35
 * @LastEditTime: 2021-08-31 16:32:43
 * @LastEditors: ZhouGuiqing
 * @Description: 栈-循环链表作业
 * @FilePath: /code/Daily/8.30/stacklist.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

Node *initlist(void)
{
    Node *head = calloc(1, sizeof(Node));
    if (head != NULL)
    {
        head->next = NULL;
    }
    return head;
}


void addnote(Node *head, Node *new)
{
    new->next = head->next;
    head->next = new;
}


Node *removenode(Node *head)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    
    Node *temp = head->next;
    head->next = temp->next;
    temp->next = NULL;

    return temp;
    
}


void destroyall(Node *head)
{
    Node *temp, *next;
    for (temp = head->next; temp != NULL; temp = next)
    {
        next = temp->next;
        free(temp);

    }
    free(head);
}

void showlist(Node *head)
{
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
    
}

Node *createnode(int data)
{
    Node *new = calloc(1, sizeof(Node));
    if (new != NULL)
    {
        new->next = NULL;
        new->data = data;
    }
    return new;   
}