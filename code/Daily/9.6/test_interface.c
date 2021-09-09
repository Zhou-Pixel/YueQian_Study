/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 18:41:18
 * @LastEditTime: 2021-09-06 18:52:55
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/9.6/test_interface.c
 */
#include <stdio.h>
#include <string.h>

void input_fgets_string(char *buf, int size)
{
    fgets(buf, size, stdin);
    strtok(buf, "\n");
}

int main_interface()
{
    while (1)
    {
        printf("1：加入购物车\n");
        printf("2：修改购物车商品信息\n");
        printf("3：结账\n");
        printf("4：查看购物车中的所有的商品\n");
        printf("5：查看购物我的购物历史\n");
        printf("6：返回\n");
        char input_arrary[20]={0};
        char passwd[20] = {0};
        input_fgets_string(input_arrary, 20);  
        if (strlen(input_arrary) == 2)
        {
            return input_arrary[0];
        }
        if (strcmp(input_arrary, "admin") == 0)
        {
            input_fgets_string(passwd, 20);
            if (strcmp(passwd, "123456789") == 0)
            {
                printf("登录管理员\n");
            }
            
        }
        
        
    }
    
}

int main(int argc, char const *argv[])
{

    return 0;
}
