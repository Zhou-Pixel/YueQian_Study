/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 16:33:32
 * @LastEditTime: 2021-08-31 18:36:44
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.31/homework/queue_homework.h
 */
#ifndef _QUEUE_HOMEWORK_H_
#define _QUEUE_HOMEWORK_H_



typedef struct node 
{
    char buf[100];
    struct node *next;

}Node;



Node *initlist();
Node *create_node(char *);
void add_note(Node *head, Node *new);
Node *remove_node(Node *head);
void show_queue(Node *head);
void destroyall(Node *head);

#endif