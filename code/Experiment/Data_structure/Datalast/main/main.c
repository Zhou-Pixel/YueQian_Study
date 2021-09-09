/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-03 19:57:00
 * @LastEditTime: 2021-09-09 14:59:25
 * @LastEditors: ZhouGuiqing
 * @Description: 项目主函数
 * @FilePath: /code/Experiment/Data_structure/Datalast/main/main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "input_scanf.h"
#include "custom_kernel_list.h"

/**
 * @description: 格式化写入购买历史文本
 * @param {car_node} *head 购物车链表头结点
 * @return {*}
 */
void write_shopping_history(car_node *head)
{
    FILE *fp = fopen("./text/shopping_history.txt", "a+");
    car_node *pos;
    float subtotal, total = 0;
    list_for_each_entry(pos, &head->list, list)
    {
        subtotal = pos->commodity->price * pos->quantity;
        total += subtotal;
        fprintf(fp, "商品名字:%s    数量:%d     小计:%f\n", pos->commodity->name, pos->quantity, subtotal);
    }
    if (total != 0)
    {
        fprintf(fp, "总计:%f\n", total);
    }
    
    fclose(fp);
}

/**
 * @description: 格式化输出购买历史
 * @param {*}
 * @return {*}
 */
void show_shopping_history(void)
{
    FILE *fp = fopen("./text/shopping_history.txt", "r");
    if (fp == NULL)
    {
        return;
    }

    char *buf = malloc(200);
    bool start = false;
    while (1)
    {
        bzero(buf, 100);
        char *temp = fgets(buf, 200, fp);
        if (temp == NULL)
        {
            break;
        }

        char name[40];
        int quantity;
        float subtotas;
        float total;

        if (strstr(buf, "商品名字:") != NULL)
        {
            sscanf(strstr(buf, "商品名字:") + strlen("商品名字:"), "%s", name);
            sscanf(strstr(buf, "数量:") + strlen("数量:"), "%d", &quantity);
            sscanf(strstr(buf, "小计:") + strlen("小计:"), "%f", &subtotas);
            if (start == false)
            {
                printf("{\n");
                start = true;
            }
            printf("    商品名字:%s     数量:%d     小计:%.2f\n", name, quantity, subtotas);
        }
        if (strstr(buf, "总计:") != NULL)
        {
            sscanf(strstr(buf, "总计:") + strlen("总计:"), "%f", &total);
            printf("    总计:%.2f\n", total);
            printf("}\n");
            start = false;
        }
    }
    free(buf);
    fclose(fp);
}

/**
 * @description: 按价格冒泡排序购物车的商品
 * @param {car_node} *head
 * @return {*}
 */
void sort_list_car(car_node *head)
{
    struct list_head *start_node = head->list.next;
    struct list_head *end_node1 = head->list.prev;
    struct list_head *end_node2 = head->list.prev;
    struct list_head *pos1, *pos2;
    for (pos1 = start_node; pos1 != end_node1; pos1 = pos1->next)
    {
        for (pos2 = start_node; pos2 != end_node2; pos2 = pos2->next)
        {
            car_node *current_node = list_entry(pos2, car_node, list);
            car_node *current_node_n = list_entry(pos2->next, car_node, list);
            if (current_node->commodity->price > current_node_n->commodity->price)
            {
                car_node *temp = init_new_node(car_node);
                memcpy(temp, current_node, offsetof(car_node, list));
                memcpy(current_node, current_node_n, offsetof(car_node, list));
                memcpy(current_node_n, temp, offsetof(car_node, list));
                free(temp);
            }
        }
        end_node2 = end_node2->prev;
    }
}

/**
 * @description: 老板修改商品函数
 * @param {commodity_node} *mod_node 需要修改的商品节点
 * @return {*}
 */
