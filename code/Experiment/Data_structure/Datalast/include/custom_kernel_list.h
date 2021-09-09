/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-04 14:51:30
 * @LastEditTime: 2021-09-09 09:09:09
 * @LastEditors: ZhouGuiqing
 * @Description: 封装内核链表函数
 * @FilePath: /code/Experiment/Data_structure/Datalast/include/custom_kernel_list.h
 */

#ifndef _CUSTOM_KERNEL_LIST_H
#define _CUSTOM_KERNEL_LIST_H


#ifndef _LIST_H
#define _LIST_H

#include "list.h"

#endif

typedef struct commodity_list_node
{
    char name[40];
    float price;
    unsigned in_stock;
    struct list_head list;

}commodity_node;


typedef struct  shopping_car_node
{
    commodity_node *commodity;
    unsigned int quantity;
    struct list_head list;
}car_node;


commodity_node *find_node_by_name(commodity_node *head, char *name);

void show_node(commodity_node *example);

void show_list(commodity_node *head);
void init_storehouse(commodity_node *head, const char *filename);

commodity_node *create_node_input(void);


car_node *find_node_by_name_car(car_node *head, char *name);

void show_list_car(car_node *);


#define destroy_list(head)\
({\
    typeof(head) pos, n;\
    list_for_each_entry_safe(pos, n, &head->list, list)\
    {\
        free(pos);\
    }\
    INIT_LIST_HEAD(&head->list);\
})


#define destroy_list_all(head)\
({\
    typeof(head) pos, n;\
    list_for_each_entry_safe(pos, n, &head->list, list)\
    {\
        free(pos);\
    }\
    free(head);\
})


#define remove_node(rm_note)\
({\
    list_del(&rm_note->list);\
})


#define init_new_node(type)\
({\
    type *head = calloc(1, sizeof(type));\
    if (head != NULL)\
    {\
        INIT_LIST_HEAD(&head->list);\
    }\
    head;\
})



#define add_node(head, new)\
({\
    list_add(&new->list, &head->list);\
})
#endif
