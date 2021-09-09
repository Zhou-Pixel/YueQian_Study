/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-30 10:54:28
 * @LastEditTime: 2021-08-30 14:19:56
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.27/studentlist/list.h
 */
#ifndef _LIST_H
#define _LIST_H


typedef struct
{
    char name[20];
    int age;
    int height;
}Student;


typedef struct node
{
    Student data;
    struct node *next;

}Node;


Node *initlist(void);  





Node *create_node(void);

void addnode(Node *, Node *);


Node *findnode(Node *head, char *name);

Node *removenode(Node *head, Student *data);


void forEach(Node *head, void (*showlist)(Student *));

void destroyall(Node *head);

void showlist(Student *data);
void showui(void);

#endif