void boss_modify_node(commodity_node *mod_node)
{
    printf("当前商品:");
    show_node(mod_node);
    commodity_node *backup_node = init_new_node(commodity_node);
    if (backup_node == NULL)
    {
        return;
    }
    // memcpy(backup_node, mod_node, sizeof(commodity_node));
    *backup_node = *mod_node;
    bool modified = false;
    while (1)
    {
        printf("===============================\n");
        printf("===========1：修改商品名字=======\n");
        printf("===========2：修改价格==========\n");
        printf("===========3：修改库存==========\n");
        printf("===========4：删除当前商品======\n");
        printf("===========0：返回=============\n");
        printf("===============================\n");
        switch (input_scanf_int())
        {
        case 1:
        {
            char new_name[40];
            input_fgets_string(new_name, 40);
            strcpy(mod_node->name, new_name);
            modified = true;
            break;
        }
        case 2:
        {
            float new_price = input_scanf_float();
            mod_node->price = new_price;
            modified = true;
            break;
        }
        case 3:
        {
            mod_node->in_stock = input_scanf_int();
            modified = true;
            break;
        }
        case 4:
        {

            remove_node(mod_node);
            free(backup_node);
            free(mod_node);
            return;
        }
        case 0:
        {
            if (modified == true)
            {
                printf("是否保存:(y/n)");
                char input_ch = input_fgets_char();
                if (input_ch != 'y' && input_ch != '\n')
                {
                    // memcpy(mod_node, backup_node, sizeof(commodity_node));
                    *mod_node = *backup_node;
                }
            }
            free(backup_node);
            return;
        }
        }
    }
}

/**
 * @description:  老板新增商品函数
 * @param {commodity_node} *head
 * @return {*}
 */
void boss_add_node(commodity_node *head)
{
    commodity_node *new = create_node_input();
    if (new == NULL)
    {
        return;
    }
    commodity_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (strcmp(new->name, pos->name) == 0)
        {
            pos->in_stock += new->in_stock;
            pos->price = new->price;
            printf("新增商品已存在, 已更新商品信息\n");
            printf("是否去修改该商品信息:(y/n)");
            char input_ch = input_fgets_char();
            if (input_ch == 'y' || input_ch == '\n')
            {
                boss_modify_node(pos);
            }
            free(new);
            return;
        }
    }

    add_node(head, new);
}

/**
 * @description: 老板初始化函数
 * @param {commodity_node} *head 商品信息链表头结点
 * @return {*}
 */
void boss_func(commodity_node *head, car_node *head_car)
{
    printf("成功进入管理员账户\n");
    while (1)
    {
        printf("===============================\n");
        printf("===========1：录入商品===========\n");
        printf("===========2：搜索商品并且更改====\n");
        printf("===========3：打印所有商品=======\n");
        printf("===========4：查看购物历史=======\n");
        printf("===========0：返回==============\n");
        printf("===============================\n");
        switch (input_scanf_int())
        {
        case 1:
        {
            boss_add_node(head);
            break;
        }
        case 2:
        {
            char name[40];
            printf("请输入查找的商品\n");
            input_fgets_string(name, 40);
            commodity_node *find_node = find_node_by_name(head, name);
            if (find_node == NULL)
            {
                printf("找不到\n");
                break;
            }
            printf("已查找到商品:");
            show_node(find_node);
            printf("是否修改:(y/n)\n");
            char input_ch = input_fgets_char();
            if (input_ch == 'y' || input_ch == '\n')
            {
                boss_modify_node(find_node);
            }
            break;
        }
        case 3:
            show_list(head);
            break;
        case 4:
            show_shopping_history();
            break;
        case 0:
            return;
        case -1:
            exit(0);
        }
    }
}

/**
 * @description: 顾客购买商品函数
 * @param {commodity_node} *head 商品信息链表头结点
 * @param {car_node} *head_car 购物车链表头结点
 * @return {*}
 */
