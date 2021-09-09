/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 14:23:06
 * @LastEditTime: 2021-08-31 15:27:14
 * @LastEditors: ZhouGuiqing
 * @Description: 双向循环链表
 * @FilePath: /code/Daily/8.31/list.c
 */
#include <stdio.h>
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
        new->prev = new;
        new->next = new;
    }
    return new;
    
}


void add_node_head(Node *head, Node *new)
{
    new->next = head->next;
    new->prev = head;

    head->next->prev = new;
    head->next = new;
}


void add_node_tail(Node *head, Node *new)
{
    new->next = head;
    new->prev = head->prev;

    head->prev->next = new;
    head->prev = new;
}



Node *find_node_by_data(Node *head, int data)
{
    Node *temp;
    for ( temp = head->next; temp != head; temp = temp->next)
    {
        if (temp->data == data)
        {
            return temp;
        }
        
    }

    return NULL;

}



void showlist(Node *head)
{
    for (Node *temp = head->next; temp != head; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }

    printf("\n");
}


void destroyall(Node *head)
{
    Node *temp, *next;
    for (temp = head->next; temp != head; temp = next)
    {
        next = temp->next;
        free(temp);

    }
    free(head);    
}

void shownoe(Node *node)
{
    printf("%d\n", node->data);
}



void increase_add(Node *head, Node *new)
{
    Node *temp;
    for (temp = head->next; temp != head; temp = temp->next)
    {
        if (temp->data >= new->data)
        {
            break;
        }
        
    }


    new->next = temp;
    new->prev = temp->prev;


    temp->prev->next = new;
    temp->prev = new;
}

void remove_node(Node *rm_node)
{
    rm_node->prev->next = rm_node->next;
    rm_node->next->prev = rm_node->prev;


    rm_node->next = rm_node;
    rm_node->prev = rm_node;
}