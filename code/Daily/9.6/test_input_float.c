/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-06 09:38:16
 * @LastEditTime: 2021-09-06 19:25:01
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/9.6/test_input_float.c
 */
#include <stdio.h>
#include <string.h>


float input_scanf_float(void)
{
    float input_value;


    while (!(scanf("%f", &input_value) == 1 && getchar() == '\n'))
    {
        printf("请重新输入：");
        while (getchar() != '\n');
    }

    return input_value;
    
}

void input_fgets_string(char *buf, int size)
{
    fgets(buf, size, stdin);
    strtok(buf, "\n");
}

char input_fgets_char()
{
    char buf[100];
    while (1)
    {
        bzero(buf, sizeof(buf));
        fgets(buf, 100, stdin);
        if (strlen(buf) == 2)
        {
            break;
        }

        printf("请重新输入\n");
        
    }
    
    return buf[0];
    
}

int main(int argc, char const *argv[])
{
    // printf("%f\n", input_scanf_float());

    // char buf[100];
    // input_fgets_string(buf, 100);

    // printf("%s\n", buf);

    printf("%c\n", input_fgets_char());

    return 0;
}
