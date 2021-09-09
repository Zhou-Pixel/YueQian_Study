/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-23 19:12:26
 * @LastEditTime: 2021-08-23 19:29:47
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\list.h
 */
#ifndef _LIST_H
#define _LIST_H

typedef struct node
{
    int  data;
    struct node *next;
}Node;

Node *initlist();



Node *create_node(int data);

void listtailadd(Node *head, int data);
    


void listheadadd(Node *head, int data);

Node *removenode(Node *head, int data);

void showlist(Node *head);

#endif