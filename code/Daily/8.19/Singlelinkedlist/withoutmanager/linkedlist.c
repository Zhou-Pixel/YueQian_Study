/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-19 16:30:51
 * @LastEditTime: 2021-08-19 16:52:17
 * @LastEditors: ZhouGuiqing
 * @Description: 单链表（不带管理结构体，但是带头结点的）
 * @FilePath: \code\Daily\8.19\Singlelinkedlist\withoutmanager\linkedlist.c
 */
#include "linkedlist.h"
/**
 * @description: 节点创建
 * @param {int} data
 * @return {*}
 */
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
 * @description: 链表的初始化
 * @param {*}
 * @return {*}
 */
Node *initLinkedlist()
{
    Node *head = create_Node(0);
    
    return head;
}

bool addNode(Node *head, int data)
{
    if (head == NULL)
    {
        return false;       
    }
    else
    {
        Node *temp = NULL;
        for(temp = head->next; temp != NULL; temp = temp->next);
        temp->next = create_Node(data);
        return true;
    }
}

bool removeNode(int data)
{
    
}