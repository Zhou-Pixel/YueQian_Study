/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-09 15:42:35
 * @LastEditTime: 2021-08-09 16:06:19
 * @LastEditors: ZhouGuiqing
 * @Description: 测试动态库参数化
 * @FilePath: \code\Daily\8.9\Dynamic_library\main.c
 */
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    FILE *fp = fopen("config", "r");
    char *config = calloc(1, 100);
    fgets(config, 100, fp);
    fclose(fp);


    // printf("%s\n", config);
    void *check = dlopen(strtok(config, "\n"), RTLD_LAZY);
    if(check == NULL)
    {
        perror("dlopen出错");
        return 0;
    }


    void (*dect)(void);
    dect = dlsym(check, "dect");
    if(dect == NULL)
    {
        perror("dect出错");
        return 0;
    }

    dect();
    dlclose(check);
    return 0;
}
