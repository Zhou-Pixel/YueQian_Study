/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 15:00:39
 * @LastEditTime: 2021-08-26 19:37:10
 * @LastEditors: ZhouGuiqing
 * @Description:  顺序表 
 * @FilePath: /code/Daily/8.26/list.h
 */
#ifndef _LIST_H
#define _LIST_H

#define SIZE 10

typedef struct datalist 
{
    int data[SIZE];
    int last;
}datalist;


datalist *initlist();

void forEachnode(datalist *list, void (*p)(int));

bool isFull(datalist *list);


bool isEmty(datalist *list);

bool addnode(datalist *list, int data);


bool removenode(datalist *list, int data);
bool increaseadd(datalist *list, int data);


#endif