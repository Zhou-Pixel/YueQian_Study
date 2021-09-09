/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 18:26:02
 * @LastEditTime: 2021-08-27 16:30:30
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.26/homework/studentlist.h
 */
#ifndef _STUDENT_H
#define _STUDENT_H

#include <stdbool.h>


#define SIZE 40

typedef struct
{
    char name[20];
    unsigned short age;
    unsigned short height;
}Student;

typedef struct studentlist
{
    Student theclass[SIZE];
    int last;

}slist;


slist *initlist();

bool isFull(slist *thelist);

bool isEmpty(slist *thelist);

void add_node(slist *thelist, Student *student);
void create_node(Student *stu);


void forEach(slist *thelist, void(*shownode)(Student *));   



void remove_by_name(slist *thelist, char *name);

int find_by_name(slist *thelist, char *name);

#endif
