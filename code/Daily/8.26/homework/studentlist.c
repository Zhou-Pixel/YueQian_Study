/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 18:25:52
 * @LastEditTime: 2021-08-27 16:40:09
 * @LastEditors: ZhouGuiqing
 * @Description: 学生信息链表
 * @FilePath: /code/Daily/8.26/homework/studentlist.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "studentlist.h"


slist *initlist()
{
    slist *newlist = calloc(1, sizeof(slist));   
    if (newlist != NULL)
    {
        newlist->last = -1;
    }


    return newlist;
    
}


void create_node(Student *stu)
{
    printf("请输入名字\n");
    scanf("%s", stu->name);

    printf("请输入年龄\n");
    scanf("%hu", &(stu->age));
    
    printf("请输入身高（cm）\n");
    scanf("%hu", &(stu->height));  
}

bool isFull(slist *thelist)
{
    return thelist->last == SIZE-1;
}

bool isEmpty(slist *thelist)
{
    return thelist->last == -1;
}

void add_node(slist *thelist, Student *student)
{
    if (isFull(thelist))
    {
        return;
    }
    thelist->theclass[++thelist->last] = *student;
        
}





void forEach(slist *thelist, void(*shownode)(Student *))
{
    for (int i = 0; i <= thelist->last; i++)
    {
        shownode(&thelist->theclass[i]);
    }
    
}


void remove_by_name(slist *thelist, char *name)
{   
    int i; 
    for (i = 0; i <= thelist->last; i++)
    {
        if (strcmp(thelist->theclass[i].name, name) == 0)
        {
            break;
        }
        
    }
    if (i == thelist->last + 1 )
    {
        return;
    }
    memcpy(thelist->theclass + i +1, thelist->theclass + i, thelist->last - i);
    

    
}


int find_by_name(slist *thelist, char *name)
{
    int i; 
    for (i = 0; i <= thelist->last; i++)
    {
        if (strcmp(thelist->theclass[i].name, name) == 0)
        {
            break;
        }
        
    }
    if (i == thelist->last + 1 )
    {
        return -1;
    }
    return i;
}