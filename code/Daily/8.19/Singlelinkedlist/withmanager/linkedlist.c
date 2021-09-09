/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-19 15:01:47
 * @LastEditTime: 2021-08-20 18:59:20
 * @LastEditors: ZhouGuiqing
 * @Description: 单链表（带管理结构体的，不带头结点的）
 * @FilePath: \code\Daily\8.19\Singlelinkedlist\withmanager\linkedlist.c
 */
#include "linkedlist.h"


manager *initLinkedlist()
{
    manager *list = calloc(1, sizeof(manager));   
    if (list == NULL)
    {
        return NULL;
    }
    list->head = NULL;
    list->number = 0;
    return list;
}

Node *create_Node(int data)
{
    Node *new = calloc(1, sizeof(Node));
    if (new == NULL)
    {
        return NULL;
    }
    new->data = data;
    new->next = NULL;
    return new;
}
/**
 * @description: 在尾部新增节点
 * @param {manager} *list
 * @param {int} data
 * @return {*}
 */
void addNode(manager *list, int data)
{
    Node *temp = NULL;
    for(temp = list->head; temp != NULL; temp=temp->next);     
    temp->next = create_Node(data);   
    
}

void removeNode()
{
    
}