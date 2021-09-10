/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-03 19:26:13
 * @LastEditTime: 2021-09-10 14:53:09
 * @LastEditors: ZhouGuiqing
 * @Description: 再次封装scanf函数，使其稳定获取键盘输入，
 * @FilePath: /YueQian/code/Experiment/Data_structure/Datalast/src/input_scanf.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input_scanf.h"


int input_scanf_int(void)
{
    int input_value;


    while (!(scanf("%d", &input_value) == 1 && getchar() == '\n'))
    {
        printf("格式不对，请重新输入：");
        while (getchar() != '\n');
    }

    return input_value;
    
}
/**
 * @description: 封装fgets函数获取键盘输入的字符串，去掉\n
 * @param {char} *buf
 * @param {int} size
 * @return {*}
 */
void input_fgets_string(char *buf, int size)
{
    fgets(buf, size, stdin);
    strtok(buf, "\n");
}

/** 
 * @description: 用fgets函数获取字符 
 * @param {*}
 * @return {*}
 */
char input_fgets_char(void)
{
    char buf[100];
    while (1)
    {
        bzero(buf, sizeof(buf));
        fgets(buf, 100, stdin);
        if (strlen(buf) <= 2)
        {
            break;
        }
        printf("格式不对，请重新输入\n");
    }
    return buf[0];  
}

float input_scanf_float(void)
{
    float input_value;

    while (!(scanf("%f", &input_value) == 1 && getchar() == '\n'))
    {
        printf("格式不对，请重新输入：");
        while (getchar() != '\n');
    }

    return input_value;
    
}