void consumer_buy_func(commodity_node *head, car_node *head_car)
{
    printf("请输入商品名字\n");
    char name[40];
    input_fgets_string(name, 40);
    commodity_node *find_node = find_node_by_name(head, name);
    if (find_node == NULL)
    {
        printf("没有该商品\n");
        return;
    }
    if (find_node->in_stock <= 0)
    {
        printf("库存不够，无法购买，通知老板！\n");
        return;
    }

    int quantity_buy;
    printf("请输入购买的数量：\n");
    while (1)
    {
        quantity_buy = input_scanf_int();
        if (quantity_buy > 0 && quantity_buy <= find_node->in_stock)
        {
            break;
        }
        printf("数量不对\n");
    }

    printf("是否确认购买(y/n)\n");
    char input_ch = input_fgets_char();
    if (input_ch != 'y' && input_ch != '\n')
    {
        return;
    }

    car_node *find_node_car = find_node_by_name_car(head_car, name);
    if (find_node_car != NULL)
    {
        find_node_car->quantity += quantity_buy;
        find_node_car->commodity->in_stock -= quantity_buy;
        return;
    }
    car_node *new = init_new_node(car_node);
    new->commodity = find_node;
    add_node(head_car, new);
    find_node->in_stock -= quantity_buy;
    new->quantity += quantity_buy;
}

/**
 * @description: 顾客修改购物车商品函数
 * @param {car_node} *mod_node
 * @return {*}
 */
void consumer_modify_node(car_node *mod_node)
{
    printf("当前的购物车的商品是:商品名字:%s, 价格:%f元, 数量:%d\n",
           mod_node->commodity->name, mod_node->commodity->price, mod_node->quantity);
    while (1)
    {
        printf("===============================\n");
        printf("============1：修改数量==========\n");
        printf("============2：移出购物车========\n");
        printf("============3：返回=============\n");
        printf("===============================\n");
        switch (input_scanf_int())
        {
        case 1:
        {
            printf("请输入修改后的数量：\n");
            int quantity = input_scanf_int();
            while (quantity < 0)
            {
                printf("请重新输入数量\n");
                quantity = input_scanf_int();
            }
            if (quantity == 0)
            {
                remove_node(mod_node);
                free(mod_node);
                return;
            }
            mod_node->quantity = quantity;
            break;
        }
        case 2:
            remove_node(mod_node);
            free(mod_node);
        case 3:
            return;
        case -1:
            exit(0);
        default:
            break;
        }
    }
}

/**
 * @description: 顾客结账函数
 * @param {car_node} *head
 * @return {*}
 */
void consumer_bill(car_node *head)
{
    float total = 0;
    car_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        total += pos->commodity->price * pos->quantity;
    }
    printf("总共%f元\n", total);
    destroy_list(head);
}

/**
 * @description: 防止管理员删除商品导致购物车链表越界访问
 * @param {commodity_node} *head
 * @param {car_node} *head_car
 * @return {*}
 */
void check_shopping_list(commodity_node *head, car_node *head_car)
{
    car_node *pos1, *n1;
    commodity_node *pos2;

    list_for_each_entry_safe(pos1, n1, &head_car->list, list)
    {
        bool is_exist = false;
        list_for_each_entry(pos2, &head->list, list)
        {
            if (pos1->commodity == pos2)
            {
                is_exist = true;
                break;
            }
        }
        if (is_exist == false)
        {
            remove_node(pos1);
            free(pos1);
        }
    }
}

/**
 * @description: 顾客函数
 * @param {commodity_node} *head
 * @param {car_node} *head_car
 * @return {*}
 */
void consumer_func(commodity_node *head, car_node *head_car)
{
    check_shopping_list(head, head_car);
    while (1)
    {
        printf("========================================\n");
        printf("==========1：加入购物车===================\n");
        printf("==========2：修改购物车商品信息============\n");
        printf("==========3：结账========================\n");
        printf("==========4：查看购物车中的所有的商品=======\n");
        printf("==========5：查看购物我的购物历史==========\n");
        printf("==========6：查看所有待售商品=============\n");
        printf("==========7：按价格排序并打印所有购物车商品=\n");
        printf("==========8：清空购物车==================\n");
        printf("==========0：返回=======================\n");
        printf("=======================================\n");

        switch (input_scanf_int())
        {
        case 1:
        {
            consumer_buy_func(head, head_car);
            break;
        }
        case 2:
        {
            char name[40];
            printf("你要修改的商品的名字？\n");
            input_fgets_string(name, 40);
            car_node *find_node = find_node_by_name_car(head_car, name);
            if (find_node == NULL)
            {
                printf("购物车中没有你指定的商品\n");
                break;
            }
            consumer_modify_node(find_node);
            break;
        }
        case 3:
        {
            write_shopping_history(head_car);
            consumer_bill(head_car);
            break;
        }
        case 4:
        {
            show_list_car(head_car);
            break;
        }
        case 5:
        {
            show_shopping_history();
            break;
        }
        case 6:
        {
            show_list(head);
            break;
        }
        case 7:
        {
            sort_list_car(head_car);
            show_list_car(head_car);
            break;
        }
        case 8:
        {
            destroy_list(head_car);
            break;
        }
        case 0:
            return;
        }
    }
}

