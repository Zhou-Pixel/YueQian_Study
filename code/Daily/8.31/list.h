/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 14:23:31
 * @LastEditTime: 2021-08-31 15:27:28
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.31/list.h
 */
#ifndef _LIST_H
#define _LIST_H



typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
       
}Node;


Node *initlist();
Node *create_node(int data);
void add_node_head(Node *head, Node *new);
void add_node_tail(Node *head, Node *new);
Node *find_node_by_data(Node *head, int data);
void showlist(Node *head);
void destroyall(Node *head);
void shownoe(Node *node);
void increase_add(Node *head, Node *new);
void remove_node(Node *rm_node);

#endif