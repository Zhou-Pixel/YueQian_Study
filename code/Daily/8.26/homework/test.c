/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-26 18:26:11
 * @LastEditTime: 2021-08-27 16:50:38
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.26/homework/test.c
 */
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "studentlist.h"

void shownode(Student *stu)
{


    printf("名字：%s\t", stu->name);
    printf("年龄：%hu\t", stu->age);
    printf("身高：%hu\t", stu->height);
    printf("\n");
    
}



int main(int argc, char const *argv[])
{


    slist *newlist = initlist();
    while (1)
    {
        printf("输入1录入学生信息\n");
        printf("输入2打印所有学生信息\n");
        printf("输入3查找指定名字的学生\n");
        printf("输入4开除指定名字的学生\n");
        printf("输入5退出程序\n");
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            Student stu;
            // bzero(&stu, sizeof(Student));
            create_node(&stu);
            add_node(newlist, &stu);
            break;
        }

        case 2:
        {
            forEach(newlist, shownode);            
            break;
        }


        case 3:
        {
            printf("请输入名字\n");
            char name[20];
            scanf("%s", name);
            int i = find_by_name(newlist, name);
            if (i == -1)
            {
                printf("找不到\n");
                continue;
            }
            printf("找到了：");
            shownode(&newlist->theclass[i]);            
            break;
        }



        case 4:
        {
            printf("请输入名字\n");
            char name[20];
            scanf("%s", name);
            remove_by_name(newlist, name);

            break;
        }

        case 5:
        free(newlist);
            return 0;
        
        default:
            break;
        }
    }
    
    
    return 0;

}
