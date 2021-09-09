/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-02 14:04:27
 * @LastEditTime: 2021-09-03 16:29:35
 * @LastEditors: ZhouGuiqing
 * @Description: 内核链表——学生信息系统
 * @FilePath: /code/Daily/9.2/student_kernel_list.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct
{
    char name[20];
    int age;
    int height;
} student_t;

typedef struct node
{
    student_t stu;
    struct list_head list;
} node_t;

node_t *init_list(void)
{
    node_t *head = calloc(1, sizeof(node_t));
    if (head != NULL)
    {
        INIT_LIST_HEAD(&head->list);
    }

    return head;
}

node_t *find_node(node_t *head, char *name)
{
    node_t *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (strcmp(pos->stu.name, name) == 0)
        {
            return pos;
        }
    }
    return NULL;
}

node_t *create_node(void)
{
    node_t *new = calloc(1, sizeof(node_t));

    if (new != NULL)
    {
        printf("请输入名字\n");
        scanf("%s", new->stu.name);

        printf("请输入年龄\n");
        scanf("%d", &new->stu.age);

        printf("请输入身高\n");
        scanf("%d", &new->stu.height);
    }

    return new;
}

void show_node(node_t *example)
{
    printf("----------------------\n");
    printf("名字：%s", example->stu.name);
    printf("年龄：%d", example->stu.age);
    printf("身高：%d\n", example->stu.height);
    printf("----------------------\n");
}

void show_list(node_t *head)
{
    node_t *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        printf("----------------------\n");
        printf("名字：%s", pos->stu.name);
        printf("年龄：%d", pos->stu.age);
        printf("身高：%d\n", pos->stu.height);
        printf("----------------------\n");
    }
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

void show_ui(void)
{
    printf("----------------------\n");
    printf("输入1录入学生信息\n");
    printf("输入2打印所有学生信息\n");
    printf("输入3查找指定名字的学生\n");
    printf("输入4开除指定名字的学生\n");
    printf("输入5修改指定名字的学生信息\n");
    printf("输入6退出程序\n");
    printf("----------------------\n");
}

void increase_add_node(node_t *new, node_t *head)
{
    node_t *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (pos->stu.height > new->stu.height)
        {
            break;
        }
        
    }
    list_add_tail(&new->list, &pos->list);
    
}

int main(int argc, char const *argv[])
{

    node_t *head = init_list();

    while (1)
    {
        show_ui();

        int input;
        scanf("%d", &input);

        switch (input)
        {
        case 1:
        {
            node_t *new = create_node();
            if (new == NULL)
            {
                printf("插入失败\n");
                continue;
            }
            increase_add_node(new, head);

            break;
        }
        case 2:
        {
            show_list(head);
            break;
        }
        case 3:
        {
            char name[20];
            scanf("%s", name);

            node_t *the_node = find_node(head, name);
            if (the_node == NULL)
            {
                printf("找不到\n");
                continue;
            }
            printf("找到了");
            show_node(the_node);
        }
        case 4:
        {
            char name[20];
            scanf("%s", name);

            node_t *the_node = find_node(head, name);

            if (the_node == NULL)
            {
                printf("找不到指定学生，无法删除\n");
                continue;
            }

            list_del(&the_node->list);
            free(the_node);
            printf("已删除\n");
            break;
        }
        case 5:
        {
            printf("请输入修改的学生：");
            char name[20];
            scanf("%s", name);

            node_t *the_node = find_node(head, name);
            if (the_node == NULL)
            {
                printf("找不到\n");
                continue;
            }

            printf("请输入修改选项：");
            int input_value5;
            scanf("%d", &input_value5);
            while (1)
            {
                switch (input_value5)
                {
                case 1:
                {
                    char name[20];
                    scanf("%s", name);
                    strcpy(the_node->stu.name, name);
                    break;
                }
                case 2:
                {
                    int modify_value;
                    scanf("%d", &modify_value);
                    the_node->stu.age = modify_value;
                    break;
                }
                case 3:
                {
                    int modify_value;
                    scanf("%d", &modify_value);
                    the_node->stu.height = modify_value;
                    break;
                }
                default:
                    break;
                }
            }

            break;
        }

        case 6:
        {
            destroy_list_all(head);
            return 0;
        }

        default:
            continue;
        }
    }
    return 0;
}
