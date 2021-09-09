/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-19 10:50:41
 * @LastEditTime: 2021-08-19 11:22:26
 * @LastEditors: ZhouGuiqing
 * @Description: 顺序表
 * @FilePath: \code\Daily\8.19\seqlist.c
 */
#include <stdio.h>
#include "seqlist.h"
#include <stdbool.h>



seqlist *initseqlist(int cap)
{
    seqlist *s1 = calloc(1, sizeof(seqlist));
    if (s1 == NULL)
    {
        printf("结构体seqlist内存申请失败\n");
        return NULL;
    }

    s1->data = calloc(cap, sizeof(int));
    if (s1->data == NULL)
    {
        printf("顺序表内存申请失败\n");
        free(s1);
        return NULL;
    }

    s1->cap = cap;
    s1->last = -1;

    return s1;   
    
}



bool insertNode(seqlist *s1, int data)
{
    if (s1->last == -1)
    {
        s1->data[0] = data;
        s1->last = 0;
    }
    else if (s1->last == (s1->cap-1))
    {
        return false;
    }
    else
    {
        s1->data[++s1->last] = data;
    }
    
    return true;
}