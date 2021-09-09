/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-19 15:01:23
 * @LastEditTime: 2021-08-19 15:09:19
 * @LastEditors: ZhouGuiqing
 * @Description: 单链表头文件
 * @FilePath: \code\Daily\8.19\Singlelinkedlist\linkedlist.h
 */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct
{
    int number;
    Node *head;    
    
}manager;


#endif