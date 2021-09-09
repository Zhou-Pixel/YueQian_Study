/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-30 15:27:58
 * @LastEditTime: 2021-08-30 15:58:42
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.30/stacklist.h
 */
#ifndef _STACKLIST_H

#define _STACKLIST_H


typedef struct node 
{
    int data;
    struct node *next;

}Node;


Node *initlist(void);




void addnote(Node *head, Node *new);

Node *removenode(Node *head);


void destroyall(Node *head);

void showlist(Node *head);

Node *createnode(int data);


#endif