/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-16 16:36:35
 * @LastEditTime: 2021-08-18 14:34:52
 * @LastEditors: ZhouGuiqing
 * @Description: 动态库参数化
 * @FilePath: \code\Experiment\IO\exp7\main.c
 */
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
// #include "jpg.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("参数错误\n");
        return 0;
    }
    void *handle = NULL;
    if (strstr(argv[1], ".bmp")!=NULL &&
            strcmp(argv[1]+strlen(argv[1])-4, strstr(argv[1], ".bmp")) == 0)
    {
        handle = dlopen("./lib/mylib/libshowbmp.so", RTLD_NOW);
    }
    else if (strstr(argv[1], ".jpg") != NULL && 
                strcmp(argv[1]+strlen(argv[1])-4, strstr(argv[1], ".jpg")) == 0)
    {
        handle = dlopen("./lib/mylib/libshowjpg.so", RTLD_NOW);
    }
    
    if (handle == NULL)
    {
        perror("handle获取出错");
        return 0;
    }
    int (*showimg)(const char *);
    showimg = dlsym(handle, "showimg");
    showimg(argv[1]);
    dlclose(handle);
    
    return 0;
}
