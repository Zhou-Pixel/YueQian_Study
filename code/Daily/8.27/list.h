/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-27 16:51:08
 * @LastEditTime: 2021-08-31 18:36:50
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.27/list.h
 */
#ifndef _LIST_H_
#define _LIST_H_



typedef struct node
{
    int data;
    struct node *next;

}Node;


Node *initlist(void);  





Node *create_node(int data);

void addnode(Node *, Node *);


Node *findnode(Node *head, int data);

Node *removenode(Node *head, int data);


void forEach(Node *head, void (*showlist)(int));

void destroyall(Node *head);


#endif