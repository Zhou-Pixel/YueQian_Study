/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-30 10:54:28
 * @LastEditTime: 2021-08-30 14:31:56
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.27/studentlist/list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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


Node *create_node(void)
{
    Node *new = calloc(1, sizeof(Node));

    if (new == NULL)
    {
        return NULL;
    }
    
    
    printf("请输入名字\n");
    scanf("%s", new->data.name);

    printf("请输入年龄\n");
    scanf("%d", &(new->data.age));
    
    printf("请输入身高（cm）\n");
    scanf("%d", &(new->data.height));  


    return new;
}

void addnode(Node *head, Node *new)
{
    Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next);
    temp->next = new;

    
}


Node *findnode(Node *head, char *name)
{
    Node *temp;
    
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        if (!strcmp(temp->data.name, name))
        {
            return temp;
        }
        
    }

    return NULL;

       
}

Node *removenode(Node *head, Student *data)
{
    Node *rm_node = findnode(head, data->name);
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


void forEach(Node *head, void (*showlist)(Student *))
{
    for (Node *temp = head->next; temp != NULL; temp = temp->next)
    {
        showlist(&temp->data);

    }

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


void showlist(Student *data)
{
    printf("%s\t", data->name);
    printf("%d\t", data->age);
    printf("%d\n", data->height);
}


void showui(void)
{
        printf("输入1录入学生信息\n");
        printf("输入2打印所有学生信息\n");
        printf("输入3查找指定名字的学生\n");
        printf("输入4开除指定名字的学生\n");
        printf("输入5退出程序\n");
}