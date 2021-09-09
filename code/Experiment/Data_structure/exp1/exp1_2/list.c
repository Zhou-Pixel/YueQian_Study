/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 14:16:58
 * @LastEditTime: 2021-08-24 16:35:13
 * @LastEditors: ZhouGuiqing
 * @Description: 循环链表
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\exp1_2\list.c
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
        return head;
    }
    return NULL;
    
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


void listheadadd(Node *head, int data)
{
    Node *new = create_node(data);
    if (new == NULL)
    {
        return;
    }
    new->next = head->next;
    head->next = new;
        
}
void listtailadd(Node *head, int data)
{
    Node *new = create_node(data);
    if (new == NULL)
    {
        return;

    }
    Node *temp;
    for (temp = head; temp->next != head; temp = temp->next)
    {
           
    }
    new->next = temp->next;
    temp->next = new; 
}



Node *removenode(Node *head, int data)
{
    if (head->next == head || head == NULL)
    {
        return NULL;
    }



    Node *temp;
    for (temp = head; ; temp = temp->next)
    {
        if (temp->next->data == data || temp->next == head)
        {
            break;
        }
        
    }
    if (temp->next == head && temp->next->data != data)
    {
        return NULL;
    }
    
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    
    return temp2;

    
}
Node *removepnode(Node *head, Node *rm)
{

    if (head == rm)
    {
        return NULL;
    }
    
    Node *temp;
    for (temp = rm; temp->next != rm; temp = temp->next);
    temp->next = rm->next;
    rm->next = NULL;


    return temp;


    
    
}

void showlist(Node *head)
{
    for (Node *temp = head->next; temp != head; temp = temp->next)
    {
        printf("%d    ", temp->data);
    }
    printf("\n");
    
}