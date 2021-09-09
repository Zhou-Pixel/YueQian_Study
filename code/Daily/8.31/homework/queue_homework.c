/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 16:32:20
 * @LastEditTime: 2021-08-31 17:09:12
 * @LastEditors: ZhouGuiqing
 * @Description: 队列作业
 * @FilePath: /code/Daily/8.31/homework/queue_homework.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_homework.h"



Node *initlist()
{
    Node *head = calloc(1, sizeof(Node));
    if (head != NULL)
    {
        head->next = NULL;
    }
    return head;   
}


Node *create_node(char *buf)
{
    Node *new = calloc(1, sizeof(Node));
    if (new != NULL)
    {
        new->next = NULL;
        strcpy(new->buf, buf);
    }
    return new;
}




void add_note(Node *head, Node *new)
{
    Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next);

    temp->next = new;
}


Node *remove_node(Node *head)
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


void show_queue(Node *head)
{
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%s\n", temp->buf);
    }
}


void destroyall(Node *head)
{
    Node *temp, *next;
    for ( temp = head->next; temp != NULL; temp = next)
    {
        next = temp->next;
        free(temp);
    }
    free(head);
}