/**
 * @description: 退出程序把商品信息重新写入文件
 * @param {commodity_node} *head
 * @return {*}
 */
void rewrite_commodity_txt(commodity_node *head)
{
    FILE *fp = fopen("./text/commodity.txt", "w+");
    if (fp == NULL)
    {
        perror("打开出错");
        return;
    }

    commodity_node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        fprintf(fp, "商品名字:%s  价格:%f 库存:%d\n", pos->name, pos->price, pos->in_stock);
    }
    fclose(fp);
}

// bool multi_user(char *name, char *password)
// {
//     FILE *fp = fopen("./text/user.txt", "r");
//     if (fp == NULL)
//     {
//         return true;
//     }
//     char *namebuf = calloc(1, 100);
//     sprintf(namebuf, "username=%s", name);
//     char *buf = malloc(100);
//     while (1)
//     {
//         bzero(buf, 100);
//         if (fgets(buf, 100, fp) == NULL)
//             break;
//         if (strstr(buf, namebuf) != NULL)
//         {
//             if (strstr(buf, "password") == NULL)
//             {
//                 fclose(fp);
//                 free(buf);
//                 free(namebuf);
//                 return true;
//             }
//             if (strcmp(strstr(buf, "password=") + strlen("password="), name) == 0)
//             {
//                 fclose(fp);
//                 free(buf);
//                 free(namebuf);
//                 return true;
//             }
//             break;
//         }
//     }
//     fclose(fp);
//     free(buf);
//     free(namebuf);
//     return false;
// }

int main(int argc, char const *argv[])
{
    commodity_node *commodity_list = init_new_node(commodity_node);
    car_node *shopping_list = init_new_node(car_node);
    init_storehouse(commodity_list, "./text/commodity.txt");
    show_list(commodity_list);
    

    while (1)
    {
        // char input_name[40] = {0};
        // char password[20] = {0};
        // input_fgets_string(input_name, 40);
        // if (strcmp(input_name, "root") == 0)
        // {
        //     if (multi_user(input_name, password))
        //     {
        //         input_fgets_string(password, 20);
        //         boss_func(commodity_list, shopping_list);
        //         continue;
        //     }  
        // }
        // else
        // {
        //     input_fgets_string(password, 20);
        //     if (multi_user(input_name, password) == false)
        //     {
        //         printf("重新登陆\n");
        //         continue;
        //     }
        //     else
        //     {     
        //     }    
        // }
        
        char input_arrary[20] = {0};
        char passwd[20] = {0};
        int input_value;

        printf("按回车继续\n");
        input_fgets_string(input_arrary, 20);
        if (strlen(input_arrary) == 1 && input_arrary[0] == '\n')
        {
            consumer_func(commodity_list, shopping_list);
        }
        else if (strcmp(input_arrary, "admin") == 0)
        {
            input_fgets_string(passwd, 20);
            if (strcmp(passwd, "123456") == 0)
            {
                boss_func(commodity_list, shopping_list);
            }
        }
        else if (strcmp(input_arrary, "exit") == 0)
        {
            rewrite_commodity_txt(commodity_list);
            destroy_list_all(commodity_list);
            destroy_list_all(shopping_list);
            printf("退出系统\n");
            return 0;
        }
        else
        {
            printf("请重新输入\n");
        }
    }
}
