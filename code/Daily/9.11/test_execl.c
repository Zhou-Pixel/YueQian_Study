/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-11 16:02:57
 * @LastEditTime: 2021-09-11 16:34:56
 * @LastEditors: ZhouGuiqing
 * @Description: 利用多进程和execl函数调用别的程序
 * @FilePath: /YueQian/code/Daily/9.11/test_execl.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void calling_program(const char *program, char *const *argv)
{
    pid_t pid = vfork();
    if (pid == 0)
    {
        execv(program, argv);
        printf("这一句不会显示\n");
    }

}

int main(int argc, char const *argv[])
{

    char *array[] = {NULL};
    calling_program("hello_world", array);


    printf("父进程要退出了\n");
    return 0;
}
