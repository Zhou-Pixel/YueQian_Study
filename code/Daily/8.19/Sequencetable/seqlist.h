/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-19 10:51:30
 * @LastEditTime: 2021-08-19 11:02:56
 * @LastEditors: ZhouGuiqing
 * @Description: 顺序表头文件
 * @FilePath: \code\Daily\8.19\seqlist.h
 */
#ifndef _SEQLIST_H
#define _SEQLIST_H

typedef struct
{
    int cap;
    int last;
    int *data;
}seqlist;
bool insertNode(int);

#endif