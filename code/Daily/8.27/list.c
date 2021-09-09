/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-27 16:51:15
 * @LastEditTime: 2021-08-30 15:08:00
 * @LastEditors: ZhouGuiqing
 * @Description: 单链表
 * @FilePath: /code/Daily/8.27/list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"



Node *initlist(void)
{
    Node *new = calloc(1, sizeof(Node));
    if (new != NULL)
    {
        new->next = NULL;
    }

    return new;
    
}


Node *create_node(int data)
{
    Node *new = calloc(1, sizeof(Node));
    if (new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

void addnode(Node *head, Node *new)
{
    Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next);
    temp->next = new;

    
}


Node *findnode(Node *head, int data)
{
    Node *temp;
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        if (temp->data == data)
        {
            return temp;
        }
        
    }

    return NULL;

       
}

Node *removenode(Node *head, int data)
{
    Node *rm_node = findnode(head, data);
    if (rm_node == NULL)
    {
        return NULL;
    }
    
    Node *temp;
    for ( temp = head; temp->next != rm_node && temp->next != NULL; temp = temp->next);
    if (temp->next == NULL)
    {
        return NULL;
    }
    temp->next = temp->next->next;
    rm_node->next = NULL;
    
    return rm_node;    
}


void forEach(Node *head, void (*showlist)(int))
{
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        showlist(temp->data);
    }
    printf("\n");
}

void destroyall(Node *head)
{
    Node *next = head;
    for (Node *temp = head->next; temp != NULL && next != NULL; temp = next)
    {
        next = temp->next;
        free(temp);
    }
    free(head);
    
}
