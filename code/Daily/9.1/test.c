/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-01 18:49:39
 * @LastEditTime: 2021-09-01 20:24:33
 * @LastEditors: ZhouGuiqing
 * @Description: 内核链表测试
 * @FilePath: /code/Daily/9.1/test.c
 */
#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char const *argv[])
{
    node_t *head = initlist();

    for (int i = 0; i < 10; i++)
    {
        node_t *new = new_node(i);
        if (new == NULL)
        {
            continue;
        }
        
        list_add(&new->list, &head->list);
    }
    
    showlist(head);

    while (1)
    {
        int input;
        scanf("%d", &input);

        if (input > 0)
        {
            node_t *new = new_node(input);
            if (new == NULL)
            {
                continue;
            }
            
            list_add(&new->list, &head->list);
        }
        else if (input < 0)
        {
            if (list_empty(&head->list))
            {
                continue;
            }
            node_t *temp = find_node(head, -input);
            if (temp == NULL)
            {
                continue; 
            }
            list_del(&temp->list);
            free(temp);
        }
        else
        {
            break;
        }
        showlist(head);
        
    }

    destroy_list_all(head);

    return 0;
}
