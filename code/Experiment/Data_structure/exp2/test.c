/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 16:38:59
 * @LastEditTime: 2021-08-30 17:08:13
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Experiment/Data_structure/exp2/test.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"


void listtailaddp(Node *head, Node *p)
{
    Node *new = p;
    new->next = head;
    new->prev = head->prev;

    head->prev->next = new;
    head->prev = new;
}

void removenodep(Node *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;

    p->prev = p;
    p->next = p;
    
    
}

void increaseadd(Node *head, Node *new)
{
    Node *temp;
    for ( temp = head->next; temp != head; temp = temp->next)
    {
        if (new->data <= temp->data)
        {
            break;
        }
        
    }


    new->next = temp;
    new->prev = temp->prev;
    
    temp->prev->next = new;
    temp->prev = new;        
       
}



/**
 * @description: 升序排列, 把链表原有的节点全部删除再把所有的节点按升序插入新的链表， 把新的头节点返回
 * @param {Node} *head
 * @return {*}
 */
Node *sortlist(Node *head)
{
    Node *newhead = initlist();

    Node *temp, *next;

    for (temp = head->next; temp != head; temp = next)
    {
        next = temp->next;
        removenodep(temp);
        increaseadd(newhead, temp);
    }
    

    free(head);
    return newhead;

}


/**
 * @description: 重新排序，实现奇偶分别升序排列
 * @param {Node} *head :双向链表的头节点
 * @return {*}  
 */
Node *reorder(Node *head)
{   

    
    head = sortlist(head);
    // printf("%d\n", __LINE__);
    Node *temp;
    Node *next;
    Node *newhead = initlist();
    for (temp = head->next; temp != head; temp = next)
    {
        next = temp->next;
        if (temp->data%2 == 0)
        {
            removenodep(temp);
            listtailaddp(newhead, temp);
        } 
    }


    newhead->prev->next = head;
    head->prev->next = newhead->next;
    free(newhead);


    return head;

    // for (temp = head->next; temp != head; temp = temp->next)
    // {

    // }
       
}

int main(int argc, char const *argv[])
{
    Node *head = initlist();

    
    for (int i = 0; i < 10; i++)
    {
        srand(i);
        listtailadd(head, rand()%100);
    }
    printf("前");
    showlist(head);

    head = reorder(head);

    printf("后");
    showlist(head);

    distroyall(head);

    return 0;
}
