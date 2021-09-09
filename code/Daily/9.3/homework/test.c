/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-01 18:49:39
 * @LastEditTime: 2021-09-04 20:50:14
 * @LastEditors: ZhouGuiqing
 * @Description: 内核链表测试
 * @FilePath: /code/Daily/9.3/homework/test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

typedef struct node
{
    int data;
    struct list_head list;
} node_t;

node_t *new_node(int data)
{
    node_t *new = calloc(1, sizeof(node_t));
    if (new != NULL)
    {
        INIT_LIST_HEAD(&new->list);
        new->data = data;
    }
    return new;
}


node_t *find_node(node_t *head, int data)
{
    struct list_head *pos;
    list_for_each(pos, &head->list)
    {
        node_t *temp = list_entry(pos, node_t, list);
        if(temp->data == data)
        {   
            return temp;
        }
    }


    return NULL;
}


void showlist(node_t *head)
{
    struct list_head *pos;
    list_for_each(pos, &head->list)
    {
        printf("%d\t", list_entry(pos, node_t, list)->data);
    }
    printf("\n");
}

node_t *initlist(void)
{
    node_t *new = calloc(1, sizeof(node_t));
    if (new != NULL)
    {
        INIT_LIST_HEAD(&new->list);
    }
    return new;
}

void destroy_list_all(node_t *head)
{
    node_t *pos, *n;
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        free(pos);
    }

    free(head);

}


void sort_list(node_t *head)
{
    struct list_head *start_node = head->list.next;
    struct list_head *end_node = head->list.prev;
    struct list_head *end_node2 = end_node;
    struct list_head *pos1, *pos2;

    for (pos1 = start_node; pos1 != end_node->prev; pos1 = pos1->next)
    {
        for (pos2 = start_node; pos2 != end_node2; pos2 = pos2->next)
        {
            node_t *current_node = list_entry(pos2, node_t, list);
            node_t *current_node_n  = list_entry(pos2->next, node_t, list);

            if (current_node->data > current_node_n->data)
            {
                int temp = current_node->data;
                current_node->data = current_node_n->data;
                current_node_n->data = temp;
            }
             
        }
        end_node2 = end_node2->prev;
        
    }
    

}

int main(int argc, char const *argv[])
{
    node_t *head = initlist();

    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        node_t *new = new_node(rand()%100);
        if (new == NULL)
        {
            continue;
        }
        
        list_add(&new->list, &head->list);
    }
    
    showlist(head);

    sort_list(head);

    showlist(head);

    destroy_list_all(head);

    return 0;
}
