/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-04 15:08:06
 * @LastEditTime: 2021-09-09 14:46:51
 * @LastEditors: ZhouGuiqing
 * @Description: 内核链表函数封装
 * @FilePath: /code/Experiment/Data_structure/Datalast/src/kernel_list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "custom_kernel_list.h"
#include "input_scanf.h"


commodity_node *find_node_by_name(commodity_node *head, char *name)
{
    commodity_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (strcmp(pos->name, name) == 0)
        {
            return pos;
        }
        
    }
    return NULL;
}


commodity_node *create_node_input(void)
{

    commodity_node *new = init_new_node(commodity_node);
    if (new == NULL)
    {
        printf("创建节点失败\n");
        return NULL;
    }
    printf("请输入名字\n");
    input_fgets_string(new->name, sizeof(new->name));
    printf("请输入价格\n");
    new->price = input_scanf_float();
    printf("请输入库存\n");
    new->in_stock = input_scanf_int();
    return new;

}


void show_node(commodity_node *example)
{
    printf("商品名字:%s\t价格:%.2f元\t库存:%d\n", example->name, example->price, example->in_stock);
}


void show_list(commodity_node *head)
{

    commodity_node *pos;
    int i = 1;
    list_for_each_entry(pos, &head->list, list)
    {
        printf("序号：%d    ", i);
        show_node(pos);
        i++;
    }
}

void init_storehouse(commodity_node *head, const char *filename)
{
    FILE *commodity_list = fopen(filename, "r");
    if (commodity_list == NULL)
    {
        return;
    }

    
    char *buf = malloc(200);

    while (1)
    {

        bzero(buf, 100);
        char * temp = fgets(buf, 200, commodity_list);

        if (temp == NULL)
        {
            break;
        }


        commodity_node *new = init_new_node(commodity_node);

        if (new == NULL)
        {
            return;
        }


        sscanf(strstr(buf, "商品名字:")+strlen("商品名字:"), "%s", new->name);
        sscanf(strstr(buf, "价格:")+strlen("价格:"), "%f", &new->price);
        sscanf(strstr(buf, "库存:")+strlen("库存:"), "%d", &new->in_stock);

        list_add_tail(&new->list, &head->list);        
    }
    free(buf);
    fclose(commodity_list);
}



//-------------------------------------------------------------------------------------


car_node *find_node_by_name_car(car_node *head, char *name)
{
    car_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (strcmp(pos->commodity->name, name) == 0)
        {
            return pos;
        }
        
    }

    return NULL;
}



void show_list_car(car_node *head)
{
    car_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        printf("商品名字:%s, 价格:%f元, 数量:%d\n", pos->commodity->name, pos->commodity->price, pos->quantity);
    }
}
