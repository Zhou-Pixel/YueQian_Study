/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-16 14:56:33
 * @LastEditTime: 2021-08-16 15:02:18
 * @LastEditors: ZhouGuiqing
 * @Description: 库文件的使用
 * @FilePath: \YueQian\code\Experiment\IO\exp6\main.c
 */
#include <stdio.h>
#include "exp6_1.h"

int main(int argc, char const *argv[])
{
    copyregfile(argv[1], argv[2]);
    return 0;
}
