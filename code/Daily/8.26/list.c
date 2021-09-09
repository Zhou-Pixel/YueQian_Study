/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 14:57:30
 * @LastEditTime: 2021-08-27 09:48:37
 * @LastEditors: ZhouGuiqing
 * @Description: 从今天开始在粤嵌总部学习
 * @FilePath: /code/Daily/8.26/list.c
 */
 
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <stdio.h>
#include <string.h>
#include "list.h"

datalist *initlist()
{
    datalist *list = calloc(1, sizeof(datalist));
    if (list != NULL)
    {
        list->last = -1;
    }
    
    return list;
}


void forEachnode(datalist *list, void (*p)(int))
{
    for (int i = 0; i <= list->last; i++)
    {
        p(list->data[i]);
    }
    printf("\n");
    
}

bool isFull(datalist *list)
{
    return   list->last == SIZE - 1;   
}


bool isEmty(datalist *list)
{
    return list->last == -1;
}

bool addnode(datalist *list, int data)
{
    if (isFull(list))
    {
        return false;
    }
    else 
    {
        list->data[++list->last] = data;
        return true;
    }
        
}


bool increaseadd(datalist *list, int data)
{
    if (isFull(list))
    {
        return false;
    }
    else
    {
        int i;
        for (i = 0; i <=list->last; i++)
        {
            if (list->data[i] >= data)
            {
                for (int j = list->last; j >= i; j--)
                {
                       list->data[j + 1] = list->data[j];

                }
                break;       
            }
        }

        list->data[i] = data;
        list->last++;

        return true;
        
    }
    // printf("in function:last:%d\n", list->last);
}

/**
 * @description: remove all nodes that are equal to  data
 * @param {datalist} *list
 * @param {int} data
 * @return {*}
 */
bool removenode(datalist *list, int data)
{
    int i;
    for (i = 0; i <= list->last; i++)
    {
        if (list->data[i] == data)
        {
            for (int j = i; j < list->last; j++)
            {
                list->data[j] = list->data[j+1];
            }
            list->last--;
            i--;
            
        }
        
    }

    if (i != list->last + 1)
    {
        return true;
    }
    return false;
    
    
} 


void distroy(datalist *list)
{
    free(list);
}

